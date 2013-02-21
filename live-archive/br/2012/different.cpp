#include <cstdio>
#include <cstring>

int count[10];

int valid(int n) {
	memset(count, 0, sizeof(count));
	while(n) {
		count[n%10]++;
		n /= 10;
	}
	for(int i=0;i<10;i++) if(count[i] > 1) return 0;
	return 1;
}

int main() {
	int i, ans, n, m;
	while(scanf("%d%d", &n, &m)!=EOF) {
		ans=0;
		for(i=n;i<=m;i++) if(valid(i)) ans++;
		printf("%d\n", ans);
	}
}
