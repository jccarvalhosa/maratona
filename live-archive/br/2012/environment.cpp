#include <cstdio>
#include <algorithm>
using namespace std;
#define EPS 1e-7

int K;
double W, D, A, fn[10], fd[10], gn[10], gd[10], exp[10];

double val(double *pn, double *pd, double x, double m) {
	double num=0, den=0;
	int i;
	if(x < EPS) return pn[0] / pd[0];
	exp[0] = 1;
	for(i=1;i<=K;i++) exp[i] = x*exp[i-1];
	for(i=0;i<=K;i++) num += pn[i] / exp[K-i];
	for(i=0;i<=K;i++) den += pd[i] / exp[K-i];
	return max(num/den - m, 0.0);
}

double area(double m) {
	double sum=0, x, nx, delta=1e-3;
	for(x=0;x<=W;x+=delta) {
		nx = min(x+delta, W);
		sum += (nx-x)*val(fn, fd, (x+nx)/2, m);
		sum -= (nx-x)*val(gn, gd, (x+nx)/2, m);
	}
	return sum;
}

double binary_search(double i, double f, double key) {
	double m;
	while(f-i > EPS) {
		m = (f+i)/2;
		if(area(m) > key) i = m;
		else f = m;
	}
	return -m;
}

int main() {
	int i;
	while(scanf("%lf%lf%lf%d", &W, &D, &A, &K) != EOF) {
		for(i=0;i<=K;i++) scanf("%lf", &fn[i]);
		for(i=0;i<=K;i++) scanf("%lf", &fd[i]);
		for(i=0;i<=K;i++) scanf("%lf", &gn[i]);
		for(i=0;i<=K;i++) scanf("%lf", &gd[i]);
		printf("%.5lf\n", binary_search(-D, 0, A));
	}
	return 0;
}
