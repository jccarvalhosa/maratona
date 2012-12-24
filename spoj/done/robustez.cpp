#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

double dp[100][1001], prob;
int c, N, B;

int main() {
	int i, j, k;
	while(scanf("%d%d", &N, &B) && N) {
		scanf("%d%lf", &c, &prob);
		memset(dp, 0, sizeof(dp));
		for(i=0;i<=B;i+=c) dp[0][i] = 1 - pow(prob, i/c); 
		for(i=1;i<=B;i++) dp[0][i] = max(dp[0][i], dp[0][i-1]);
		for(i=1;i<N;i++) {
			scanf("%d%lf", &c, &prob);
			for(k=0;k<=B;k++) for(j=0;j<=k;j+=c) dp[i][k] = max(dp[i][k], (1 - pow(prob, j/c)) * dp[i-1][k-j]); 
			for(j=1;j<=B;j++) dp[i][j] = max(dp[i][j], dp[i][j-1]);
		}
		printf("%.3lf\n", dp[N-1][B]);
	}
	return 0;
}
