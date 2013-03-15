#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, vis[1000], men[1000], nbridges;
vector<int> adj[1000];

int dfs(int v, int p, int h) {
	int u, i;
	vis[v] = men[v] = h;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i];
		if(u != p) {
			if(vis[u]) men[v] = min(men[v], vis[u]);
			else men[v] = min(men[v], dfs(u, v, h+1));
		}
	}
	if(p >= 0 && men[v] >= vis[v]) nbridges++;
	return men[v];
}

int main() {
	int i, a, b;
	while(scanf("%d%d", &n, &m) && n) {
		for(i=0;i<n;i++) adj[i].clear();
		for(i=0;i<m;i++) {
			scanf("%d%d", &a, &b);
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		for(i=0;i<n;i++) vis[i]=0;
		nbridges=0;
		dfs(0, -1, 1);
		printf("%c\n", nbridges == 0 ? 'S' : 'N');
	}
	return 0;
}
