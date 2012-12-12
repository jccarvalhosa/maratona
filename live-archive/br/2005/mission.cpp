#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb push_back
#define mp make_pair
#define sz size()
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

struct pt {
	int x, y, r;
	pt(int x=0, int y=0): x(x),y(y) {}
} I[1000], R[30], T[1000];

vector<pii> edge;
typedef vector<pt> polygon;

int dep, M;
int pai[30], vis[30], valid[1000];

int abs2(pt a, pt b) { return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); }
double abs2(double x, double y) { return x*x+y*y; }
bool ccw(pt A, pt B, pt C) { return ((C.y-A.y)*(B.x-A.x) > (B.y-A.y)*(C.x-A.x)); }
bool inter(pt A, pt B, pt C, pt D) { return (ccw(A,C,D) != ccw(B,C,D) && ccw(A,B,C) != ccw(A,B,D)); }

int in_poly(pt X, polygon P) {
	int n = 0;
	pt ref = pt(2000,2000);
	for(int i=0;i<P.sz;i++) n += inter(P[i], P[(i+1)%P.sz], X, ref);
	return n % 2;
}

double dist_pt_seg(pt C, pt A, pt B) {
	pt V = pt(B.x-A.x,B.y-A.y);
    double d, d1, d2, u, xx, yy;
	d = abs2(A,B);
	u = ((C.x-A.x)*(B.x-A.x)+(C.y-A.y)*(B.y-A.y))/d;
	xx = (A.x + u*V.x);
    yy = (A.y + u*V.y);
    d1 = abs2(xx-A.x, yy-A.y);
    d2 = abs2(xx-B.x, yy-B.y);
	if(d1 > d) return abs2(B,C);
	if(d2 > d) return abs2(A,C);
	return abs2(C.x-xx, C.y-yy);
}

void dfs(int v, int p) {
	vis[v] = ++dep;
	pai[v] = p;
	for(int u=0;u<M;u++) if(u != p && u != v) {
		int rsum = R[v].r + R[u].r;
		if(abs2(R[v],R[u]) < rsum*rsum) {
            if(!vis[u]) dfs(u, v);
            else if(vis[u] < vis[v]) edge.pb(mp(u,v));
        }
	}
}

int main(void) {
	int i, j, B, N;
	while(scanf("%d",&B) && B) {
		for(i=0;i<B;i++) scanf("%d%d", &T[i].x, &T[i].y);
		scanf("%d",&N);
		for(i=0;i<N;i++) scanf("%d%d", &I[i].x, &I[i].y);
		scanf("%d",&M);
		for(i=0;i<M;i++) scanf("%d%d%d", &R[i].x, &R[i].y, &R[i].r);
        memset(vis, 0, sizeof(vis));
        //elimina informantes dentro dos radares
		for(i=0;i<N;i++) {
            valid[i] = 1;
            for(j=0;j<M;j++) if(abs2(I[i],R[j]) <= R[j].r*R[j].r) valid[i] = 0;
        }
        //elimina informantes dentro dos poligonos
        //acha os poligonos fazendo um dfs para encontrar ciclos
        edge.clear();
        for(i=0;i<M;i++) if(!vis[i]) dep=0, dfs(i, -1);
        for(i=0;i<edge.sz;i++) {
            polygon pol;
            for(j=edge[i].second; j != edge[i].first; j=pai[j]) pol.pb(pt(R[j].x,R[j].y));
            pol.pb(pt(R[j].x,R[j].y));
            for(j=0;j<N;j++) if(valid[j] && in_poly(I[j], pol)) valid[j] = 0;
        }
        int besti = 0;
        double dmin, gmin=0;
        for(i=0;i<N;i++) if(valid[i]) {
            dmin = INF;
            for(j=0;j<B;j++) dmin = min(dmin, dist_pt_seg(I[i], T[j], T[(j+1)%B]));
            if(dmin > gmin) gmin = dmin, besti = i+1;
        }
        if(besti) printf("Contact informer %d\n", besti);
		else printf("Mission impossible\n");
	}
	return 0;
}
