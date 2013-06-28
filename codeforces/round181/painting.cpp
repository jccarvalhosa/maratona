#include <cstdio>
#include <iostream>
#define M 7340033
using namespace std;

long long dp[31][1001], delta[31][1001];

int main() {
	int n, i, j, k, q, t;
	dp[0][0]=1;
	for(i=1;i<=30;i++) {
		dp[i][0]=1;
		for(j=0;j<=1000;j++) for(k=0;k<=1000-j;k++) delta[i][j+k] = (delta[i][j+k] + dp[i-1][j]*dp[i-1][k]) % M;
		for(j=0;j<=1000;j++) for(k=0;k<=1000-j-1;k++) dp[i][j+k+1] = (dp[i][j+k+1] + delta[i][j]*delta[i][k]) % M;
	}
	cin>>q;
	while(q--) {
		t=0;
		cin>>n>>k;
		while(n>1 && n&1) n/=2, t++;
		cout<<dp[t][k]<<endl;
	}
	return 0;
}
