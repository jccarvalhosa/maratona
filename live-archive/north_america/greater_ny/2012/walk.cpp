#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=1010;
double dp[2][2*N][2*N];

int main() {
	int p;
	cin>>p;
	while(p--) {
		int t, n;
		double l, r;
		cin>>t>>n>>l>>r;

		memset(dp, 0, sizeof(dp));
		
		dp[0][N][N] = 1;

		for(int step=1;step<=n;step++) for(int i=N-step;i<=N+step;i++) {
			int ind = step & 1;
			if(i >= N) {
				dp[ind][i][i] = (1 - l - r) * dp[1 - ind][i][i] + r * dp[1 - ind][i-1][i-1] + r * dp[1 - ind][i-1][i];
			}
			for(int j=max(N, i+1);j<=N+step;j++) {
				dp[ind][i][j] = (1 - l - r) * dp[1 - ind][i][j] + r * dp[1 - ind][i-1][j] + l * dp[1 - ind][i+1][j];
			}
		}

		double ans = 0;
		for(int i=N-n;i<=N+n;i++) for(int j=i;j<=N+n;j++) ans += dp[n&1][i][j] * (j-N);
		printf("%d %.4lf\n", t, ans);
	}
	return 0;
}
