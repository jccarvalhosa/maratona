#include <cstdio>
#include <algorithm>
#define EPS 1e-30
using namespace std;
typedef long double ld;

int n;
ld a[1111111];

ld f1(ld x) {
	ld ret=1e18;
	for(int i=0; i<n; i++) ret=min(ret, a[i]-i*x);
	return ret;
}

ld f2(ld x) {
	ld ret=-1e18;
	for(int i=0; i<n; i++) ret=max(ret, a[i]-(i+1)*x);
	return ret;
}

ld f(ld x) { return f1(x)-f2(x); }

int main() {
	int i;
	ld lo=0, hi=1e10, mid, low, high;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%Lf", &a[i]);
	for(i=0; i<100; i++) {
		ld p1=(2*lo+hi)/3;
		ld p2=(lo+2*hi)/3;
		if(f(p1)<f(p2)) lo=p1+EPS;
		else hi=p2-EPS;
	}
	ld _max=(lo+hi)/2;
	lo=0, hi=_max;
	for(i=0; i<100; i++) {
		mid=(lo+hi)/2;
		if(f(mid)<EPS) lo=mid+EPS;
		else hi=mid-EPS;
	}
	low=mid;
	lo=_max, hi=1e10;
	for(i=0; i<100; i++) {
		mid=(lo+hi)/2;
		if(f(mid)<EPS) hi=mid-EPS;
		else lo=mid+EPS;
	}
	high=mid;
	printf("%.12Lf %.12Lf\n", low, high);
	return 0;
}
