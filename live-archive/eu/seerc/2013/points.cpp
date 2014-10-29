#include <bits/stdc++.h>
using namespace std;

const int N=1e6+7;
long long dp[N][2][2];
int a[N], b[N], c[N];

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i=0;i<n;i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
		dp[n-1][0][0] = dp[n-1][0][1] = 0;
		dp[n-1][1][0] = a[n-1];
		dp[n-1][1][1] = -1e18;
		for(int i=n-2;i>=0;i--) {
			dp[i][0][0] = max(dp[i+1][0][0], dp[i+1][0][1]);
			dp[i][0][1] = max(dp[i+1][1][0], dp[i+1][1][1]);
			dp[i][1][0] = a[i] + max(dp[i+1][0][0], dp[i+1][0][1]);
			dp[i][1][1] = b[i] + max(dp[i+1][1][0] - a[i+1] + b[i+1], dp[i+1][1][1] - b[i+1] + c[i+1]);
		}
		cout << max(max(dp[0][1][0], dp[0][1][1]), max(dp[0][0][0], dp[0][0][1])) << endl;
	}
	return 0;
}
