#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, unsigned long long> > adj[100000];
unsigned long long d[100000];
int pai[100000], pos[100000];

void go(int v, int p, unsigned long long s)
{
    int i, u, a;
    if(p == -1) pos[v] = 0;
    else pos[v] = pos[p] + 1;
    d[v] = s; pai[v] = p;
    for(i=0;i<adj[v].size();i++)
    {
        u = adj[v][i].first;
        a = adj[v][i].second;
        if(d[u] == -1) go(u, v, s+a);
    }
}

int inter(int a, int b)
{
    if(a == b) return a;
    if(pos[a] > pos[b]) return inter(pai[a], b);
    return inter(a, pai[b]);
}

int main()
{
    int N, Q, i, a, b;
    while(scanf("%d", &N) && N)
    {
        for(i=0;i<N;i++) adj[i].clear();
        for(i=1;i<=N-1;i++)
        {
            scanf("%d%d", &a, &b);
            adj[i].push_back(make_pair(a, b));
            adj[a].push_back(make_pair(i, b));
        }
        for(i=0;i<N;i++) d[i] = -1;
        go(0, -1, 0);
        scanf("%d", &Q);
        while(Q--)
        {
            scanf("%d%d", &a, &b);
            printf("%llu ", d[a] + d[b] - 2*d[inter(a, b)]);
        }
        printf("\n");
    }
    return 0;
}
