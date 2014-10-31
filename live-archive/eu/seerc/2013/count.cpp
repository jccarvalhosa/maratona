#include <cstdio>

int a[10001][10001], n, m;

int main() {
	fread(&n, sizeof(n), 1, stdin);
	fread(&m, sizeof(m), 1, stdin);
	for(int i=0;i<n;i++) fread(a[i], sizeof(int), m, stdin);
	int x, y;
	while(fread(&x, sizeof(x), 1, stdin)) {
		fread(&y, sizeof(y), 1, stdin);
		int ret=0, l=0, r=m-1;
		for(int i=n-1;i>=0;i--) {
			while(l < m && a[i][l] < x) l++;
			ret -= l;
		}
		for(int i=0;i<n;i++) {
			while(r >= 0 && a[i][r] > y) r--;
			ret += r+1;
		}
		printf("%d\n", ret);
	}
	return 0;
}
