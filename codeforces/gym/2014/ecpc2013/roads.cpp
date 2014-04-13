#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

struct edge {
	int a, b, w;
	bool operator <(const edge &e)const { return w < e.w; }
};

const int N=1e5+10;
edge e[N];
int ans[N], cc[N];
vector<int> v[N];
vector<pii> upd[N];

void process(int c) {
	int sum=0;
	int j=upd[c].size()-1;
	for(int i=v[c].size()-1;i>=0;i--) {
		while(j>=0 && upd[c][j].first >= i) {
			sum += upd[c][j].second;
			j--;
		}
		ans[v[c][i]] += sum;
	}
	v[c].clear();
	upd[c].clear();
}

int main() {
	freopen("road.in", "r", stdin);
	int T, n, m;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n>>m;
		for(int i=1;i<=n;i++) {
			ans[i]=0;
			cc[i]=i;
			v[i].push_back(i);
		}
		for(int i=0;i<m;i++) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
		sort(e, e+m);
		for(int i=0;i<m;i++) {
			int ca = cc[e[i].a], cb = cc[e[i].b];
			int na = v[ca].size(), nb = v[cb].size();
			if(ca == cb) continue;
			upd[ca].push_back(pii(na-1, e[i].w*nb));
			upd[cb].push_back(pii(nb-1, e[i].w*na));
			if(na < nb) {
				swap(ca, cb);
				swap(na, nb);
			}
			for(int i=0;i<nb;i++) {
				cc[v[cb][i]] = ca;
				v[ca].push_back(v[cb][i]);
			}
			process(cb);
		}
		for(int i=1;i<=n;i++) process(i);
		printf("Case %d:\n", t);
		for(int i=1;i<=n;i++) printf("%d\n", ans[i]);
	}
	return 0;
}
