#include <stdio.h>
#include <queue>
#define INF 1000000000

using namespace std;

int g[1000][1000], d[1000][1000], vis[1000][1000];
int C, R, ci, ri, cf, rf, cont=0;

int mod(int a) { return a > 0 ? a : -a; }

void shortest_path()
{
    int r, c, i, j, delta;
    priority_queue<pair<int, pair<int, int> > > q;
    for(i=0;i<R;i++) for(j=0;j<C;j++)
    {
        d[i][j] = INF;
        vis[i][j] = 0;
    }
    d[ri][ci] = 0;
    q.push(make_pair(0, make_pair(ri, ci)));
    while(!q.empty())
    {
        r = q.top().second.first;
        c = q.top().second.second;
        q.pop();
        if(vis[r][c]) continue;
        vis[r][c] = 1;
        if(r == rf && c == cf) return;
        for(i=-1;i<=1;i++) for(j=-1;j<=1;j++)
        {
            if(r+i<0 || r+i>=R || c+j<0 || c+j>=C) continue;
            delta = 2+mod(i*j);
            if(!g[r][c] && !g[r+i][c+j]) continue;
            if(!g[r][c] && g[r+i][c+j]) delta++;
            if(d[r+i][c+j] > d[r][c] + delta)
            {
                d[r+i][c+j] = d[r][c] + delta;
                q.push(make_pair(-d[r+i][c+j], make_pair(r+i, c+j)));
            }
        }
    }
}

int main()
{
    int w, c1, r1, c2, r2, i, j;
    while(scanf("%d%d", &C, &R) && C)
    {
        for(i=0;i<R;i++) for(j=0;j<C;j++) g[i][j] = 1;
        scanf("%d%d%d%d", &ci, &ri, &cf, &rf);
        ci--; ri--; cf--; rf--;
        scanf("%d", &w);
        while(w--)
        {
            scanf("%d%d%d%d", &c1, &r1, &c2, &r2);
            for(i=r1-1;i<=r2-1;i++) for(j=c1-1;j<=c2-1;j++) g[i][j] = 0; 
        }
        shortest_path();
        if(d[rf][cf] == INF) printf("impossible\n");
        else printf("%d\n", d[rf][cf]);
    }
    return 0;
}

