#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int m, dp[111][111][111];

int go(int a, int b, int n) {
	if(dp[a][b][n] != -1) return dp[a][b][n];
	if(n==0) return dp[a][b][0] = go(0, 0, a);
	int ans=0;
	for(int i=1;i<=min(n, m);i++) ans = max(ans, a+b+n - go(b, a+i, n-i));
	return dp[a][b][n] = ans;
}

int main() {
	int n;
	cin>>n>>m;
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) dp[i][j][k] = -1;
	dp[0][0][0] = 0;
	cout<<go(0, 0, n)<<endl;
	return 0;
}
