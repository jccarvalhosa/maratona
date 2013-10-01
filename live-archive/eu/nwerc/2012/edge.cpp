#include <cstdio>
const int D = 3000;
const int M = 10000;
int c[M+1][D];

int main() {
	c[3][D-1] = 4;
	c[4][D-1] = 7;
	for(int i=5;i<=M;i++) {
		int carry=0;
		for(int j=D-1;j>=0;j--) {
			c[i][j] = c[i-1][j] + c[i-2][j] + carry;
			if(c[i][j] >= 10) {
				c[i][j] -= 10;
				carry=1;
			}
			else carry=0;
		}
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		int i;
		for(i=0;;i++) if(c[n][i] != 0) break;
		for(;i<D;i++) printf("%d", c[n][i]);
		printf("\n");
	}
	return 0;
}
