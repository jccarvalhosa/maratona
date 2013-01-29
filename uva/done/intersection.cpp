#include <cstdio>
#include <vector>
using namespace std;
#define EPS 1e-3
#define INF 1e9
#define sz size()

int cmpD(double x, double y=0) { return x <= y+EPS ? x < y-EPS ? -1 : 0 : 1; }

struct pt {
	double x, y;
	pt(double x=0, double y=0): x(x), y(y) {}
	pt operator -(pt p) { return pt(x-p.x, y-p.y); }
	pt operator /(double c) { return pt(x/c, y/c); }
	double operator %(pt p) { return x*p.y - y*p.x; }
	int cmp(pt p) const {
		int t = cmpD(x, p.x);
		return t ? t : cmpD(y, p.y);
	}
	bool operator <(const pt &p)const { return cmp(p) < 0; }
	bool operator <=(const pt &p)const { return cmp(p) <= 0; }
	int prod (pt p, pt q) { return cmpD((*this-p) % (q-p)); }
	bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
	bool left(pt p, pt q) { return prod(p, q) < 0; }
};

pt line_intersect(pt p, pt q, pt r, pt s) {
	pt a=q-p, b=s-r, c(p%q, r%s);
	if(cmpD(a%b) == 0) return pt(INF, INF);
	return pt(pt(a.x, b.x) % c, pt(a.y, b.y) % c) / (a%b);
}

bool seg_intersect(pt p, pt q, pt r, pt s) {
	if(r.between(p, q) || s.between(p, q) || p.between(r, s) || q.between(r, s)) return true;
	pt a = line_intersect(p, q, r, s);
	return a.between(p, q) && a.between(r, s);
}

typedef vector<pt> polygon;

int in_convex_poly(pt p, polygon T) {
	for(int i=0; i<T.size();i++) if(p.between(T[i], T[(i+1) % T.size()])) return -1;
	for(int i=0; i<T.size();i++) if(!p.left(T[i], T[(i+1) % T.size()])) return 0;
	return 1;
}

int main() {
	vector<pt> T(4);
	pt a, b;
	double x, X, y, Y;
	int n, i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &x, &Y, &X, &y);
		T[0] = pt(x, y);
		T[1] = pt(X, y);
		T[2] = pt(X, Y);
		T[3] = pt(x, Y);
		if(in_convex_poly(a, T)) printf("T\n");
		else {
			for(j=0;j<4;j++) if(seg_intersect(a, b, T[j], T[(j+1)%4])) break;
			if(j != 4) printf("T\n");
			else printf("F\n");
		}
	}
	return 0;
}
