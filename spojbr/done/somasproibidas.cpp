#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> adj[100000], g[2];
int vis[100000];

int dfs(int v) {
    int i, u;
    for(i=0;i<adj[v].size();i++) {
        u = adj[v][i];
        if(vis[u] == vis[v]) break;
        if(!vis[u]) {
            vis[u] = 3 - vis[v];
            if(!dfs(u)) return 0;
        }
    }
    if(i == adj[v].size()) return 1;
    return 0;
}

int main()
{
    int N, M, i, j, ini, fim;
    int soma;
    int v[100000];
    map<int, int> m;
    scanf("%d%d", &N, &M);
    for(i=0;i<N;i++) scanf("%d", &v[i]);
    sort(v, v+N);
    for(i=0;i<M;i++) {
        scanf("%d", &soma);
        ini=0; fim=N-1;
        while(ini<fim) {
            if(v[ini] + v[fim] < soma) ini++;
            else if(v[ini] + v[fim] > soma) fim--;
            else {
                adj[ini].push_back(fim);
                adj[fim].push_back(ini);
                ini++;
            }
        }
    }
    for(i=0;i<N;i++) vis[i] = 0;
    for(i=0;i<N;i++) if(!vis[i]) {
        vis[i] = 1;
        if(!dfs(i)) break;
    }
    if(i != N) printf("-1\n-1\n");
    else {
        for(i=0;i<N;i++) g[vis[i]-1].push_back(v[i]);
        for(i=0;i<2;i++) {
            sort(g[i].begin(), g[i].end());
            printf("%lu ", g[i].size());
            for(j=0;j<g[i].size();j++) printf("%d ", g[i][j]);
            printf("\n");
        }
    }
}
