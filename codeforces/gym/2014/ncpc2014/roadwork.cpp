#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N=251;
pii w[N], e[N];
int dp[N][N][N][2];
int W, E;

int main() {
	int t, n;
	cin>>t>>n;
	for(int i=0;i<n;i++) {
		char d;
		int a, r;
		scanf(" %c %d%d", &d, &a, &r);
		if(d=='W') w[W++] = pii(a, r);
		if(d=='E') e[E++] = pii(a, r);
	}
	for(int i=0;i<=W;i++) for(int j=0;j<=E;j++) for(int k=0;k<=n;k++) for(int d=0;d<2;d++) dp[i][j][k][d] = 1e9;
	if(W) dp[1][0][0][0] = w[0].first;
	if(E) dp[0][1][0][1] = e[0].first;
	for(int sum=1;sum<=n;sum++) for(int i=0;i<=min(sum, W);i++) {
		int j = sum-i;
		if(j > E) continue;
		for(int k=0;k<=sum;k++) {
			if(i < W) {
				int nt = min(dp[i][j][k][0] + 3, dp[i][j][k][1] + t);
				nt = max(nt, w[i].first);
				int nk = k + (nt > w[i].first + w[i].second);
				dp[i+1][j][nk][0] = min(dp[i+1][j][nk][0], nt); 
			}
			if(j < E) {
				int nt = min(dp[i][j][k][0] + t, dp[i][j][k][1] + 3);
				nt = max(nt, e[j].first);
				int nk = k + (nt > e[j].first + e[j].second);
				dp[i][j+1][nk][1] = min(dp[i][j+1][nk][1], nt); 
			}
		}
	}
	for(int i=0;i<=n;i++) for(int d=0;d<2;d++) if(dp[W][E][i][d] != 1e9) {
		cout << i << endl;
		return 0;
	}
}
