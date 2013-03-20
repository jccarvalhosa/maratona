#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> pii;

vector<pii> v[100000], h[100000];
int fv[100000], fh[100000], ov[100000], oh[100000];
map<int, int> idv, idh;

int count(vector<pii> &p) {
	int i, last=0, ans=0;
	for(i=0;i<p.size();i++) if(p[i].second > last) {
		ans += p[i].second - max(last, p[i].first);
		last = p[i].second;
	}
	return ans;
}

int search(vector<pii> &p, int key) {
	int i, last=0, val=0;
	for(i=0;i<p.size();i++) {
		if(p[i].first > last) {
			val += p[i].first - last;
			if(val >= key) return p[i].first - (val-key);
		}
		last = max(last, p[i].second);
	}
	return last + (key-val);
}

int main() {
	int n, m, k, i, x, y, X, Y, H=0, V=0, ans=0;
	cin >> n >> m >> k;
	for(i=0;i<k;i++) {
		cin >> x >> y >> X >> Y;
		if(x == X) {
			if(!idv.count(x)) {
				ov[V] = x;
				idv[x] = V++;
			}
			if(y > Y) swap(y, Y);
			v[idv[x]].push_back(pii(y, Y));
		}
		if(y == Y) {
			if(!idh.count(y)) {
				oh[H] = y;
				idh[y] = H++;
			}
			if(x > X) swap(x, X);
			h[idh[y]].push_back(pii(x, X));
		}
	}
	for(i=0;i<V;i++) sort(v[i].begin(), v[i].end());
	for(i=0;i<H;i++) sort(h[i].begin(), h[i].end());
	if((m-1-H) % 2) ans ^= n;
	if((n-1-V) % 2) ans ^= m;
	for(i=0;i<V;i++) {
		fv[i] = m-count(v[i]);
		ans ^= fv[i];
	}
	for(i=0;i<H;i++) {
		fh[i] = n-count(h[i]);
		ans ^= fh[i];
	}
	if(ans == 0) cout << "SECOND" << endl;
	else {
		cout << "FIRST" << endl;
		if((ans^m) < m) {
			for(i=1;i<n;i++) if(!idv.count(i)) break;
			if(i != n) {
				printf("%d %d %d %d\n", i, 0, i, m-(ans^m));
				return 0;
			}
		}
		if((ans^n) < n) {
			for(i=1;i<m;i++) if(!idh.count(i)) break;
			if(i != m) {
				printf("%d %d %d %d\n", 0, i, n-(ans^n), i);
				return 0;
			}
		}
		for(i=0;i<V;i++) if((ans^fv[i]) < fv[i]) break;
		if(i != V) {
			printf("%d %d %d %d\n", ov[i], 0, ov[i], search(v[i], fv[i]-(ans^fv[i])));
			return 0;
		}
		for(i=0;i<H;i++) if((ans^fh[i]) < fh[i]) break;
		if(i != H) {
			printf("%d %d %d %d\n", 0, oh[i], search(h[i], fh[i]-(ans^fh[i])), oh[i]);
			return 0;
		}
	}
	return 0;
}
