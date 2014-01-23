#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define INF 1000000000
#define MN 11111
#define ME 333333

int src, snk, E;
int Q[MN], fin[MN], pro[MN], dist[MN];
int flow[ME], cap[ME], ne[ME], to[ME], from[ME];

void init(int n) {
	E=src=0;
	snk=n;
	for(int i=0; i<=n; i++) fin[i]=-1;
}

void create_edge(int u, int v, int _cap) {
	from[E]=u, to[E]=v, cap[E]=_cap, flow[E]=0;
	ne[E]=fin[u], fin[u]=E++;
}

void add(int u, int v, int _cap) {
	create_edge(u, v, _cap);
	create_edge(v, u, 0);
}

bool bfs() {
	int st, en, i, u, v;
	for(int i=0; i<=snk; i++) dist[i]=-1;
	dist[src]=st=en=0;
	Q[en++]=src;
	while(st<en) {
		u=Q[st++];
		for(i=fin[u]; i>=0; i=ne[i]) {
			v=to[i];
			if(flow[i]<cap[i] && dist[v]==-1) {
				dist[v]=dist[u]+1;
				Q[en++]=v;
			}
		}
	}
	return dist[snk]!=-1;
}

int dfs(int u, int fl) {
	if(u==snk) return fl;
	for(int &e=pro[u], v, df; e>=0; e=ne[e]) {
		v=to[e];
		if(flow[e]<cap[e] && dist[v]==dist[u]+1) {
			df=dfs(v, min(cap[e]-flow[e], fl));
			if(df>0) {
				flow[e]+=df;
				flow[e^1]-=df;
				return df;
			}
		}
	}
	return 0;
}

int dinitz() {
	int ret=0, df;
	while(bfs()) {
		for(int i=0; i<=snk; i++) pro[i]=fin[i];
		while(1) {
			df=dfs(src, INF);
			if(df) ret+=df;
			else break;
		}
	}
	return ret;
}

int g[MN], a[ME], b[ME];
vector<int> adj[MN];

void bfs_bip(int s) {
	int i, u, v;
	queue<int> q;
	g[s]=1;
	q.push(s);
	while(!q.empty()) {
		u=q.front();
		q.pop();
		for(i=0; i<adj[u].size(); i++) {
			v=adj[u][i];
			if(!g[v]) {
				if(g[u]==1) g[v]=2;
				else g[v]=1;
				q.push(v);
			}
		}
	}
}

int main() {
	int i, n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(i=0; i<m; i++) {
		scanf("%d %d", &a[i], &b[i]);
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	init(n+1);
	for(i=1; i<=n; i++) if(!g[i]) bfs_bip(i);
	for(i=1; i<=n; i++) if(g[i]==1) add(src, i, 1);
	for(i=1; i<=n; i++) if(g[i]==2) add(i, snk, 1);
	for(i=0; i<m; i++) {
		if(g[a[i]]==1) add(a[i], b[i], 1);
		else add(b[i], a[i], 1);
	}
	printf("skojarzenie\n%d\n", dinitz());
	for(i=0; i<E; i++) if(flow[i]==1 && from[i]>0 && to[i]<snk && from[i] < snk && to[i] > 0) printf("%d %d\n", from[i], to[i]);
	return 0;
}
