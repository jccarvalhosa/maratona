#include <cstdio>
using namespace std;

const int N=2e3+10;
int n, adj[N][N], vis[N];

void dfs(int v) { vis[v]=1; for(int u=0;u<n;u++) if(!vis[u] && adj[v][u]) dfs(u); }
void dfsi(int v) { vis[v]=1; for(int u=0;u<n;u++) if(!vis[u] && adj[u][v]) dfsi(u); }

int main() {
	scanf("%d", &n);
	int valid=1;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &adj[i][j]);
	for(int i=0;i<n;i++) vis[i]=0;
	dfs(0);
	for(int i=0;i<n;i++) if(!vis[i]) valid=0;
	for(int i=0;i<n;i++) vis[i]=0;
	dfsi(0);
	for(int i=0;i<n;i++) if(!vis[i]) valid=0;
	if(valid) printf("YES\n");
	else printf("NO\n");
	return 0;
}
