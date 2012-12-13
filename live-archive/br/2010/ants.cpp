#include <cstdio>
#include <vector>
using namespace std;
#define MN 100000
#define MLN 100
typedef long long ll;

int N, vis[MN], pai[MN][MLN], ord[MN];
ll dist[MN];
vector<pair<int, int> > adj[MN];

void dfs(int v, int p, ll d) {
    vis[v] = 1;
    pai[v][0] = p;
    dist[v] = d;
    ord[v] = (p == v) ? 0 : ord[p]+1;
    int i, u;
    for(i=0;i<adj[v].size();i++) {
        u = adj[v][i].first;
        if(!vis[u]) dfs(u, v, d+adj[v][i].second);
    }
}

int lca(int a, int b) {
	int i, loga=1;
	if(ord[a] < ord[b]) swap(a, b);
	while((1<<loga) <= ord[a]) loga++; loga--;
	for(i=loga;i>=0;i--) if(ord[a]-(1<<i) >= ord[b]) a = pai[a][i];
	if(a == b) return a;
	for(i=loga;i>=0;i--) if(pai[a][i] != pai[b][i]) a=pai[a][i], b=pai[b][i];
	return pai[a][0];
}

int main() {
    int i, j, a, b, c, l, Q;
    while(scanf("%d", &N) && N) {
        for(i=0;i<N;i++) {
            adj[i].clear();
            vis[i] = 0;
        }
        for(i=1;i<N;i++) {
            scanf("%d%d", &a, &l);
            adj[a].push_back(make_pair(i, l));
            adj[i].push_back(make_pair(a, l));
        }
        dfs(0, 0, 0);
		for(i=0;i<N;i++) for(j=1;(1<<j)<N;j++) pai[i][j] = pai[pai[i][j-1]][j-1];
        scanf("%d", &Q);
        for(i=0;i<Q;i++) {
            scanf("%d%d", &a, &b);
            if(i) printf(" ");
            c = lca(a, b);
            printf("%lld", dist[a]+dist[b]-2*dist[c]);
        }
        printf("\n");
    }
    return 0;
}
