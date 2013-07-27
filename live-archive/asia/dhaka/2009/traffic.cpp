#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define EPS 1e-6
#define INF 1e9
#define mp make_pair
typedef pair<double, int> pdi;

double cmpD(double a, double b=0) { return a<b+EPS? a<b-EPS ? -1: 0 : 1; }

struct pt {
    double x, y;
    pt(double x=0, double y=0) : x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(double c) { return pt(x*c, y*c); }
    pt operator /(double c) { return pt(x/c, y/c); }
    double operator *(pt p) { return x*p.x+y*p.y; }
    double operator %(pt p) { return x*p.y-y*p.x; }
    int cmp(pt p) const {
        int t=cmpD(x, p.x);
        return t ? t : cmpD(y, p.y);
    }
    bool operator ==(pt p) { return cmp(p)==0; }
    bool operator !=(pt p) { return cmp(p)!=0; }
    bool operator <(const pt &p)const { return cmp(p)<0; }
    bool operator >(const pt &p)const { return cmp(p)>0; }
    bool operator <=(const pt &p)const { return cmp(p)<=0; }
    bool operator >=(const pt &p)const { return cmp(p)>=0; }

    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }
    
    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
};

typedef pair<pt, pt> seg;

pt project(pt a, pt b) { return b*((a*b)/(b*b)); }
double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }

seg angle_intersect(pt p, double teta, pt a, pt b) {
	pt pp = a + project(p-a, b-a);
	double d = abs(p, pp);
	double x = d / tan(teta);
	pt u = (b-a)/abs(b-a);
	return mp(pp-u*x, pp+u*x);
}

pt p[1111];
int m, vis[1111];
double adj[1111][1111];
double d[1111];

void dijkstra() {
	for(int i=0;i<m;i++) {
		d[i]=INF;
		vis[i]=0;
	}
	d[0]=0;
	priority_queue<pdi> q;
	q.push(pdi(-d[0], 0));
	while(!q.empty()) {
		int v=q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(int u=0;u<m;u++) {
			if(d[u]>d[v]+adj[v][u]) {
				d[u] = d[v]+adj[v][u];
				q.push(pdi(-d[u], u));
			}
		}
	}
}

int main() {
	int n, T=1;
	double f;
	while(1) {
		cin>>n>>f;
		if(n==0) break;
		n++;
		for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
		m=n;
		for(int i=0;i<n-1;i++) for(int j=0;j<n;j++) {
			seg s = angle_intersect(p[j], acos(-1.0/f), p[i], p[i+1]);
			if(s.first.between(p[i], p[i+1])) p[m++] = s.first;
			if(s.second.between(p[i], p[i+1])) p[m++] = s.second;
		}
		for(int i=0;i<m;i++) for(int j=0;j<m;j++) {
			adj[i][j] = abs(p[i], p[j]);
			int flag=0;
			for(int k=0;k<n-1;k++) if(p[i].between(p[k], p[k+1]) && p[j].between(p[k], p[k+1])) {
				if(abs(p[k], p[i]) < abs(p[k], p[j])) flag=1;
			}
			if(!flag) adj[i][j] *= f;
		}
		dijkstra();
		printf("Case %d: %.9lf\n", T++, d[n-1]);
	}
	return 0;
}
