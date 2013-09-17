#include <cstdio>
#include <map>
#include <vector>
using namespace std;
#define sz size()
#define mp make_pair

vector<int> adj[200000];
int vis[200000], pai[200000];
pair<int, int> cycle;

int dfs(int v, int p) {
    vis[v]=1;
    pai[v]=p;
    int i, u;
    for(i=0;i<adj[v].sz;i++) {
        u = adj[v][i];
        if(u != p) {
            if(vis[u]) { cycle = make_pair(v, u); return 0; }
            else if(!dfs(u, v)) return 0;
        }
    }
    return 1;
}

int main() {
    int N, K, W, a, b, i, j, flag;
    while(scanf("%d%d", &K, &W) && K) {
        map<int, int> id;
        for(i=0;i<2*W;i++) adj[i].clear();
        flag=1;
        for(i=N=0;i<W;i++) {
            scanf("%d%d", &a, &b);
            if(!id.count(a)) id[a] = N++;
            if(!id.count(b)) id[b] = N++;
            a = id[a]; b = id[b];
            for(j=0;j<adj[a].sz;j++) if(adj[a][j] == b) break;
            if(j == adj[a].sz) {
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            if(adj[a].sz > 2 || adj[b].sz > 2) flag=0;
        }
        if(!flag) printf("N\n");
        else {
            for(i=0;i<N;i++) vis[i]=0;
            for(i=0;i<N;i++) if(!vis[i] && !dfs(i, -1)) break;
            if(i == N) printf("Y\n");
            else {
                for(i=1, a=cycle.first; a != cycle.second; i++, a=pai[a]);
                if(i == K) printf("Y\n");
                else printf("N\n");
            }
        }
    }
    return 0;
}
