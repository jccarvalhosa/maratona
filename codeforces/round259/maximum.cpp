#include <cstdio>

const int N=1e5+1;
double p[N];

double exp(double a, int e) {
	if(!e) return 1;
	if(e&1) return a*exp(a, e-1);
	return exp(a*a, e/2);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	double prob=0;
	for(int i=1;i<=n;i++) p[i] = exp(1.0*i/n, m);
	double sum = 0;
	for(int i=1;i<=n;i++) sum += (p[i] - p[i-1]) * i;
	printf("%.12lf\n", sum);
	return 0;
}
