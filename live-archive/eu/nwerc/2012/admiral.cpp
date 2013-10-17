#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 1e9

const int MAXN = 2222;
const int MAXE = 22222;

int src, snk, nNode, nEdge;
int fin[MAXN], pre[MAXN], dist[MAXN];
int cap[MAXE], cost[MAXE], nxt[MAXE], to[MAXE], from[MAXE];

inline void init(int _src, int _snk, int nodes) {
	nNode = nodes, nEdge = 0;
	src = _src, snk = _snk;
	for(int i=0;i<nodes;i++) fin[i]=-1;
}

inline void addEdge(int u, int v, int _cap, int _cost) {
	from[nEdge] = u, to[nEdge] = v, cap[nEdge] = _cap, cost[nEdge] = _cost;
	nxt[nEdge] = fin[u], fin[u] = nEdge++;
	from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0, cost[nEdge] = -(_cost);
	nxt[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bellman() {
	int iter, u, v, i;
	int flag = 1;
	for(int i=0;i<nNode;i++) {
		pre[i]=-1;
		dist[i] = INF;
	}
	dist[src] = 0;
	for(iter = 1; iter < nNode && flag; iter++) {
		flag = 0;
		for(u = 0; u < nNode; u++) {
			for(i = fin[u]; i >= 0; i = nxt[i]) {
				v = to[i];
				if(cap[i] && dist[v] > dist[u] + cost[i]) {
					dist[v] = dist[u] + cost[i];
					pre[v] = i;
					flag = 1;
				}
			}
		}
	}
	return dist[snk] < INF;
}

int mcmf(int &fcost) {
	int netflow, bot, u;
	netflow = fcost = 0;
	while(bellman()) {
		bot = INF;
		for(u = pre[snk]; u >= 0; u = pre[from[u]]) bot = min(bot, cap[u]);
		for(u = pre[snk]; u >= 0; u = pre[from[u]]) {
			cap[u] -= bot;
			cap[u^1] += bot;
			fcost += bot * cost[u];
		}
		netflow += bot;
	}
	return netflow;
}

int main() {
	int v, e, a, b, c, cost;
	while(scanf("%d %d", &v, &e)!=EOF) {
		init(0, 2*v-1, 2*v);
		for(int i=0;i<v;i++) addEdge(2*i, 2*i+1, i==0 || i==v-1 ? 2 : 1, 0);
		while(e--) {
			scanf("%d %d %d", &a, &b, &c); a--; b--;
			addEdge(2*a+1, 2*b, 1, c);
		}
		mcmf(cost);
		printf("%d\n", cost);
	}
	return 0;
}
