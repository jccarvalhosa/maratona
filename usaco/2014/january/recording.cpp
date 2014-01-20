#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;
#define INF (int)1e9

const int MAXN = 500;
const int MAXE = MAXN*MAXN;

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

int n, l[MAXN], r[MAXN];

int main() {
	ifstream in("recording.in");
	ofstream out("recording.out");
	in>>n;
	int v=n+2;
	init(0, 2*v-1, 2*v);
	for(int i=0;i<v;i++) addEdge(2*i, 2*i+1, i==0 || i==v-1 ? 2 : 1, 0);
	for(int i=1;i<=n;i++) in>>l[i]>>r[i];
	for(int i=1;i<=n;i++) {
		addEdge(1, 2*i, 1, -1);
		addEdge(2*i+1, 2*(v-1), 1, 0);
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {
		if(r[i] <= l[j]) addEdge(2*i+1, 2*j, 1, -1);
		if(r[j] <= l[i]) addEdge(2*j+1, 2*i, 1, -1);
	}
	int cost;
	mcmf(cost);
	out<<-cost<<endl;
	return 0;
}

