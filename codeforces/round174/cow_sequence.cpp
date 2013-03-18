#include <cstdio>

int delta[500000], val[500000], n=1;

int main() {
	int N, t, a, x, i;
	double sum=0;
	scanf("%d", &N);
	val[1]=0;
	delta[1]=0;
	while(N--) {
		scanf("%d", &t);
		if(t == 1) {
			scanf("%d%d", &a, &x);
			sum += a * x;
			delta[a] += x;
		}
		if(t == 2) {
			scanf("%d", &a);
			n++;
			val[n] = a;
			delta[n] = 0;
			sum += a;
		}
		if(t == 3) {
			sum -= val[n] + delta[n];
			delta[n-1] += delta[n];
			delta[n--] = 0;
		}
		printf("%lf\n", sum / n);
	}
	return 0;
}
