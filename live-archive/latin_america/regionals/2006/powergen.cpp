#include <stdio.h>
#include <vector>
#define INF 1e9

using namespace std;

int dist(int x1, int y1, int x2, int y2) { return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2); }

int N, C, resp, cap[100000], vis[100000];
vector<int> adj[100000];

void dfs(int v, int pai) {
    vis[v] = 1;
    for(int i=0;i<adj[v].size();i++) if(!vis[adj[v][i]]) dfs(adj[v][i], v);
    if(cap[v] >= C) resp++;
    else if(pai != -1) cap[pai] += cap[v];
}

int main()
{
    int p[100000][2];
    int i, j, nj, c, x, y, d, nd;
    while(scanf("%d%d", &N, &C) && N)
    {
        for(i=0;i<N;i++) adj[i].clear();
        for(i=0;i<N;i++) {
            scanf("%d%d%d", &x, &y, &c);
            p[i][0] = x;
            p[i][1] = y;
            cap[i] = c;
            d = j = INF;
            for(nj=0;nj<i;nj++) {
                nd = dist(x, y, p[nj][0], p[nj][1]);
                if(nd < d) d = nd, j = nj;
            }
            if(j != INF) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        resp = 0;
        for(i=0;i<N;i++) vis[i]=0;
        dfs(0, -1);
        printf("%d\n", resp);
    }
    return 0;
}
