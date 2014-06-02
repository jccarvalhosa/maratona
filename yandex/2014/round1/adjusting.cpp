#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
ll dp[N][2], v[N];

int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>v[i];
	sort(v+1, v+n+1);
	v[0] = -1e18;
	dp[n+1][0] = dp[n+1][1] = 0;
	dp[n][0] = 1e18;
	dp[n][1] = v[n] - v[n-1];
	for(int i=n-1;i>=1;i--) {
		dp[i][0] = dp[i+2][1] + v[i+1] - v[i];
		dp[i][1] = min(dp[i][0], dp[i+1][0] + v[i] - v[i-1]);
	}
	cout << dp[1][0] << endl;
	return 0;
}
