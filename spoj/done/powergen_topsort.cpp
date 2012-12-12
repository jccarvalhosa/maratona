#include <stdio.h>
#include <utility>
#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int dist(int x1, int y1, int x2, int y2) { return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2); }

int main()
{
    int N, C, cap[100000], dep[100000], vis[100000], p[100000][2];
    int i, j, newj, c, x, y, d, newd, resp, a, b;
    vector<int> adj[100000], topsort;
    while(scanf("%d%d", &N, &C) && N)
    {
        for(i=0;i<N;i++) adj[i].clear();
        scanf("%d%d%d", &x, &y, &c);
        p[0][0] = x; p[0][1] = y;
        cap[0] = c;
        for(i=1;i<N;i++) {
            scanf("%d%d%d", &x, &y, &c);
            d = INF;
            for(newj=0;newj<i;newj++) {
                newd = dist(x, y, p[newj][0], p[newj][1]);
                if(newd < d) { d = newd; j = newj; }
            }
            p[i][0] = x; p[i][1] = y;
            cap[i] = c;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        resp = 0;
        topsort.clear();
        for(i=0;i<N;i++) {
            dep[i] = adj[i].size();
            if(dep[i] <= 1) {
                topsort.push_back(i);
                vis[i] = 1;
            }
            else vis[i] = 0;
        }
        for(i=0;i<topsort.size();i++) {
            a = topsort[i];
            vis[a] = 2;
            if(!dep[a] && cap[a] >= C) resp++; 
            if(dep[a] == 1) {
                for(j=0;j<adj[a].size();j++) if(vis[adj[a][j]] != 2) break;
                b = adj[a][j];
                dep[b]--;
                if(cap[a] >= C) resp++;
                else cap[b] += cap[a];
                if(dep[b] == 1 && !vis[b]) {
                    topsort.push_back(b);
                    vis[b] = 1;
                }
            }
        }
        printf("%d\n", resp);
    }
    return 0;
}
