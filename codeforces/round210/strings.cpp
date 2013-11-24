#include <iostream>
#include <string>
using namespace std;

const int M = (int)1e9+7;

long long dp[2222][2222], sum[2222][2222];

int main() {
	int n, k;
	string s;
	cin>>n>>k>>s;
	dp[n][0] = 1;
	for(int i=n-1;i>=0;i--) for(int j=0;j<=k;j++) {
		sum[i+1][j] = (sum[i+2][j] + dp[i+1][j]*(s[i]-'a'))%M;
		dp[i][j] = (dp[i][j] + sum[i+1][j])%M;
		dp[i][j] = (dp[i][j] + dp[n][j])%M;
		int again=0;
		for(int k=i;k<n;k++) {
			if(j - (n-k)*(k-i+1) < 0) {	again=1; break;	}
			dp[i][j] = (dp[i][j] + dp[k+1][j - (n-k)*(k-i+1)]*('z'-s[k]))%M;
		}
		if(again) for(int k=n-1;k>=i;k--) {
			if(j - (n-k)*(k-i+1) < 0) break;
			dp[i][j] = (dp[i][j] + dp[k+1][j - (n-k)*(k-i+1)]*('z'-s[k]))%M;
		}
	}
	cout<<dp[0][k]<<endl;
	return 0;
}
