#include <cstdio>

const int M=30000001;
int dp[M];

int main() {
	for(int d=1;d<M;d++) for(int i=2*d;i<M;i+=d) if(((i^d) < i) && (i^d) % d==0) dp[i]++;
	for(int i=3;i<M;i++) dp[i] += dp[i-1];
	int T;
	scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		int n; 
		scanf("%d", &n);
		printf("Case %d: %d\n", t, dp[n]); 
	} 
	return 0;
}
