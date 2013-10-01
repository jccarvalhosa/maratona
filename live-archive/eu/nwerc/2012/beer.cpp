#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

double p[6666666][5];
int n, k, dp[6][55], vis[6666666];

int conv(int v[5], int sum) {
	if(sum==0) return 0;
	int ret = dp[n][sum-1];
	int s=0;
	for(int i=n-1;i>=0;i--) {
		s += v[i];
		ret += dp[i][sum] - dp[i][sum-s];
	}
	return ret;
}

void go(int v[5], int sum, int iv) {
	vis[iv] = 1;
	for(int j=0;j<n;j++) p[iv][j]=0;
	if(sum == k) {
		int m = *max_element(v, v+n);
		int x = count(v, v+n, m);
		for(int j=0;j<n;j++) if(v[j] == m) p[iv][j] = 1.0/x;
		return;
	}
	int u[5];
	for(int i=0;i<n;i++) u[i] = v[i];
	for(int i=0;i<n;i++) {
		u[i]++;
		int iu = conv(u, sum+1);
		if(!vis[iu]) go(u, sum+1, iu);
		for(int j=0;j<n;j++) p[iv][j] += (1.0*v[i]/sum) * p[iu][j];
		u[i]--;
	}
}

int main() {
	while(scanf("%d %d", &n, &k)!=EOF) {
		for(int i=0;i<=k;i++) dp[0][i]=1;
		for(int i=1;i<=n;i++) {
			dp[i][0] = 1;
			for(int j=1;j<=k;j++) dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
		for(int i=0;i<=dp[n][k];i++) vis[i]=0;
		int v[5] = {0};
		for(int i=0;i<n;i++) cin>>v[i];
		int sum = accumulate(v, v+5, 0);
		int ind = conv(v, sum);
		go(v, sum, ind);
		for(int i=0;i<n;i++) printf("pub %d: %.2lf %%\n", i+1, 100.0*p[ind][i]);
	}
	return 0;
}
