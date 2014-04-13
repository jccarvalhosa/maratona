#include <bits/stdc++.h>
using namespace std;

int n, d[2222];

int valid(double r) {
	double sum=0;
	for(int i=0;i<n;i++) {
		if(d[i] > 2*r) return 0;
		double teta = asin(d[i]/(2*r));
		sum += teta;
	}
	return sum <= M_PI;
}

double solve() {
	double i=0, f=300000;
	for(int t=0;t<450;t++) {
		double m = (i+f)/2;
		if(valid(m)) f=m;
		else i=m;
	}
	return f;
}

int main()
{
	int t=1, T;
	freopen("zeriba.in", "r", stdin);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=0;i<n;i++) scanf("%d", &d[i]);
		printf("Case %d: ", t++);
		if(2*(*max_element(d, d+n)) >= accumulate(d, d+n, 0)) printf("can't form a convex polygon\n");
		else printf("%.4lf\n", solve());
	}
	return 0;
}
