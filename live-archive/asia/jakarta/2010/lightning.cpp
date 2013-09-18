#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj[55555];
int pi[55555], level[55555], P[55555][20], sum[55555], dp[55555], n;

void process()
{
    int i, j;
    for(i=0; i<n; i++) for(j=0; (1<<j)<n; j++) P[i][j]=-1;
    for(i=0; i<n; i++) P[i][0]=pi[i];
    for(j=1; (1<<j)<n; j++) for(i=0; i<n; i++) if(P[i][j-1]!=-1) P[i][j]=P[P[i][j-1]][j-1];
}

int query(int p, int q)
{
    int tmp, log, i;
    if(level[p]<level[q])
    {
        tmp=p;
        p=q;
        q=tmp;
    }
    for(log=1; (1<<log)<=level[p]; log++);
    log--;
    for(i=log; i>=0; i--) if(level[p]-(1<<i)>=level[q]) p=P[p][i];
    if(p==q) return p;
    for(i=log; i>=0; i--) if(P[p][i]!=-1 && P[p][i]!=P[q][i])
    {
        p=P[p][i];
        q=P[q][i];
    }
    return pi[p];
}

void dfs(int u, int p)
{
    int i, v;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(v==p) continue;
        level[v]=level[u]+1;
        pi[v]=u;
        dfs(v, u);
    }
}

void go(int u, int p)
{
    int i, v, s=0;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(v==p) continue;
        go(v, u);
        s+=dp[v];
    }
    dp[u]=s+sum[u];
}

int main()
{
    int i, t, q, a, b, c, aux=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            adj[i].clear();
            sum[i]=0;
        }
        for(i=1; i<n; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        level[0]=0;
        pi[0]=-1;
        dfs(0, 0);
        process();
        scanf("%d", &q);
        for(i=0; i<q; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            int lca=query(a, b);
            if(lca==a)
            {
                sum[b]+=c;
                if(pi[a]!=-1) sum[pi[a]]-=c;
            }
            else if(lca==b)
            {
                sum[a]+=c;
                if(pi[b]!=-1) sum[pi[b]]-=c;
            }
            else
            {
                sum[a]+=c;
                sum[b]+=c;
                sum[lca]-=c;
                if(pi[lca]!=-1) sum[pi[lca]]-=c;
            }
        }
        go(0, 0);
        printf("Case #%d:\n", aux++);
        for(i=0; i<n; i++) printf("%d\n", dp[i]);
    }
    return 0;
}
