#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct line {
	ll m, y0;
	line(ll y0=0, ll m=0): y0(y0), m(m) {}
};

struct ConvexHullTrick {

	int pos=0;

	bool check(line a, line b, line c) {
		return (a.y0 - b.y0) * (c.m - a.m) < (a.y0 - c.y0) * (b.m - a.m);
	}

	vector<line> H;

	void update(line l) {
		if(H.size() >= 1 && l.m == H.back().m) {
			if(l.y0 >= H.back().y0) return;
			H.pop_back();
		}
		while(H.size() >= 2 && !check(H[H.size()-2], H[H.size()-1], l)) H.pop_back();
		H.push_back(l);
	}

	ll eval(int id, int x) {
		return H[id].y0 + H[id].m*x;
	}

	ll query(int x) {
		while(pos + 1 < H.size() && eval(pos,x) > eval(pos + 1,x)) pos++;
		return eval(pos, x);
	}
};

const int N=1e5+7;
ConvexHullTrick c[5*N];
pii a[N];
ll ac[N], ans[N];
int x[N], y[N];

void update(int n, int b, int e, int pos, line l) {
	c[n].update(l);
	if(b == e) return;
	int m = (b+e)/2;
	if(pos <= m) update(2*n, b, m, pos, l);
	else update(2*n+1, m+1, e, pos, l);
}

ll query(int n, int b, int e, int i, int j, int x) {
	if(b > j || e < i) return 1e16;
	if(b >= i && e <= j) return c[n].query(x);
	int m = (b+e)/2;
	return min(query(2*n, b, m, i, j, x), query(2*n+1, m+1, e, i, j, x));
}

int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i].first);
		a[i].second=i;
		ac[i] = ac[i-1] + a[i].first;
	}
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	for(int i=1;i<=n;i++) {
		update(1, 1, n, a[i].second, line(1ll * a[i].first * a[i].second - ac[a[i].second], a[i].first));
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++) {
		scanf("%d%d", &x[i], &y[i]);
		a[i].first = x[i]-y[i];
		a[i].second=i;
	}
	sort(a+1, a+q+1);
	for(int i=1;i<=q;i++) {
		int j = a[i].second;
		ans[j] = ac[y[j]] + query(1, 1, n, y[j]-x[j]+1, y[j], x[j]-y[j]);
	}
	for(int i=1;i<=q;i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
