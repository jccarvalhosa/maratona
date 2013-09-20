#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define EPS 1e-6
#define INF 1e9

using namespace std;

int cmpD(double x, double y=0, double tol=EPS) { return (x<=y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

struct pt {
	double x, y;
	pt(double x=0,double y=0): x(x), y(y) {}
	pt operator +(pt p) {return pt(x+p.x, y+p.y);}
	pt operator -(pt p) {return pt(x-p.x, y-p.y);}
	pt operator *(double c) {return pt(x*c,y*c);}
	pt operator /(double c) {return pt(x/c,y/c);}
	double operator *(pt p) {return x*p.x+y*p.y;}
	double operator %(pt p) {return x*p.y-y*p.x;}
	int cmp(pt p) const {
		int t=cmpD(x,p.x);
		return t ? t : cmpD(y,p.y);
	}
	bool operator ==(pt p) { return cmp(p) == 0; }
	bool operator !=(pt p) { return cmp(p) != 0; }
	bool operator <(const pt &p)const { return cmp(p) < 0; }
	bool operator >(const pt &p)const { return cmp(p) > 0; }
	bool operator <=(const pt &p)const { return cmp(p) <= 0; }
	bool operator >=(const pt &p)const { return cmp(p) >= 0; }
	int prod(pt p, pt q) { return cmpD((*this-p)%(q-p)); }
	bool between(pt p, pt q) { return prod(p,q) == 0 && min(p,q) <= *this && *this <= max(p,q); }
	bool left(pt p, pt q) { return prod(p,q) < 0; }
	bool right(pt p, pt q) { return prod(p,q) > 0; }
};

pt line_intersect(pt p, pt q, pt r, pt s)
{
	pt a=q-p, b = s-r, c(p%q, r%s);
	if(cmpD(a%b)==0) return pt(INF,INF);
	return pt(pt(a.x,b.x)%c, pt(a.y,b.y)%c)/(a%b);
}

bool seg_intersect(pt p, pt q, pt r, pt s)
{
	if(r.between(p,q) || s.between(p,q) || p.between(r,s) || q.between(r,s)) return true;
	pt a = line_intersect(p,q,r,s);
	return a.between(p,q) && a.between(r,s);
}

int main()
{
	pt a, b, c, d;
	int i=1;
	while(scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y) && a.x)
	{
		scanf("%lf%lf%lf%lf", &c.x, &c.y, &d.x, &d.y);
		cout << "Case " << i++ << ": ";
		if(!seg_intersect(a,b,c,d)) printf("%.3lf\n", hypot(a.x-b.x, a.y-b.y)/2);
		else  printf("%.3lf\n", min(hypot(a.x-c.x,a.y-c.y)+hypot(b.x-c.x,b.y-c.y),hypot(a.x-d.x,a.y-d.y)+hypot(b.x-d.x,b.y-d.y))/2);

	}
	return 0;
}
