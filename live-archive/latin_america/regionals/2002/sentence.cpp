#include <stdio.h>
#include <vector>
#define MAX 2001
#define pb push_back
#define sz size()

using namespace std;

int N, V, vis[MAX], p[MAX], n[MAX], cc;
vector<int> g[MAX];

int neg(int a) { return N + a; }

void dfs(int v) {
    int u, i;
    vis[v]=cc;
    if(v<N) p[cc]++;
    else n[cc]++;
    for(i=0;i<g[v].sz;i++) {
        u = g[v][i];
        if(!vis[u]) dfs(u);
    }
}

int main()
{
    int i, j, v, resp;
    char c[1000];
    while(scanf("%d", &N) && N) {
        V = 2*N;
        for(i=0;i<V;i++) {
            g[i].clear();
            vis[i]=p[i]=n[i]=0;
        }
        for(i=0;i<N;i++) {
            scanf(" %s ", c);
            scanf("%d", &v); v--;
            scanf(" %s ", c);
            scanf(" %s ", c);
            if(c[0] == 'f') {
                g[i].pb(neg(v));
                g[neg(v)].pb(i);
                g[neg(i)].pb(v);
                g[v].pb(neg(i));
            }
            if(c[0] == 't') {
                g[i].pb(v);
                g[v].pb(i);
                g[neg(i)].pb(neg(v));
                g[neg(v)].pb(neg(i));
            }
        }
        cc=0;
        for(i=0;i<V;i++) if(!vis[i]) cc++, dfs(i);
        for(i=0;i<N;i++) if(vis[i] == vis[neg(i)]) break;
        if(i != N) printf("Inconsistent\n");
        else {
            resp=0;
            for(i=1;i<=cc;i++) {
                if(p[i]>n[i]) resp+=2*p[i];
                if(p[i]==n[i]) resp+=p[i];
            }
            printf("%d\n", resp/2);
        }
    }
    return 0;
}
