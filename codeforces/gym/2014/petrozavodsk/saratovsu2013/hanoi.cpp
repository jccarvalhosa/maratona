#include <cstdio>

const int N=2e3+2;
const int M=1e8;
int dp[N][N], ans[N], flip[N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i=n;i>=1;i--) {
		int a, b;
		scanf("%d%d", &a, &b);
		flip[i] = a<b;
	}
	for(int i=1;i<=n;i++) {
		dp[i][0] = 2;
		for(int j=0;j<=n;j++) {
			dp[i][j] += 2*dp[i-1][j];
			while(dp[i][j] >= M) {
				dp[i][j] -= M;
				dp[i][j+1]++;
			}
		}
	}
	for(int i=n;i>=1;i--) {
		if(i==1 && !flip[i]) ans[0] += 3;
		else ans[0] += 2*(2-flip[i]);
		flip[i-1] ^= flip[i];
		for(int j=0;j<=n;j++) {
			ans[j] += (2-flip[i])*dp[i-1][j];
			while(ans[j] >= M) {
				ans[j] -= M;
				ans[j+1]++;
			}
		}
	}
	for(int i=n;i>=0;i--) if(ans[i]) {
		printf("%d", ans[i]);
		for(int j=i-1;j>=0;j--) printf("%08d", ans[j]);
		printf("\n");
		break;
	}
	return 0;
}
