#include <cstdio>
#define MAX 1000000

int mod(int a) { return a > 0 ? a : -a; }

char c[MAX];
int a[MAX], g[MAX];

int main() {
	int n, i, sa, sg;
	scanf("%d", &n);
	for(i=0;i<n;i++) scanf("%d %d", &a[i], &g[i]);
	sa = sg = 0;
	for(i=0;i<n;i++) {
		if(mod(sa - (sg+g[i])) <= 500) {
			c[i] = 'G';
			sg += g[i];
		}
		else {
			c[i] = 'A';
			sa += a[i];
		}
	}
	if(mod(sa-sg) > 500) {
		printf("-1\n");
	}
	else {
		for(i=0;i<n;i++) printf("%c", c[i]);
		printf("\n");
	}
	return 0;
}
