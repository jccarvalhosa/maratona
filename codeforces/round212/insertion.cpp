#include <cstdio>
#include <iostream>
using namespace std;

int v[5555], dp[5555][5555];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++) dp[1][i] = v[0]>i;
	for(int i=1;i<n;i++) for(int j=0;j<n;j++) dp[i+1][j] = dp[i][j] + (v[i]>j);
	int sum=0;
	for(int i=0;i<n;i++) sum += dp[i][v[i]];
	int d=0, t=0;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
		if(v[i]<v[j]) continue;
		int nd = dp[i][v[j]] - dp[i][v[i]];
		nd += dp[j][v[i]] - dp[j][v[j]];
		int x = dp[j][v[j]] - dp[j][v[i]-1];
		x -= dp[i+1][v[j]] - dp[i+1][v[i]-1];
		nd -= x;
		if(nd < d) {
			d = nd;
			t=1;
		}
		else if(nd == d) {
			t++;
		}
	}
	cout<<sum+d<<" "<<t<<endl;
	return 0;
}
