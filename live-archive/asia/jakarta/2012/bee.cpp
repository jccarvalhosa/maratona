#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 1<<30

int abs(int a) { return a>0?a:-a; }

int H, W, dp[55][555];

int solve(int x[], int h[], int n) {
	int X = x[n-1];
	for(int i=1;i<=X;i++) dp[0][i] = INF;
	for(int i=0;i<n;i++) dp[i][0] = INF;
	dp[0][0]=0;
	for(int i=1;i<n;i++) for(int j=1;j<=X;j++) {
		dp[i][j] = INF;
		int cost = abs(x[i]-j)*h[i];
		for(int k=j-1;k>=max(0, j-W);k--) dp[i][j] = min(dp[i][j], dp[i-1][k] + cost);
	}
	int ans=INF;
	for(int i=1;i<=X;i++) ans = min(ans, dp[n-1][i]);
	return ans;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
		int n;
		cin>>n>>H>>W;
		int x[55], h[55], nx[55], nh[55];
		for(int i=0;i<n;i++) cin>>x[i]>>h[i]; 
		int ans=1<<30;
		int m = *max_element(h, h+n);
		if(m <= H) cout << 0 << endl;
		else {
			for(int i=0;i<n;i++) if(h[i]==m) {
				for(int j=i+1;j<n;j++) {
					if(h[j] < h[j-1] - H) break;
					if(h[j] <= H) {
						for(int k=i;k<=j;k++) {
							nx[k-i] = x[k]-x[i];
							nh[k-i] = h[k];
						}
						ans = min(ans, solve(nx, nh, j-i+1));
						break;
					}
				}
				for(int j=i-1;j>=0;j--) {
					if(h[j] < h[j+1] - H) break;
					if(h[j] <= H) {
						for(int k=i;k>=j;k--) {
							nx[i-k] = x[i]-x[k];
							nh[i-k] = h[k];
						}
						ans = min(ans, solve(nx, nh, i-j+1));
						break;
					}
				}
			}
			if(ans == (1<<30)) cout << -1 << endl;
			else cout << ans <<endl;
		}
	}
	return 0;
}
