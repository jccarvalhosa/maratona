#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000000
#define MN 1000
#define ME 100000

int src, snk, E;
int Q[MN], fin[MN], pro[MN], dist[MN];
int flow[ME], cap[ME], nex[ME], to[ME];

void init(int n) {
    E = src = 0;
    snk = n;
    for(int i=0;i<=n;i++) fin[i] = -1;
}

void create_edge(int u, int v, int _cap) {
    to[E] = v, cap[E] = _cap, flow[E] = 0;
    nex[E] = fin[u], fin[u] = E++;
}

void add(int u, int v,int _cap) {
    create_edge(u,v,_cap);
    create_edge(v,u,0);
}

bool bfs() {
    int st, en, i, u, v;
    for(i=0;i<=snk;i++) dist[i] = -1;
    dist[src] = st = en = 0;
    Q[en++] = src;
    while(st < en) {
        u = Q[st++];
        for(i=fin[u];i>=0;i=nex[i]) {
            v = to[i];
            if(flow[i] < cap[i] && dist[v] == -1) {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk]!=-1;
}

int dfs(int u, int fl) {
    if(u==snk) return fl;
    for(int &e=pro[u],v , df; e>=0;e=nex[e]){
        v = to[e];
        if(flow[e] < cap[e] && dist[v] == dist[u]+1) {
            df = dfs(v,min(cap[e]-flow[e],fl));
            if(df > 0) {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}

int dinitz() {
    int ret = 0, df;
    while(bfs()) {
        for(int i=0;i<=snk;i++) pro[i] = fin[i];
        while(1) {
            df = dfs(src,INF);
            if(df) ret += df;
            else break;
        }
    }
    return ret;
}

int n, c[MN], vis[MN];
vector<int> adj[MN];

int main() {
    int m, t=1;
    while(scanf("%d %d", &n, &m) && n) {
        for(int i=0;i<=n;i++) adj[i].clear();
        for(int i=0;i<m;i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--; b--;
            if(a==-1) a=n;
            if(b==-1) b=n;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
		int cmin=0;
		for(int i=0;i<n;i++) c[i] = 1e9;
		while(1) {
			for(int i=0;i<n;i++) {
				init(n);
				src = i;
				for(int v=0;v<=n;v++) {
					for(int j=0;j<adj[v].size();j++) {
						int u = adj[v][j];
						add(v, u, 1);
					}
				}
				c[i] = min(c[i], cmin + dinitz());
			}
			cmin=c[0];
			for(int i=1;i<n;i++) if(!adj[i].empty()) cmin = min(cmin, c[i]);
			if(c[0] == cmin) break;
			for(int i=1;i<n;i++) if(c[i] == cmin) adj[i].clear();
		}
        printf("Case %d: %d\n\n", t++, c[0]);
    }
    return 0;
}
