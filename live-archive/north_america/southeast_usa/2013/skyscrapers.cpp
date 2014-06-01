#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;
const int N=5e3+10;
int dp[N][N], c[N][N];

int main() {
	for(int i=0;i<N;i++) {
		c[0][i]=1;
		for(int j=1;j<=i;j++) c[j][i] = (c[j][i-1] + c[j-1][i-1])%M;
	}

	dp[0][0]=1;
	for(int i=1;i<N;i++) {
		for(int j=1;j<=i;j++) dp[i][j] = (dp[i-1][j-1] + 1ll*(i-1)*dp[i-1][j])%M;
	}

	int n, l, r;
	while(cin>>n>>l>>r && n) {
		int ans=0;
		for(int m=0;m<n;m++) ans = (ans + 1ll*c[m][n-1]*dp[m][l-1]%M*dp[n-m-1][r-1])%M;
		cout << ans << endl;
	}
	return 0;
}
