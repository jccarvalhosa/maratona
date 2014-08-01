#include <cstdio>

long long v[2000001];

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%lld", &v[i]);
	for(int i=n;i<2*n;i++) v[i] = v[i-n];
	long long sum = 0, step=0;
	for(int i=0;i<n;i++) {
		sum += v[i] * (i+1);
		step += v[i];
	}
	long long ans = sum;
	for(int i=1;i<n;i++) {
		sum += n * v[i+n-1] - step;
		if(ans < sum) ans = sum;
	}
	printf("%lld\n", ans);
	return 0;
}
