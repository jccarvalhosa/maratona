#include <cstdio>
#include <algorithm>
#define INF 1000000
using namespace std;

int N, T[1000][1000], dp[1000][1000];

int cont(int n, int v) {
	int ret;
	if(!n) return INF;
	for(ret=0; n % v == 0; ret++) n /= v;
	return ret;
}

int best(int v) {
	int i, j;
	for(i=0;i<N;i++) for(j=0;j<N;j++) dp[i][j] = cont(T[i][j], v);
	for(j=1;j<N;j++) dp[0][j] = min(INF, dp[0][j] + dp[0][j-1]);
	for(i=1;i<N;i++) {
		dp[i][0] = min(INF, dp[i][0] + dp[i-1][0]);
		for(j=1;j<N;j++) dp[i][j] = min(INF, dp[i][j] + min(dp[i-1][j], dp[i][j-1]));
	}
	return dp[N-1][N-1];
}

int main() {
	scanf("%d", &N);
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) scanf("%d", &T[i][j]);
	printf("%d", min(best(2), best(5)));
	return 0;
}
