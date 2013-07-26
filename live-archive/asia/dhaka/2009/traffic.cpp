#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define EPS 1e-6
#define INF 1e9
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

pt project(pt a, pt b) { return b*((a*b)/(b*b)); }
double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }

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
			pt a = p[i];
			pt b = p[i+1];
			if(a>b) swap(a, b);
			pt pp = a + project(p[j]-a, b-a);
			double d = abs(p[j], pp);
			pt u = (b-a)/abs(b-a);
			double x = d / tan(acos(-1.0/f));
			pt p1 = pp + u*x;
			if(p1>a && p1<b) p[m++] = p1;
			pt p2 = pp - u*x;
			if(p2>a && p2<b) p[m++] = p2;
		}
		for(int i=0;i<m;i++) for(int j=0;j<m;j++) {
			adj[i][j] = abs(p[i], p[j]);
			int flag=0;
			for(int k=0;k<n-1;k++) 
				if(p[i].between(p[k], p[k+1]) && p[j].between(p[k], p[k+1])) 
					if(abs(p[k], p[i]) < abs(p[k], p[j])) 
						flag=1;
			if(!flag) adj[i][j] *= f;
		}
		dijkstra();
		cout<<"Case "<<T++<<": ";
		printf("%.9lf\n", d[n-1]);
	}
	return 0;
}
