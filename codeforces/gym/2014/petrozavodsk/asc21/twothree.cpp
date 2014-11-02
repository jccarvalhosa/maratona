#include <bits/stdc++.h>
using namespace std;

int trans[2501][5001];
int dp[2][5001];

int main() {
	freopen("twothree.in", "r", stdin);
	freopen("twothree.out", "w", stdout);
	int l, r;
	cin>>l>>r;
	if(r==1) {
		cout << 0 << endl;
		return 0;
	}
	if(l==1 || l==2 || l==3) {
		cout << 1 << endl;
		return 0;
	}
	trans[1][2]=1;
	trans[1][3]=1;
	for(int i=2;i<=l/2;i++) for(int j=4;j<=l;j++) trans[i][j] = (trans[i-1][j-2] + trans[i-1][j-3])%r;
	int ans=0;
	dp[1][2] = 1;
	dp[1][3] = 1;
	for(int h=2;1<<h<=l;h++) {
		for(int i=1;i<1<<h;i++) dp[h&1][i]=0;
		for(int i=1<<h;i<=l;i++) {
			dp[h&1][i] = 0;
			for(int j=i/3;j<=i/2;j++) dp[h&1][i] = (dp[h&1][i] + 1ll*dp[1-(h&1)][j]*trans[j][i])%r;
		}
		ans = (ans + dp[h&1][l])%r;
	}
	cout << ans << endl;
	return 0;
}
