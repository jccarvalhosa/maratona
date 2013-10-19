#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[222222];
int vis[222222], dead[222222], val[222222], anc[222222];

void start(int u, int d)
{
    int i, v;
    vis[u]=1;
    anc[u]=d;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(!vis[v]) start(v, d);
    }
}

void dfs(int u, int d)
{
    int i, v;
    vis[u]=1;
    val[u]=d;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(!vis[v]) dfs(v, d);
    }
}

int main()
{
    int i, n, m, fa, mo, k, t, id, dna, f, cur, last;
    char c;
    while(scanf("%d", &n)!=EOF)
    {
        t=n;
        for(i=1; i<=n; i++) scanf(" %c", &c);
        scanf("%d", &m);
        for(i=0; i<=n+m+10; i++)
        {
            adj[i].clear();
            vis[i]=dead[i]=val[i]=0;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d", &fa);
            if(fa<0) dead[-fa]=1;
            else
            {
                scanf("%d %c ", &mo, &c);
                adj[++t].push_back(mo);
                adj[mo].push_back(t);
            }
        }
        scanf("%d", &k);
        for(i=0; i<k; i++)
        {
            scanf("%d %d", &id, &dna);
            if(!vis[id]) dfs(id, dna);
        }
        for(i=0; i<=n+m+10; i++) vis[i]=0;
        for(i=1; i<=t; i++) if(!vis[i]) start(i, i);
        last=0;
        for(i=1; i<=t; i++) if(!dead[i])
        {
            if(!last) last=anc[i];
            else if(last!=anc[i]) break;
        }
        if(i==t+1) printf("YES\n");
        else
        {
            //for(i=1; i<=t; i++) printf("%d %d\n", dead[i], val[i]);
            f=last=0;
            for(i=1; i<=t; i++) if(!dead[i])
            {
                if(!val[i]) f=1;
                else
                {
                    cur=val[i];
                    if(last && last!=cur) break;
                    last=cur;
                }
            }
            if(f)
            {
                if(i==t+1) printf("POSSIBLY\n");
                else printf("NO\n");
            }
            else
            {
                if(i==t+1) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}
