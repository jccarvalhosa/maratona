#include <cstdio>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

vector<int> adj[22222];
int match[22222], d[22222], n;

int bfs()
{
    int u, v, i;
    queue<int> q;
    for(i=0; i<=n; i++)
    {
        if(!match[i])
        {
            d[i]=0;
            q.push(i);
        }
        else d[i]=INF;
    }
    d[0]=INF;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(u)
        {
            for(i=0; i<adj[u].size(); i++)
            {
                v=adj[u][i];
                if(d[match[v]]==INF)
                {
                    d[match[v]]=d[u]+1;
                    q.push(match[v]);
                }
            }
        }
    }
    return (d[0]!=INF);
}

int dfs(int u)
{
    int i, v;
    if(u)
    {
        for(i=0; i<adj[u].size(); i++)
        {
            v=adj[u][i];
            if(d[match[v]]==d[u]+1 && dfs(match[v]))
            {
                match[v]=u;
                match[u]=v;
                return 1;
            }
        }
        d[u]=INF;
        return 0;
    }
    return 1;
}

int hopcroft_karp()
{
    int matching=0, i;
    while(bfs()) for(i=1; i<=n; i++) if(!match[i] && dfs(i)) matching++;
    return matching;
}

int main()
{
    int i, j, a, nr, b;
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0; i<=2*n; i++)
        {
            adj[i].clear();
            match[i]=0;
            d[i]=INF;
        }
        for(i=0; i<n; i++)
        {
            scanf("%d: (%d)", &a, &nr);
            for(j=0; j<nr; j++)
            {
                scanf("%d", &b);
                adj[a+1].push_back(b+1);
            }
        }
        printf("%d\n", hopcroft_karp());
    }
    return 0;
}
