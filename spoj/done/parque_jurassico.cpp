#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[101], b[101], c[201];
int A, B, C, dp[101][101];

int main() {
	int t, i, j, k;
	for(t=1; scanf(" %s ", a) && a[0] != '#'; t++) {
		printf("Teste %d\n", t);
		A = strlen(a);
		scanf(" %s ", b);
		B = strlen(b);
		for(j=0;j<=B;j++) dp[0][j] = 0;
		for(i=1;i<=A;i++) for(j=1;j<=B;j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if(a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
		}
		C = A + B - dp[A][B];
		i = A; j = B; k = C;
		while(i || j) {
			if(!i) c[--k] = b[--j];
			else if(!j) c[--k] = a[--i];
			else if(a[i-1] == b[j-1]) { c[--k] = a[--i]; j--; }
			else if(dp[i-1][j] == dp[i][j]) c[--k] = a[--i];
			else c[--k] = b[--j];
		}
		for(k=0;k<C;k++) printf("%c", c[k]);
		printf("\n\n");
	}
	return 0;
}
