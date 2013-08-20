#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#define EPS 1e-12
using namespace std;
const double PI = acos(-1);

struct pt {
	double x, y;
	pt(double x=0, double y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(double c) { return pt(x*c, y*c); }
    double operator *(pt p) { return x*p.x + y*p.y; }
};

pt ellipse_hit(pt p, pt d, double A, double B) {
	double a = d.x*d.x/A/A + d.y*d.y/B/B;
	double b = 2*p.x*d.x/A/A + 2*p.y*d.y/B/B;
	double c = p.x*p.x/A/A + p.y*p.y/B/B - 1;
	double delta = sqrt(b*b - 4*a*c);
	double t1 = (-b + delta)/2/a; 
	double t2 = (-b - delta)/2/a;
	return p + d*max(t1, t2);
}

pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

pt reflect(pt p, pt v) {
	pt px = project(p, v);
	pt py = p - px;
	return px - py;
}

int main() {
	pt p, d;
	double a, b;
	while(scanf("%lf", &p.x) != EOF) {
		cin>>p.y>>d.x>>d.y>>a>>b;
		p = ellipse_hit(p, d, a, b);
		printf("%.3lf %.3lf\n", p.x+EPS, p.y+EPS);
		pt tg = pt(-a*a*p.y, b*b*p.x);
		d = reflect(d, tg);
		p = ellipse_hit(p, d, a, b);
		printf("%.3lf %.3lf\n", p.x+EPS, p.y+EPS);
	}
	return 0;
}
