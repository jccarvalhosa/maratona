#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int dp[555][555];
int sum[111][555];
int best[555];

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int n, s, w;
		cin>>n>>s>>w;
		memset(sum, 0, sizeof(sum));
		for(int i=1;i<=w;i++) {
			int k;
			cin>>k;
			while(k--) {
				int j;
				cin>>j;
				sum[i][j]=1;
			}
		}
		for(int i=1;i<=w;i++) for(int j=2;j<=n;j++) sum[i][j] += sum[i][j-1];
		int i, j;
		for(i=1;i<=n;i++) {
			int f=0;
			for(j=1;j<=w;j++) if(sum[j][i]-sum[j][i-1]!=0) f++;
			if(f+1>s) break;
			dp[i][1] = best[i-1] + f;
			best[i] = dp[i][1];
			for(j=2;j<=i;j++) {
				int f=0;
				for(int k=1;k<=w;k++) if(sum[k][i]-sum[k][i-j]!=0) f++;
				if(j+f>s) break;
				int old=0;
				for(int k=1;k<=w;k++) if(sum[k][i-1]-sum[k][i-j]!=0) old++;
				dp[i][j] = dp[i-1][j-1] + f - old;
				best[i] = min(best[i], dp[i][j]);
			}
		}
		cout<<"Case "<<t<<": ";
		if(i<=n) cout<<-1<<endl;
		else cout<<best[n]<<endl;
	}
	return 0;
}
