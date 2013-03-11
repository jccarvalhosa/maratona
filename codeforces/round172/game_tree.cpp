#include <cstdio>
#include <vector>
using namespace std;
#define MAX 100000

int vis[MAX];
vector<int> adj[MAX];
double ans;

int dfs(int v, int h) {
	vis[v]=1;
	ans += 1.0/h;
	int i, u;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i];
		if(!vis[u]) dfs(u, h+1);
	}
}

int main() {
	int i, a, b, n;
	scanf("%d", &n);
	for(i=0;i<n-1;i++) {
		scanf("%d%d", &a, &b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	for(i=0;i<n;i++) vis[i]=0;
	ans=0;
	dfs(0, 1);
	printf("%lf\n", ans);
	return 0;
}
