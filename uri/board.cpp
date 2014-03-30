#include <iostream>
#include <string>
using namespace std;
int valid[100][100];
int dp[100][100];
int v[100][100], sum[100][100];
string s[100];
int main() {
	int n, m, k;
	while(cin>>n>>m && n) {
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>v[i][j];
		cin>>k;
		for(int i=0;i<k;i++) cin>>s[i];
		for(int i=0;i<k;i++) for(int j=0;j<k;j++) {
			valid[i][j]=1;
			for(int jj=0;jj<m;jj++) if(s[i][jj] == s[j][jj] && s[i][jj] != '.') valid[i][j]=0;
		}
		for(int i=0;i<n;i++) for(int j=0;j<k;j++) {
			sum[i][j]=0;
			for(int jj=0;jj<m;jj++) {
				if(s[j][jj] == '+') sum[i][j] += v[i][jj];
				if(s[j][jj] == '-') sum[i][j] -= v[i][jj];
			}
		}
		for(int i=0;i<k;i++) dp[0][i] = sum[0][i];
		for(int i=1;i<n;i++) for(int j=0;j<k;j++) {
			dp[i][j] = -1e9;
			for(int jj=0;jj<k;jj++) if(valid[jj][j]) dp[i][j] = max(dp[i][j], dp[i-1][jj] + sum[i][j]);
		}
		int ans=-1e9;
		for(int i=0;i<k;i++) ans = max(ans, dp[n-1][i]);
		cout<<ans<<endl;
	}
	return 0;
}
