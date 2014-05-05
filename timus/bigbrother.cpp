#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		double n, m;
		scanf("%lf%lf", &n, &m);
		printf("%.12lf\n", m > n ? 0 : (n-m+1)/(n+1));
	}
	return 0;
}
