#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
#define MN 2555
#define ME 111111

int src, snk, E;
int Q[MN], fin[MN], pro[MN], dist[MN];
int flow[ME], cap[ME], nex[ME], to[ME];

void init(int n) {
	E=src=0;
	snk=n;
	for(int i=0;i<=n;i++) fin[i]=-1;
}

void create_edge(int u, int v, int _cap) {
	to[E] = v, cap[E] = _cap, flow[E] = 0;
	nex[E] = fin[u], fin[u] = E++;
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
		for(i=fin[u]; i>=0; i=nex[i]) {
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
	for(int &e=pro[u], v, df; e>=0; e=nex[e]) {
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

char tab[55][55];

int main() {
	int T, w, h, x, y, z;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &w, &h);
		scanf("%d%d%d", &x, &y, &z);
		for(int i=0;i<h;i++) scanf("%s", tab[i]);
		init(w*h+2);
		int sum=0;
		for(int i=0;i<h;i++) for(int j=0;j<w;j++) if(i==0 || i==h-1 || j==0 || j==w-1) {
			 if(tab[i][j] == '.') tab[i][j]='#', sum+=y;
		}
		for(int i=0;i<h;i++) for(int j=0;j<w;j++) {
			int pos = i*w+j+1;
			if(tab[i][j] == '.') add(pos, snk, y);
			else {
				if(i==0 || i==h-1 || j==0 || j==w-1) add(src, pos, INF);
				else add(src, pos, x);
			}
		}
		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, 1, -1};
		for(int i=0;i<h;i++) for(int j=0;j<w;j++) {
			int pos = i*w+j+1;
			for(int k=0;k<4;k++) {
				int ii = i+dx[k];
				int jj = j+dy[k];
				if(ii >= 0 && ii < h && jj >= 0 && jj < w) {
					int npos = ii*w+jj+1;
					add(pos, npos, z);
				}
			}
		}
		printf("%d\n", sum+dinitz());
	}
	return 0;
}
