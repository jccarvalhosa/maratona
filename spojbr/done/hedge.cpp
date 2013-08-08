#include <stdio.h>
#include <vector>

using namespace std;

#define fori(i, n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz size()

vector<int> adj[10000], G[10000], P[10000];
int R, c, vis[10000], men[10000];

int dfsp(int v, int p, int ind) {
    vis[v] = men[v] = ++c;
    fori(i, adj[v].sz) {
        int u = adj[v][i];
        if(u != p) {
            if(vis[u]) men[v] = min(men[v], vis[u]);
            else men[v] = min(men[v], dfsp(u, v, i));
        }
    }
    if(p >= 0 && men[v] >= vis[v]) P[p][ind] = 1;
    return men[v];
}

void dfsc(int v) {
    vis[v] = c;
    fori(i, G[v].sz) {
        int u = G[v][i];
        if(!vis[u]) dfsc(u);
    }
}

int main()
{
    int C, Q, a, b;
    while(scanf("%d%d%d", &R, &C, &Q) && R) {
        fori(i, R) {
            adj[i].clear();
            G[i].clear();
            P[i].clear();
        }
        fori(i, C) {
            scanf("%d%d", &a, &b);
            adj[a-1].pb(b-1);
            P[a-1].pb(0);
            adj[b-1].pb(a-1);
            P[b-1].pb(0);
        }
        c=0;
        fori(i, R) vis[i] = 0;
        fori(i, R) if(!vis[i]) dfsp(i, -1, 0);
        fori(i, R) fori(j, adj[i].sz) if(P[i][j]) {
            G[i].pb(adj[i][j]);
            G[adj[i][j]].pb(i);
        }
        c=0;
        fori(i, R) vis[i] = 0;
        fori(i, R) if(!vis[i]) c++, dfsc(i);
        fori(i, Q) {
            scanf("%d%d", &a, &b);
            printf("%c\n", vis[a-1] == vis[b-1] ? 'Y' : 'N');
        }
        printf("-\n");
    }
    return 0;
}
