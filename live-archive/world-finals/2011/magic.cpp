#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int v[555], mi;

int valid1(int a, int b, double r) {
	double sum=0;
	for(int i=a;i<=b;i++) {
		if(v[i] > 2*r) return 0;
		sum += asin(v[i]/(2*r));
	}
	return sum <= M_PI;
}

int valid2(int a, int b, double r) {
	double sum=0;
	for(int i=a;i<=b;i++) {
		double teta = asin(v[i]/(2*r));
		if(i == mi) sum += M_PI - teta;
		else sum += teta;
	}
	return sum <= M_PI;
}

double area(int a, int b) {
	int m=0, sum=0;
	mi=a;
	for(int i=a;i<=b;i++) {
		if(v[i] > m) {
			m = v[i];
			mi = i;
		}
		sum += v[i];
	}
	if(m >= sum-m) return 0;
	if(valid1(a, b, m/2.0)) {
		double i=m/2.0, f=1e6;
		for(int t=0;t<200;t++) {
			double r = (i+f)/2;
			if(valid2(a, b, r)) i=r;
			else f=r;
		}
		double s=0;
		for(int i=a;i<=b;i++) {
			double st = v[i] * sqrt(f*f - v[i]*v[i]/4.0) / 2;
			if(i == mi) s -= st;
			else s += st;
		}
		return s;
	}
	double i=0, f=1e6;
	for(int t=0;t<200;t++) {
		double r = (i+f)/2;
		if(valid1(a, b, r)) f=r;
		else i=r;
	}
	double s=0;
	for(int i=a;i<=b;i++) s += v[i] * sqrt(f*f - v[i]*v[i]/4.0) / 2;
	return s;
}

double solve(int a, int b) {
	if(b-a <= 1) return 0;
	double s = area(a, b);
	return max(s,solve(a,mi-1)+solve(mi+1,b));
}

int main() {
	int n, t=1;
	while(cin>>n && n) {
		for(int i=0;i<n;i++) cin>>v[i];
		printf("Case %d: %.9lf\n", t++, solve(0, n-1));
	}
	return 0;
}
