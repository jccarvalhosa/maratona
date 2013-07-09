#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000ll
 
ll dp[301][301], custo[301][301];

int main() {
	int n, m, k, i, j, l, r, c;
	cin>>n>>m>>k;
	for(i=0;i<=n;i++) for(j=0;j<=n;j++) custo[i][j]=dp[i][j]=INF;
	for(i=0;i<m;i++) {
		cin>>l>>r>>c;
		custo[l][r] = min(custo[l][r], (ll)c);
	}
	for(l=1;l<=n;l++) for(i=1;i<=l;i++) for(j=l;j<=n;j++){
		custo[i][l] = min(custo[i][l], custo[i][j]);
		custo[l][j] = min(custo[l][j], custo[i][j]);
	}
	for(i=0;i<=n;i++) {
		dp[i][0]=0;
		for(j=1;j<=i;j++) {
			dp[i][j] = dp[i-1][j];
			for(l=1;l<j;l++) dp[i][j] = min(dp[i][j], custo[i-l+1][i] + dp[i-l][j-l]);
			for(l=j;l<=i;l++) dp[i][j] = min(dp[i][j], custo[i-l+1][i]);
		}
	}
	if(dp[n][k]==INF) cout<<-1<<endl;
	else cout<<dp[n][k]<<endl;
	return 0;
}
