#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;

const int N=5e3+10;
ll p[N], dp[N][N];

int main() {
	int n, K;
	cin>>n>>K;
	for(int i=0;i<n;i++) cin>>p[i];
	for(int k=1;k<=K;k++) {
		ll M = 0;
		for(int i=n-1;i>=0;i--) {
			M = max(M, dp[i+1][k-1] + p[i]);
			dp[i][k] = max(dp[i][k-1], max(dp[i+1][k], M - p[i]));
		}
	}
	cout<<dp[0][K]<<endl;
	return 0;
}
