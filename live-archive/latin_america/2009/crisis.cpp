#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define sz size()
#define all(v) v.begin(), v.end()
#define MAX 100001
using namespace std;

int T;
vector<int> adj[MAX], val[MAX];
int pd[MAX], vis[MAX];

void dfs(int v) {
    int i, u, conv=0;
    vis[v] = 1;
    for(i=0;i<adj[v].sz;i++) {
        u = adj[v][i];
        if(!vis[u]) {
            dfs(u);
            val[v].pb(pd[u]);
        }
    }
    if(val[v].sz == 0) pd[v] = 1;
    else {
        pd[v] = 0;
        sort(all(val[v]));
        while(conv * 100 < T * val[v].sz) pd[v] += val[v][conv++];
    }
}

int main()
{
    int N, i, b;
    while(scanf("%d%d", &N, &T) && N) {
        for(i=0;i<=N;i++) {
            adj[i].clear(); 
            val[i].clear(); 
            vis[i] = 0;
        }
        for(i=1;i<=N;i++) {
            scanf("%d", &b);
            adj[b].pb(i);
            adj[i].pb(b);
        }
        dfs(0);
        printf("%d\n", pd[0]);
    }
    return 0;
}
