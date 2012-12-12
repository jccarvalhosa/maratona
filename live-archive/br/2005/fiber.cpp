#include <stdio.h>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define sz size()
#define INF 1e9
#define fori(i, N) for(int i=0;i<(N);i++)


using namespace std;

int N;
vector<int> adj[1000];
vector<pair<int, int> > r[1000];
string city[1000];
int vis[1000];
double pd[1000][50];

void dfs(int v, int pai) {
    vis[v] = 1;
    fori(i, adj[v].sz) {
        int u = adj[v][i];
        if(!vis[u]) dfs(u, v);
    }
    if(pai != -1) {
        fori(i, r[pai].sz) {
            double best=INF;
            fori(j, r[v].sz) best = min(best, pd[v][j] + hypot(r[pai][i].first-r[v][j].first, r[v][j].second-r[pai][i].second));
            pd[pai][i] += best;
        }
    }
}

int main()
{
    int N, i, j, c, x, y;
    string s;
    while(scanf("%d", &N) && N) {
        for(i=0;i<N;i++) {
            r[i].clear();
            adj[i].clear();
            vis[i]=0;
        }
        map<string, int> id;
        for(i=0;i<N;i++) {
            cin >> city[i];
            id[city[i]] = i;
            scanf("%d", &c);
            for(j=0;j<c;j++) {
                scanf("%d%d", &x, &y);
                r[i].pb(mp(x, y));
                pd[i][j] = 0;
            }
        }
        for(i=0;i<N-1;i++) {
            cin >> s;
            x = id[s];
            cin >> s;
            y = id[s];
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs(0, -1);
        double sol = INF;
        for(i=0;i<r[0].sz;i++) sol = min(sol, pd[0][i]);
        printf("%.1lf\n", sol);
    }
    return 0;
}

