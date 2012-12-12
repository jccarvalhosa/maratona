#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int N, M, ini, fim;
int d[500], vis[500], cut[10000];
vector<piii> adj[500];

void dijkstra()
{
    priority_queue<pii> q;
    int v, u, i, j, dist;
    for(i=0;i<N;i++) {
        vis[i] = 0;
        d[i] = INF;
    }
    d[ini] = 0;
    q.push(make_pair(0, ini));
    while(!q.empty()) {
        v = q.top().second;
        q.pop();
        if(vis[v]) continue;
        vis[v] = 1;
        for(i=0;i<adj[v].size();i++) {
            if(cut[adj[v][i].second]) continue;
            u = adj[v][i].first.first;
            dist = adj[v][i].first.second;
            if(d[u] > d[v] + dist) {
                d[u] = d[v] + dist;
                q.push(make_pair(-d[u], u));
            }
        }
    }
}

int dfs(int v, int total) {
    int i, j, u, dist, flag=0;
    if(total > d[fim]) return 0;
    for(i=0;i<adj[v].size();i++) {
        u = adj[v][i].first.first;
        dist = adj[v][i].first.second;
        j = adj[v][i].second;
        if(u == fim && total+dist == d[fim]) cut[j] = flag = 1;
        if(!cut[j] && dfs(u, total+dist)) cut[j] = flag = 1;
    }
    return flag;
}

int main()
{
    int i, u, v, dist;
    while(scanf("%d%d", &N, &M) && N)
    {
        scanf("%d%d", &ini, &fim);
        for(i=0;i<N;i++) adj[i].clear();
        for(i=0;i<M;i++) {
            scanf("%d%d%d", &u, &v, &dist);
            adj[u].push_back(make_pair(make_pair(v, dist), i));
        }
        for(i=0;i<M;i++) cut[i] = 0;
        dijkstra();
        if(d[fim] == INF) printf("-1\n");
        else {
            dfs(ini, 0);
            dijkstra();
            if(d[fim] == INF) printf("%d\n", -1);
            else printf("%d\n", d[fim]);
        }
    }
    return 0;
}
