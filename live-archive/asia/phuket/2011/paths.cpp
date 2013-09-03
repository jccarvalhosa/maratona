#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, ans, up[22222], down[22222];
vector<pii> adj[22222];

void dfs(int v, int p) {
	up[v] = down[v] = 0;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		if(u==p) continue;
		dfs(u, v);
		int d = adj[v][i].second;
		if(d > 0) {
			up[v] += max(1, up[u]);
			ans += down[u];
		}
		else {
			down[v] += max(1, down[u]);
			ans += up[u];
		}
	}
	int x = min(up[v], down[v]);
	up[v] -= x;
	down[v] -= x;
	ans += x;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		for(int i=0;i<n;i++) adj[i].clear();
		for(int i=0;i<n-1;i++) {
			int a, b;
			cin>>a>>b;
			adj[a].push_back(pii(b, 1));
			adj[b].push_back(pii(a, -1));
		}
		ans=0;
		dfs(0, -1);
		ans += up[0] + down[0];
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
