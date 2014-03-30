#include <iostream>
#include <algorithm>
using namespace std;

long long v[111], dp[111][111];

int main() {
	int T, n, m;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>v[i];
		sort(v+1, v+n+1);
		for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j] = 1e15;
		dp[0][0]=0;
		for(int ng=1;ng<=m;ng++) for(int i=1;i<=n;i++) for(int j=i;j>0;j--) dp[i][ng] = min(dp[i][ng], dp[j-1][ng-1] + v[i]-v[j]);
		cout<<"Case #"<<t<<": "<<dp[n][m]<<endl;
	}
	return 0;
}
