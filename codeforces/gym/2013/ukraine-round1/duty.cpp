#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cc, deg[111111], vis[111111], t[111111];
vector<int> adj[111111];

void dfs(int v) {
	vis[v] = 1;
	t[cc] += deg[v]%2;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(!vis[u]) dfs(u);
	}
}

int main() {
	int a, b, n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++; deg[b]++;
	}
	cc=0;
	for(int i=1;i<=n;i++) if(!vis[i] && deg[i] != 0) dfs(i), cc++;
	if(cc==1) cout<<t[0]/2<<endl;
	else {
		int ans=0;
		for(int i=0;i<cc;i++) ans += max(0, t[i]/2-1);
		cout<<cc+ans<<endl;
	}
	return 0;
}
