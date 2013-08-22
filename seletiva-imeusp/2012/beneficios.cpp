#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
#define MN 1111
#define ME 1111111

int src, snk, E;
int Q[MN], fin[MN], pro[MN], dist[MN];
int flow[ME], cap[ME], next[ME], to[ME];

void init(int n) {
	E=src=0;
	snk=n;
	for(int i=0;i<=n;i++) fin[i]=-1;
}

void create_edge(int u, int v, int _cap) {
	to[E] = v, cap[E] = _cap, flow[E] = 0;
	next[E] = fin[u], fin[u] = E++;
}

void add(int u, int v, int _cap) {
	create_edge(u, v, _cap);
	create_edge(v, u, 0);
}

bool bfs() {
	int st, en, i, u, v;
	for(i=0;i<=snk;i++) dist[i]=-1;
	dist[src] = st = en = 0;
	Q[en++] = src;
	while(st < en) {
		u = Q[st++];
		for(i=fin[u]; i>=0; i=next[i]) {
			v = to[i];
			if(flow[i] < cap[i] && dist[v]==-1) {
				dist[v] = dist[u]+1;
				Q[en++] = v;
			}
		}
	}
	return dist[snk]!=-1;
}

int dfs(int u, int fl) {
	if(u==snk) return fl;
	for(int &e=pro[u], v, df; e>=0; e=next[e]) {
		v = to[e];
		if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
			df = dfs(v, min(cap[e]-flow[e], fl));
			if(df>0) {
				flow[e] += df;
				flow[e^1] -= df;
				return df;
			}
		}
	}
	return 0;
}

int dinitz() {
	int ret=0, df;
	while(bfs()) {
		for(int i=0;i<=snk;i++) pro[i] = fin[i];
		while(1) {
			df = dfs(src, INF);
			if(df) ret += df;
			else break;
		}
	}
	return ret;
}

int c[MN], p[MN], b[MN];

int main() {
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF) {
		for(int i=1;i<=n;i++) cin>>c[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		init(n+m+1);
		for(int i=1;i<=m;i++) {
			cin>>b[i];
			for(int j=0;j<p[i];j++) {
				int v;
				cin>>v;
				add(i, m+v, INF);
			}
		}
		for(int i=1;i<=m;i++) add(0, i, b[i]);
		for(int i=1;i<=n;i++) add(m+i, snk, c[i]);
		int sum=0;
		for(int i=1;i<=m;i++) sum += b[i];
		printf("%d\n", sum-dinitz());
	}
	return 0;
}
