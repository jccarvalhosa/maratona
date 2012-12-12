#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define sz size()
#define MID 5000

using namespace std;

int G[8000][8000][2];

struct cut {
    int x1, y1, x2, y2;
    cut() {}
    cut(int a, int b, int c, int d): x1(a), y1(b), x2(c), y2(d) {
        if(x1 == x2 && y1 > y2) swap(y1, y2);
        if(y1 == y2 && x1 > x2) swap(x1, x2);
    }
};

int lt(cut a, cut b) {
    if(a.x1 < b.x1) return 1;
    if(a.x1 > b.x1) return 0;
    if(a.y1 < b.y1) return 1;
    return 0;
}

vector<cut> merge_sort(int xmin, int ymin, int xmax, int ymax) {
    int i, j;
    int besty = ymax, bestx = xmax;
    for(i=ymin+1;i<ymax;i++) {
        for(j=xmin;j<xmax;j++) if(!G[j][i][1]) break;
        if(j == xmax) break;
    }
    if(i != ymax) besty = i;
    else {
        for(i=xmin+1;i<xmax;i++) {
            for(j=ymin;j<ymax;j++) if(!G[i][j][0]) break;
            if(j == ymax) break;
        }
        if(i != xmax) bestx = i;
    }
    vector<cut> vr, vl, vf;
    if(besty != ymax) {
        vf.pb(cut(xmin, besty, xmax, besty));
        vl = merge_sort(xmin, ymin, xmax, besty);
        vr = merge_sort(xmin, besty, xmax, ymax);
    }
    else if(bestx != xmax) {
        vf.pb(cut(bestx, ymin, bestx, ymax));
        vl = merge_sort(xmin, ymin, bestx, ymax);
        vr = merge_sort(bestx, ymin, xmax, ymax);
    }
    else return vf;
    i=j=0;
    while(i!=vl.sz && j != vr.sz) {
        if(lt(vl[i], vr[j])) vf.pb(vl[i++]);
        else vf.pb(vr[j++]);
    }
    while(i!=vl.sz) vf.pb(vl[i++]);
    while(j!=vr.sz) vf.pb(vr[j++]);
    return vf;
}

int idx[10001], idy[10001], vx[8000], vy[8000], tx, ty;

int main()
{
    int N, i, j, x1, y1, x2, y2;
    while(scanf("%d", &N) && N) {
        memset(idx, 0, sizeof(idx));
        memset(idy, 0, sizeof(idy));
        vector<cut> c, r;
        for(i=0;i<N;i++) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1 += MID; y1 += MID; x2 += MID; y2 += MID;
            idx[x1] = idy[y1] = idx[x2] = idy[y2] = 1;
            r.pb(cut(x1, y1, x2, y2));
        }
        tx=ty=0;
        for(i=0;i<10001;i++) if(idx[i]) {
            idx[i] = tx;
            vx[tx++] = i-MID;
        }
        for(i=0;i<10001;i++) if(idy[i]) {
            idy[i] = ty;
            vy[ty++] = i-MID;
        }
        for(i=0;i<ty;i++) for(j=0;j<tx;j++) G[i][j][0] = G[i][j][1] = 0;
        for(i=0;i<r.sz;i++) {
            for(j=idy[r[i].y1];j<idy[r[i].y2];j++) G[idx[r[i].x1]][j][0] = G[idx[r[i].x2]][j][0] = 1;
            for(j=idx[r[i].x1];j<idx[r[i].x2];j++) G[j][idy[r[i].y1]][1] = G[j][idy[r[i].y2]][1] = 1;
        }
        c = merge_sort(0, 0, tx-1, ty-1);
        for(i=0;i<c.sz;i++) printf("%d %d %d %d\n", vx[c[i].x1], vy[c[i].y1], vx[c[i].x2], vy[c[i].y2]);
        printf("\n");
    }
}
