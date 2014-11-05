#include <bits/stdc++.h>
#include <complex>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		double w, h, xp, yp, x0, y0, a, s;
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &w, &h, &x0, &y0, &xp, &yp, &a, &s);

		double xt = xp - x0;
		double yt = yp - y0;

		double xc = xt + w/2;
		double yc = yt + h/2;

		double dx = xc - xp;
		double dy = yc - yp;

		double co = cos(a/180*M_PI);
		double si = sin(a/180*M_PI);
		double dxrot = dx*co - dy*si;
		double dyrot = dx*si + dy*co;
		dxrot *= s;
		dyrot *= s;

		xc = xp + dxrot;
		yc = yp + dyrot;

		xt = xc - w*s/2;
		yt = yc - h*s/2;

		printf(".item%d { width: %.1lfpx; height: %.1lfpx; left: %.1lfpx; top: %.1lfpx; transform: rotate(%.1lfdeg); }\n", i, w*s, h*s, xt, yt, a);
	}
	return 0;
}
