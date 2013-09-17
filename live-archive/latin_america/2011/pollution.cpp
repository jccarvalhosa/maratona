#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#define INF 1000000000
#define MAXP 20000

using namespace std;

int M, num, vis[MAXP], val[MAXP],  vsoma[MAXP], a, b, resp;
vector<pair<int, int> > grafo[MAXP], dep[MAXP][2];
pair<int, int> pai[MAXP];
map<int, int> m;

int indice(int a)
{
    if(m.count(a) == 0)
    {
        a = m[a] = m.size() - 1;
        val[a] = INF;
        return a;
    }
    return m[a];
}

void mark(int v)
{
    int i, j, u, d;
    for(i=0;i<=1;i++)
    {
        for(j=0;j<dep[v][i].size();j++)
        {
            u = dep[v][i][j].first;
            d = dep[v][i][j].second;
            if(val[u] == INF)
            {
                if(i == 0) val[u] = d - val[v];
                else val[u] = val[v] - d;
                mark(u);
            }
        }
    }
}

void go(int v, int sum, int sign, int orig)
{
    int i, u, d;
    vis[v] = 1; 
    pai[v] = make_pair(orig, sign);
    if(val[orig] == INF && val[v] == INF)
    {
        vsoma[v] = sum;
        if(sign == 1) dep[orig][0].push_back(make_pair(v, sum));
        else dep[orig][1].push_back(make_pair(v, sum));
    }
    for(i=0;i < grafo[v].size(); i++)
    {
        u = grafo[v][i].first;
        d = sum - grafo[v][i].second * sign;
        if(val[u] != INF)
        {
            val[orig] = d + sign * val[u];
            mark(orig);
        }
        else
        {
            if(val[orig] != INF) val[u] = sign * (val[orig] - d); 
            else if(vis[u] && pai[u].first == orig &&  pai[u].second == sign)
            {
                if(u == orig) val[orig] = d / 2;
                else
                {
                    if(sign == 1) val[u] = (vsoma[u] - d) / 2;
                    else val[u] = (d - vsoma[u]) / 2;
                    val[orig] = d + sign * val[u];
                }
                mark(orig);
            }
        }
        if(!vis[u]) go(u, d, -sign, orig);
    }
}

int main()
{
    int Q, i, j, a, b, d;
    while(scanf("%d%d", &M, &Q) && M)
    {
        for(i=0;i<m.size();i++)
        {
            grafo[i].clear();
            dep[i][0].clear(); dep[i][1].clear();
        }
        m.clear();
        for(i=0;i<M;i++)
        {
            scanf("%d%d%d", &a, &b, &d);
            a = indice(a); b = indice(b);
            if(a == b) val[a] = d;
            else
            {
                grafo[a].push_back(make_pair(b, d));
                grafo[b].push_back(make_pair(a, d));
            }
        }
        for(i=0;i<m.size();i++) vis[i] = 0;
        for(i=0;i<m.size();i++) if(!vis[i]) go(i, 0, -1, i);
        while(Q--)
        {
            scanf("%d%d", &a, &b);
            if(m.count(a) == 0 || m.count(b) == 0) { printf("*\n"); continue; }
            a = m[a]; b = m[b];
            if(a == b)
            {
                if(val[a] != INF) printf("%d\n", val[a]);
                else printf("*\n");
            }
            else if(val[a] != INF && val[b] != INF) printf("%d\n", val[a] + val[b]);
            else
            {
                if(val[a] != INF) printf("*\n");
                else if(val[b] != INF) printf("*\n");
                else if(pai[a].first != pai[b].first) printf("*\n");
                else if(pai[a].second == pai[b].second) printf("*\n");
                else
                {
                    d = pai[a].first;
                    if(pai[a].second == 1) printf("%d\n", vsoma[a] - vsoma[b]);
                    else printf("%d\n", vsoma[b] - vsoma[a]);
                }
            }
        }
        printf("-\n");
    }
    return 0;
}


