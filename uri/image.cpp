#include <cstdio>

char c[111][111];

int main() {
	int n, m, a, b;
	while(scanf("%d%d", &n, &m) && n) {
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf(" %c ", &c[i][j]);
		scanf("%d%d", &a, &b);
		for(int i=0;i<n;i++) for(int ii=0;ii<a/n;ii++) {
			for(int j=0;j<m;j++) for(int jj=0;jj<b/m;jj++) printf("%c", c[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
