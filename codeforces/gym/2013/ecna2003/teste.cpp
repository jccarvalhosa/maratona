#include <cstdio>
#include <iostream>
using namespace std;

int adj[111][111], v[111];
long long dp[111];

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int a, b;
		cin>>a>>b;
		adj[a+1][b+1] = adj[b+1][a+1] = 1;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if((i > j && !adj[i][j]) || (i < j && adj[i][j])) v[i]++;
	v[0] = -1;
	v[n+1] = n;
	dp[0] = 1;
	for(int i=0;i<=n;i++) for(int j=i+1;j<=n+1;j++) if(v[j] > v[i]) {
		dp[j] += dp[i];
		break;
	}
	for(int i=1;i<=n+1;i++) cout<<dp[i]<<" ";
	cout<<endl;
	cout<<dp[n+1]<<endl;
	return 0;
}
