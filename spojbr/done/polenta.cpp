#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#define pb push_back
#define mp make_pair
#define sz size()
#define fori(i, n) for(int i=0;i<(n);i++)
#define MAX 10005
#define MAXN 1005

using namespace std;

typedef pair<int, int> pii;

int G[MAXN][MAXN][2], vis[MAXN][MAXN];
int tx, ty;
int minx[MAXN*MAXN], maxx[MAXN*MAXN], miny[MAXN*MAXN], maxy[MAXN*MAXN], area[MAXN*MAXN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pii q[MAXN*MAXN];

void bfs(int a, int b, int cc) {
    int na, nb, ca, cb, ini=0, fim=0;
    q[fim++] = mp(a, b);
    vis[a][b]=cc;
    while(ini!=fim) {
        a = q[ini].first;
        b = q[ini++].second;
        fori(i, 4) {
            na = a+dx[i];
            nb = b+dy[i];
            if(na<0 || nb<0 || na>tx || nb>ty || vis[na][nb]) continue;
            if(i<2) ca=na, cb=nb;
            else ca=a, cb=b;
            if(!G[ca][cb][i%2]) {
                q[fim++] = mp(na, nb);
                vis[na][nb] = cc;
            }
        }
    }
}

int main()
{
    int N, x, y, nx, ny, resp=0, cc=1;
    bool ux[MAX], uy[MAX];
    int idx[MAX], idy[MAX], vx[MAXN], vy[MAXN];
    scanf("%d", &N);
    memset(ux, 0, sizeof(ux));
    memset(uy, 0, sizeof(uy));
    memset(G, 0 ,sizeof(G));
    memset(vis, 0 ,sizeof(vis));
    vector<pii> v;
    fori(i, N) {
        scanf("%d%d", &x, &y);
        ux[x]=1; uy[y]=1;
        v.pb(mp(x,y));
    }
    tx=ty=1;
    fori(i, MAX) {
        if(ux[i]) idx[i]=tx++;
        if(uy[i]) idy[i]=ty++;
    }
    fori(i, N) {
        x = idx[v[i].first];
        y = idy[v[i].second];
        nx = idx[v[(i+1)%N].first];
        ny = idy[v[(i+1)%N].second];
        if(nx == x) { for(int j=min(y, ny);j<max(y, ny);j++) G[x][j][0]=1; }
        else { for(int j=min(x, nx);j<max(x, nx);j++) G[j][y][1]=1; }
    }
    bfs(tx, ty, cc++);
    fori(i, tx) fori(j, ty) if(!vis[i][j]) bfs(i, j, cc++);
    for(int i=1;i<cc;i++) {
        area[i] = 0;
        minx[i] = miny[i] = MAX;
        maxx[i] = maxy[i] = 0;
    }
    fori(i, tx+1) fori(j, ty+1) {
        int c = vis[i][j];
        area[c]++;
        minx[c] = min(minx[c], i);
        maxx[c] = max(maxx[c], i);
        miny[c] = min(miny[c], j);
        maxy[c] = max(maxy[c], j);
    }
    for(int i=2;i<cc;i++) if((maxx[i]-minx[i]+1)*(maxy[i]-miny[i]+1) == area[i]) resp++;
    printf("%d", resp);
    return 0;
}
