#include <bits/stdc++.h>
using namespace std;

const unsigned M=1e9+7;
unsigned dp[20000][2], v[10001];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	int ans=0;
	dp[0][0]=1;
	int cur=1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<1<<14;j++) {
			dp[j][cur] = dp[j][1-cur] + 2*dp[j^v[i]][1-cur];
			while(dp[j][cur] >= M) dp[j][cur] -= M;
		}
		cur = 1-cur;
	}
	cout << dp[0][1-cur] << endl;
	return 0;
}
