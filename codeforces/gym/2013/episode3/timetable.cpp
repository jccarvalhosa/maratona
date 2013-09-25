#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1<<30
	
int n;
vector<int> ti[111111], tf[111111], adj[111111];
int table[111111], lim[111111], valid[111111];

int dfs(int v, int t) {
	if(v==n) return t;
	int ans = INF;
	while(lim[v] != -1 && ti[v][lim[v]] >= t) {
		ans = min(ans, dfs(adj[v][lim[v]], tf[v][lim[v]]));
		lim[v]--;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int m;
		scanf("%d", &m);
		for(int j=0;j<m;j++) {
			int ha, ma, hb, mb, d;
			scanf("%d:%d %d:%d %d", &ha, &ma, &hb, &mb, &d);
			ti[i].push_back(60*ha+ma);
			tf[i].push_back(60*hb+mb);
			adj[i].push_back(d);
		}
	}
	for(int i=1;i<=n;i++) lim[i] = -1 + adj[i].size();
	vector<int> vt;
	for(int i=0;i<ti[1].size();i++) vt.push_back(ti[1][i]);
	vt.resize(unique(vt.begin(), vt.end()) - vt.begin());
	int ans=0, m = vt.size();
	for(int i=m-1;i>=0;i--) {
		table[i] = dfs(1, vt[i]);
		if(table[i] != INF) {
			int j;
			for(j=i+1;j<m;j++) if(table[j] <= table[i]) break;
			if(j == m) {
				ans++;
				valid[i]=1;
			}
		}
	}
	printf("%d\n", ans);
	for(int i=0;i<m;i++) if(valid[i]) printf("%2.2d:%2.2d %2.2d:%2.2d\n", vt[i]/60, vt[i]%60, table[i]/60, table[i]%60);
	return 0;
}
