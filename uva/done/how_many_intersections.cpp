#include <cstdio>

int main() {
	int a, b, t=1;
	while(scanf("%d%d", &a, &b) && a) printf("Case %d: %lld\n", t++, 1LL * a * (a-1) * b * (b-1) / 4);
	return 0;
}
