#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#define mod(a) a > 0 ? a : -a
using namespace std;
const double PI = 2*acos(0);

struct pt {
    double x, y;
    pt(double x=0, double y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    double operator *(pt p) { return x*p.x + y*p.y; }
    double operator %(pt p) { return x*p.y - y*p.x; }
};

double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }

double angle(pt p, pt q, pt r) { pt u=p-q, v=r-q; return atan2(u % v, u * v); }

int main() {
	pt a, b;
	cin>>a.x>>a.y>>b.x>>b.y;
	double r1 = abs(a);
	double r2 = abs(b);
	if(r1 > r2) swap(r1, r2);
	double delta = mod(angle(a, pt(), b));
	printf("%.9lf\n", min(2.0, delta)*r1 + r2-r1);
	return 0;
}
