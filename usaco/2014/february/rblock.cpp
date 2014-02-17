#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

const int N=255;
const int INF=1e9;
int n, m, vis[N], adj[N][N], d[N][N], dist[N];

int dijkstra() {
	for(int i=1;i<=n;i++) {
		vis[i]=0;
		dist[i]=INF;
	}
	dist[1]=0;
	priority_queue<pii> q;
	q.push(pii(0, 1));
	while(!q.empty()) {
		int v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(int u=1;u<=n;u++) if(dist[u] > dist[v] + adj[v][u]) {
			dist[u] = dist[v] + adj[v][u];
			q.push(pii(-dist[u], u));
		}
	}
	return dist[n];
}

int main() {
	freopen("rblock.in", "r", stdin);
	freopen("rblock.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) adj[i][j] = d[i][j] = INF;
	for(int i=1;i<=n;i++) adj[i][i] = d[i][i]=0;
	for(int i=1;i<=m;i++) {
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		adj[a][b] = adj[b][a] = d[a][b] = d[b][a] = min(d[a][b], l);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
	int ans=0;
	int a, b;
	for(a=1;a!=n;a=b) {
		for(b=1;b<=n;b++) if(b!=a && d[a][n] == adj[a][b] + d[b][n]) break;
		adj[a][b] *= 2;
		adj[b][a] *= 2;
		ans = max(ans, dijkstra());
		adj[a][b] /= 2;
		adj[b][a] /= 2;
	}
	printf("%d\n", ans - d[1][n]);
	return 0;
}
