#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, pii> pdp;

int n, m;
int srcx, srcy, destx, desty;
double l, dist;
char g[111][111];
double d[111][111];
int vis[111][111];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

void dijkstra() {
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) d[i][j] = 1e9;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j]=0;
    d[srcx][srcy] = 0;
    priority_queue<pdp> q;
    q.push(pdp(0, pii(srcx, srcy)));
    while(!q.empty()) {
        pdp p = q.top();
        q.pop();
        int x = p.second.first;
        int y = p.second.second;
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        for(int i=0;i<4;i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            double delta=1;
            if(dx[i]) delta=dist/100.0;
            if(nx<0||nx>=n||ny<0||ny>=m || g[nx][ny]=='#') continue;
            if(d[nx][ny]>d[x][y]+delta) {
                d[nx][ny] = d[x][y] + delta;
                q.push(pdp(-d[nx][ny], pii(nx, ny)));
            }
        }
    }
}

double bin_search(double i, double f) {
    while(1) {
        dist = (i+f)/2;
        dijkstra();
        if(fabs(d[destx][desty] - l) < 0.000001) return dist;
        if(d[destx][desty] > l) f = dist;
        else i = dist;
    }
}

int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>l>>n;
        for(int i=0;i<n;i++) scanf(" %[^\n] ", g[i]);
        m = strlen(g[0])-1;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
            if(g[i][j] == 'S') srcx = i, srcy=j;
            if(g[i][j] == 'E') destx = i, desty=j;
        }
        printf("Case #%d: %.3lf%%\n", t, bin_search(0, 1000));
    }
    return 0;
}
