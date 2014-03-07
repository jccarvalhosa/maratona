#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, m, k;
const int N=1e5+10;
const int M=555;
const int INF=1e9;
vector<pii> adj[N];

int dist[M][M], q[M], sum[M];
int c[N], vis[N];

void dfs(int v) {
	if(vis[v]) return;
	vis[v]=1;
	for(int i=0;i<adj[v].size();i++) if(adj[v][i].second == 0) dfs(adj[v][i].first);
}

int solve() {
	for(int cor=1;cor<=k;cor++) {
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) if(c[i]==cor) { dfs(i); break; }
		for(int i=1;i<=n;i++) if(c[i]==cor && !vis[i]) return 0;
	}
	return 1;
}

int main() {
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) {
		scanf("%d", &q[i]);
		sum[i] = sum[i-1] + q[i];
	}
	int j=0;
	for(int i=1;i<=n;i++) {
		while(sum[j]<i) j++;
		c[i]=j;
	}
	for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) dist[i][j]=INF;
	for(int i=1;i<=k;i++) dist[i][i]=0;
	for(int i=0;i<m;i++) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back(pii(b, d));
		adj[b].push_back(pii(a, d));
		dist[c[a]][c[b]] = dist[c[b]][c[a]] = min(d, dist[c[b]][c[a]]);
	}
	if(solve()) {
		printf("Yes\n");
		for(int kk=1;kk<=k;kk++) for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) dist[i][j] = min(dist[i][j], dist[i][kk] + dist[kk][j]);
		for(int i=1;i<=k;i++) { for(int j=1;j<=k;j++) printf("%d%c", dist[i][j]==INF ? -1 : dist[i][j], j==k?'\n':' '); }
	}
	else printf("No\n");
	return 0;
}
