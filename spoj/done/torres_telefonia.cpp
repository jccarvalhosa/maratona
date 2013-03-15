#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1e9
#define EPS 1e-9

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

struct pt {
	double x, y;
	pt(double x=0, double y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
	pt operator /(double c) { return pt(x/c, y/c); }
    double operator *(pt p) { return x*p.x + y*p.y; }
    double operator %(pt p) { return x*p.y - y*p.x; }
};

inline double dist2(pt a, pt b) { return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); }
inline int ccw(pt p, pt q, pt r) { return cmpD((p-r) % (q-r)); }

struct circ {
	pt o;
	double r2;
	circ(pt o=pt(), double r2=0): o(o), r2(r2) {}
	circ(pt p, pt q) {
		o = (p+q)/2;
		r2 = dist2(o, p);
	}
	circ(pt p, pt q, pt r) {
		pt a=p-r, b=q-r, c=pt(a*(p+r)/2, b*(q+r)/2);
		o = pt(c % pt(a.y, b.y), pt(a.x, b.x) % c) / (a%b);
		r2 = dist2(p, o);
	}
};

inline bool inside(pt p, circ c) { return cmpD(dist2(c.o, p), c.r2) <= 0; }

circ spanning_circle(vector<pt> v) {
	int i, j, k, n = v.size();
	random_shuffle(v.begin(), v.end());
	circ c;
	for(i=0;i<n;i++) if(!inside(v[i], c)) {
		c = circ(v[i], 0);
		for(j=0;j<i;j++) if(!inside(v[j], c)) {
			c = circ(v[i], v[j]);
			for(k=0;k<j;k++) if(!inside(v[k], c)) {
				c = circ(v[i], v[j], v[k]);
			}
		}
	}
	return c;
}

pt p[40];
vector<pt> v;

int main() {
	int n, i, j, k, l;
	while(scanf("%d", &n) && n) {
		double ans = INF;
		for(i=0;i<n;i++) scanf("%lf %lf", &p[i].x, &p[i].y);
		for(i=0;i<n;i++) for(j=i+1;j<n;j++) {
			circ c(p[i], p[j]);
			if(cmpD(ans, c.r2) <= 0) continue;
			v.clear();
			for(k=0;k<n;k++) if(!inside(p[k], c)) v.push_back(p[k]);
			ans = min(ans, max(c.r2, spanning_circle(v).r2));
		}
		for(i=0;i<n;i++) for(j=i+1;j<n;j++) for(k=j+1;k<n;k++) if(ccw(p[i], p[j], p[k]) != 0) {
			circ c(p[i], p[j], p[k]);
			if(cmpD(ans, c.r2) <= 0) continue;
			v.clear();
			for(l=0;l<n;l++) if(!inside(p[l], c)) v.push_back(p[l]);
			ans = min(ans, max(c.r2, spanning_circle(v).r2));
		}
		printf("%.2lf\n", sqrt(ans));
	}
	return 0;
}
