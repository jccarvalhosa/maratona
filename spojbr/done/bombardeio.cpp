#include <cstdio>
#include <cmath>
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
	circ() {}
	circ(pt p, pt q, pt r) {
		pt a=p-r, b=q-r, c=pt(a*(p+r)/2, b*(q+r)/2);
		this->o = pt(c % pt(a.y, b.y), pt(a.x, b.x) % c) / (a%b);
		this->r2 = dist2(p, o);
	}
};

inline bool inside(pt p, circ c) { return cmpD(dist2(c.o, p), c.r2) <= 0; }

pt p[200];

int main() {
	int m, n, i, j, k, l, cont;
	double ans;
	while(scanf("%d%d", &n, &m) && n) {
		for(i=0;i<n;i++) scanf("%lf %lf", &p[i].x, &p[i].y);
		ans=INF;
		for(i=0;i<n;i++) for(j=i+1;j<n;j++) {
			circ c;
			c.o = (p[i]+p[j])/2;
			c.r2 = dist2(c.o, p[i]);
			if(cmpD(c.r2, ans) >= 0) continue;
			cont=2;
			for(k=0;k<n;k++) {
				if(k==i || k==j) continue;
				if(inside(p[k], c)) cont++;
				if(cont >= m) break;
				if(cont + n-k-1 < m) break;
			}
			if(cont >= m) ans = c.r2;
		}
		for(i=0;i<n;i++) for(j=i+1;j<n;j++) for(k=j+1;k<n;k++) if(ccw(p[i], p[j], p[k]) != 0) {
			circ c(p[i], p[j], p[k]);
			if(cmpD(c.r2, ans) >= 0) continue;
			cont=3;
			for(l=0;l<n;l++) {
				if(l==i || l==j || l==k) continue;
				if(inside(p[l], c)) cont++;
				if(cont >= m) break;
				if(cont + n-l-1 < m) break;
			}
			if(cont >= m) ans = c.r2;
		}
		printf("%.3lf\n", sqrt(ans));
	}
	return 0;
}
