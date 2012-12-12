#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#define pb push_back
#define sz size()
#define mp make_pair

using namespace std;

vector<int> adj[1001];
int out[1001], vis[1001], grau[1001], tam[1001], cc;

void dfs(int v) {
    int i, u;
    vis[v]=cc;
    tam[cc]++;
    for(i=0;i<adj[v].sz;i++) {
        u = adj[v][i];
        if(!vis[u] && !out[u]) dfs(u);
    }
}

int main()
{
    int i, N, P, K, a, b, resp;
    queue<int> q;
    while(scanf("%d", &N) && N) {
        scanf("%d%d", &P, &K);
        for(i=1;i<=N;i++) {
            adj[i].clear();
            out[i] = vis[i] = tam[i] = 0;
        }
        for(i=1;i<=P;i++) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b); adj[b].pb(a);
        }
        for(i=1;i<=N;i++) {
            grau[i] = adj[i].sz;
            if(grau[i] < K) q.push(i);
        }
        while(!q.empty()) {
            a = q.front();
            q.pop();
            if(!out[a]) {
                out[a] = 1;
                for(i=0;i<adj[a].sz;i++) {
                    b = adj[a][i];
                    grau[b]--;
                    if(grau[b] < K) q.push(b);
                }
            }
        }
        cc=0;
        for(i=1;i<=N;i++) if(!vis[i] && !out[i]) cc++, dfs(i);
        resp=0;
        for(i=1;i<=cc;i++) resp = max(resp, tam[i]);
        printf("%d\n", resp);
    }
    return 0;
}
