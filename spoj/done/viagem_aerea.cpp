#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<piii, int> piiii;

int main()
{
    int N, F, ini, fim;
    int i, o, d, t, c;
    int tem[1000], esc[1000], cus[1000], vis[1000];
    vector<piii> adj[1000];
    piiii dado;
    char id;
    scanf("%d%d %c ", &N, &F, &id);
    scanf("%d%d", &ini, &fim);
    ini--; fim--;
    for(i=0;i<N;i++) {
        adj[i].clear();
        tem[i] = esc[i] = cus[i] = INF;
        vis[i] = 0;
    }
    for(i=0;i<F;i++) {
        scanf("%d%d%d%d", &o, &d, &c, &t);
        adj[o-1].push_back(make_pair(make_pair(c, t), d-1));
    }

    priority_queue<piiii> q;
    tem[ini] = cus[ini] = 0;
    esc[ini] = -1;
    q.push(make_pair(make_pair(make_pair(0, 0), -1), ini));
    int v, u, dt, dc, add;
    while(!q.empty()) {
        v = q.top().second;
        q.pop();
        if(vis[v]) continue;
        if(v == fim) break;
        vis[v] = 1;
        for(i=0;i<adj[v].size();i++) {
            u = adj[v][i].second;
            dc = adj[v][i].first.first;
            dt = adj[v][i].first.second;
            add = 0;
            if(id == 'P') {
                if(cus[u] > cus[v] + dc) add = 1;
                else if(cus[u] == cus[v] + dc) {
                    if(tem[u] > tem[v] + dt) add = 1;
                    else if((tem[u] == tem[v] + dt) && esc[u] > esc[v]+1) add = 1;
                }
                if(add) {
                    cus[u] = cus[v] + dc;
                    tem[u] = tem[v] + dt;
                    esc[u] = esc[v] + 1;
                    q.push(make_pair(make_pair(make_pair(-cus[u], -tem[u]), -esc[u]), u));
                }
            } else {
                if(tem[u] > tem[v] + dt) add = 1;
                else if(tem[u] == tem[v] + dt) {
                    if(cus[u] > cus[v] + dc) add = 1;
                    else if((cus[u] == cus[v] + dc) && esc[u] > esc[v]+1) add = 1;
                }
                if(add) {
                    cus[u] = cus[v] + dc;
                    tem[u] = tem[v] + dt;
                    esc[u] = esc[v] + 1;
                    q.push(make_pair(make_pair(make_pair(-tem[u], -cus[u]), -esc[u]), u));
                }
            }
        }
    }

    if(tem[fim] == INF) printf("-1\n");
    else printf("%d %d %d\n", cus[fim], tem[fim], esc[fim]);
    return 0;
}
