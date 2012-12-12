#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define fori(i, n) for(int i=0;i<(n);i++)
#define sz size()
#define pb push_back
#define mp make_pair
#define SUM 501
#define MAX 1003

typedef pair<int, int> pii;

int minx, miny, maxx, maxy;

struct segment {
    int x1, x2, y1, y2;
    segment(int a, int b, int c, int d) : x1(SUM+a), y1(SUM+b), x2(SUM+c), y2(SUM+d) { 
        if(x1 != x2 && x1 > x2) swap(x1, x2);
        if(y1 != y2 && y1 > y2) swap(y1, y2);
    }
};

int G[MAX][MAX][2], vis[MAX][MAX];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pii q[MAX*MAX];

void bfs(int a, int b){
    int na, nb, ca, cb, ini=0, fim=0;
    q[fim++] = mp(a, b);
    vis[a][b]=1;
    while(ini!=fim) {
        a = q[ini].first;
        b = q[ini++].second;
        fori(i, 4) {
            na = a+dx[i];
            nb = b+dy[i];
            if(na<minx || nb<miny || na>=maxx || nb>=maxy || vis[na][nb]) continue;
            if(i<2) ca=na, cb=nb;
            else ca=a, cb=b;
            if(!G[ca][cb][i%2]) {
                q[fim++] = mp(na, nb);
                vis[na][nb] = 1;
            }
        }
    }
}

int main()
{
    vector<segment> v, u;
    int N, W, w[2000], x1, y1, x2, y2;
    while(scanf("%d", &N) && N) {
        v.clear(); u.clear();
        minx=miny=MAX-1;
        maxx=maxy=0;
        fori(i, N) {
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &w[i]);
            u.pb(segment(x1, y1, x2, y2));
        }
        scanf("%d", &W);
        fori(i, N) if(w[i] >= W) v.pb(u[i]);
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        fori(i, v.sz) {
            if(v[i].x1 == v[i].x2) { for(int j=v[i].y1;j<v[i].y2;j++) G[v[i].x1][j][0]=1; }
            else for(int j=v[i].x1;j<v[i].x2;j++) G[j][v[i].y1][1]=1;
            minx = min(minx, v[i].x1-1);
            maxx = max(maxx, v[i].x2+1);
            miny = min(miny, v[i].y1-1);
            maxy = max(maxy, v[i].y2+1);
        }
        bfs(minx, miny);
        int resp=0;
        for(int i=minx+1;i<maxx;i++) for(int j=miny+1;j<maxy;j++) if(!vis[i][j]) resp++;
        printf("%d\n", resp);
    }
    return 0;
}
