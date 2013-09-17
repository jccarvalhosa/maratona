#include <stdio.h>
#include <vector>
#include <algorithm>
#define fori(i, n) for(int i=0;i<(n);i++)
#define forr(i, n) for(int i=(n)-1;i>=0;i--)
#define pb push_back
#define sz size()
#define MAX 20002

using namespace std;

int tru(int a) { return 2*a; }
int fal(int a) { return 2*a+1; }

int C, P, V, c, vis[MAX], ord[MAX], comp[MAX];
vector<int> g[MAX], ginv[MAX];

void dfs(int v) {
    vis[v] = 1;
    fori(i, g[v].sz) { int u = g[v][i]; if(!vis[u]) dfs(u); }
    ord[c++] = v;
}

void dfsinv(int v) {
    vis[v] = 1;
    comp[v] = c;
    fori(i, ginv[v].sz) { int u = ginv[v][i]; if(!vis[u]) dfsinv(u); }
}

void cfconexas() {
    c=0;
    fori(i, V) vis[i]=0;
    fori(i, V) if(!vis[i]) dfs(i);
    c=0;
    fori(i, V) vis[i]=0;
    dfsinv(0), dfsinv(1), c++;
    forr(i, V) if(!vis[ord[i]]) dfsinv(ord[i]), c++;
}

int main()
{
    int x, y, s, t, i;
    while(scanf("%d%d", &C, &P) && C) {
        P++; V = 2*P;
        for(i=0;i<V;i++) g[i].clear(), ginv[i].clear();
        for(i=0;i<C;i++) {
            scanf("%d%d%d%d", &x, &y, &s, &t);
            g[fal(x)].pb(tru(y));
            ginv[tru(y)].pb(fal(x));
            g[fal(y)].pb(tru(x));
            ginv[tru(x)].pb(fal(y));
            g[tru(s)].pb(fal(t));
            ginv[fal(t)].pb(tru(s));
            g[tru(t)].pb(fal(s));
            ginv[fal(s)].pb(tru(t));
        }
        cfconexas();
        for(i=1;i<P;i++) if(comp[tru(i)] == comp[fal(i)]) break;
        if(i == P) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
