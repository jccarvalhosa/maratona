#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;

const int N=1111;
int n, a[N], vis[N];
vector<pii> adj[N];
vector<int> ans;

void dfs(int v) {
	vis[v]=1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		int ne = adj[v][i].second;
		if(!vis[u]) {
			dfs(u);
			if(a[u]) {
				ans.push_back(ne);
				a[u]^=1;
				a[v]^=1;
			}
		}
	}
}

int solve() {
	for(int i=0;i<n;i++) vis[i]=0;
	for(int i=0;i<n;i++) if(!vis[i]) {
		dfs(i);
		if(a[i]) return 0;
	}
	return 1;
}

int main() {
	int t, m;
	cin>>t;
	while(t--) {
		ans.clear();
		cin>>n>>m;
		for(int i=0;i<n;i++) adj[i].clear();
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a-1].push_back(pii(b-1, i));
			adj[b-1].push_back(pii(a-1, i));
		}
		if(solve()) {
			printf("TAK %d\n", ans.size());
			for(int i=0;i<ans.size();i++) printf("%d\n", ans[i]);
		}
		else printf("NIE\n");
	}
	return 0;
}
