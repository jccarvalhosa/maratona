#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#define EPS 1e-12
using namespace std;
const double PI = acos(-1);
double A, B;

double dist(double x, double y, double dx, double dy) {
	double a = dx*dx/A/A + dy*dy/B/B;
	double b = 2*x*dx/A/A + 2*y*dy/B/B;
	double c = x*x/A/A + y*y/B/B - 1;
	double delta = sqrt(b*b - 4*a*c);
	return max((-b + delta)/(2*a), (-b - delta)/(2*a));
}

struct pt {
	double x, y;
	pt(double x=0, double y=0): x(x), y(y) {}
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(double c) { return pt(x*c, y*c); }
    double operator *(pt p) { return x*p.x + y*p.y; }
};

pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

pt reflect(pt p, pt v) {
	pt px = project(p, v);
	pt py = p - px;
	return px - py;
}

int main() {
	double x, y, dx, dy;
	while(scanf("%lf", &x) != EOF) {
		cin>>y>>dx>>dy>>A>>B;
		double t = dist(x, y, dx, dy);
		double cx = x+t*dx;
		double cy = y+t*dy;
		printf("%.3lf %.3lf\n", cx+EPS, cy+EPS);
		pt tg = pt(-A*A*cy, B*B*cx);
		pt d = reflect(pt(dx, dy), tg);
		t = dist(cx, cy, d.x, d.y);
		printf("%.3lf %.3lf\n", cx+t*d.x+EPS, cy+t*d.y+EPS);
	}
	return 0;
}
