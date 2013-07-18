#include <complex>
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef complex<double> pt;
#define x real()
#define y imag()

int main() {
	pt a, b, c;
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	pt sum = a+b+c;
	pt G = sum/pt(3, 0);
	pt Mab = (a+b)/pt(2, 0);
	pt prod = a*b + a*c + b*c;
	pt delta = sum*sum - pt(3, 0)*prod;
	pt f1 = (sum + sqrt(delta)) / pt(3, 0);
	pt f2 = (sum - sqrt(delta)) / pt(3, 0);
	pt F1 = G + (f1-G) * pt(2, 0);
	pt F2 = G + (f2-G) * pt(2, 0);
	printf("%.5lf %.5lf %.5lf %.5lf %.5lf\n", F1.x, F1.y, F2.x, F2.y, sqrt(norm(F1-a)) + sqrt(norm(F2-a)));
	printf("%.5lf %.5lf %.5lf %.5lf %.5lf\n", f1.x, f1.y, f2.x, f2.y, sqrt(norm(f1-Mab)) + sqrt(norm(f2-Mab)));
	return 0;
}
