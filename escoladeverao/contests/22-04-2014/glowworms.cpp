#include <iostream>
#include <cstdio>
using namespace std;

int n;
const int N=1e5+10;
double x[N], y[N], a[N], b[N];

double cima(double t) {
	double ans = -1e15;
	for(int i=0;i<n;i++) ans = max(ans, y[i] + t*b[i]);
	return ans;
}

double baixo(double t) {
	double ans = 1e15;
	for(int i=0;i<n;i++) ans = min(ans, y[i] + t*b[i]);
	return ans;
}

double dir(double t) {
	double ans = -1e15;
	for(int i=0;i<n;i++) ans = max(ans, x[i] + t*a[i]);
	return ans;
}

double esq(double t) {
	double ans = 1e15;
	for(int i=0;i<n;i++) ans = min(ans, x[i] + t*a[i]);
	return ans;
}

double side(double t) { return max(cima(t) - baixo(t), dir(t) - esq(t)); }

double solve() {
	int nmi = 200;
	int it=0;
	double l=0, r=1e9;
	while(r-l > 1e-9 && it<nmi) {
		double d = (r-l)/3;
		double m1 = l + d;
		double m2 = l + 2*d;
		if(side(m1) < side(m2)) r = m2-1e-9;
		else l = m1+1e-9;
		it++;
	}
	return side((l+r)/2);
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) scanf("%lf%lf%lf%lf", &x[i], &y[i], &a[i], &b[i]);
	printf("%.12lf\n", solve());
	return 0;
}
