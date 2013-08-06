
#include <cstdio>
#include <vector>
#define MAX 5555

using namespace std;

vector<int> adj[MAX];
int pi[MAX], cycle[MAX], vis[MAX];

void dfs(int u, int p)
{
    int i, v;
    vis[u]=1;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(v==p) continue;
        if(!vis[v])
        {
            pi[v]=u;
            dfs(v, u);
        }
        else if(vis[v]==1) cycle[u]=v;
    }
    vis[u]=2;
}

int main()
{
    int i, j, t, n, m, a, b, resp, cont;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i=1; i<=n; i++)
        {
            adj[i].clear();
            pi[i]=-1;
            vis[i]=cycle[i]=0;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 1);
        resp=0;
        for(i=1; i<=n; i++) if(cycle[i])
        {
            cont=1;
            for(j=i; j!=cycle[i]; j=pi[j]) cont++;
            if(cont>resp) resp=cont;
        }
        printf("%d\n", resp);
    }
    return 0;
}
