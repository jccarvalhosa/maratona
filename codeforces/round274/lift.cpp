#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int N=5005;
const int M=1e9+7;
int dp[N][N], dpsum[N][N];
int sum(int a, int b, int k) {
	if(b < a) return 0;
	int ret = dpsum[b][k] - dpsum[a-1][k];
	return ret >= 0 ? ret : ret+M;  
}

int main() {
	int n, a, b, k;
	cin>>n>>a>>b>>k;
	dp[a][0] = 1;
	for(int i=a;i<=n;i++) dpsum[i][0] = 1;
	for(int j=1;j<=k;j++) {
		for(int i=1;i<b;i++) {
			dp[i][j] = sum(1, i-1, j-1) + sum(i+1, (b+i-1)/2, j-1);
			if(dp[i][j] > M) dp[i][j] -= M;
		}
		for(int i=b+1;i<=n;i++) {
			dp[i][j] = sum(i+1, n, j-1) + sum((b+i)/2+1, i-1, j-1);
			if(dp[i][j] > M) dp[i][j] -= M;
		}
		for(int i=1;i<=n;i++) {
			dpsum[i][j] = dpsum[i-1][j] + dp[i][j];
			if(dpsum[i][j] > M) dpsum[i][j] -= M;
		}
	}
	cout << dpsum[n][k] << endl;
	return 0;
}
