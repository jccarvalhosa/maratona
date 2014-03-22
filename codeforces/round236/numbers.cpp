#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int N=1e3+1;
const int M=1e9+7;
ll fat[N], inv[N], dp[N][N], ans[N][N];
ll comb[2*N][2*N];

ll exp(ll a, ll e) {
	if(!e) return 1;
	if(e&1) return a*exp(a, e-1)%M;
	return exp(a*a%M, e/2);
}

int main() {
	int T, n, k;
	fat[0]=1;
	for(int i=1;i<N;i++) {
		fat[i] = i*fat[i-1]%M;
		inv[i] = exp(i, M-2);
	}
	for(int i=0;i<2*N;i++) {
		comb[0][i]=1;
		for(int j=1;j<=i;j++) comb[j][i] = (comb[j-1][i-1] + comb[j][i-1])%M;
	}
	dp[0][0]=1;
	for(n=1;n<N;n++) for(k=1;k<=n;k++) dp[n][k] = (dp[n-k][k-1] + dp[n-k][k])%M;
	for(n=1;n<N;n++) for(k=1;k<=n;k++) dp[n][k] = dp[n][k]*fat[k]%M;
	for(k=1;k<N;k++) for(n=k;n<N;n++) {
		ans[n][k] = dp[n][k];
		for(int i=k;i<n;i++) ans[n][k] += dp[i][k]*comb[k][n-i+k]%M;
		ans[n][k] %= M;
	}
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		cout<<ans[n][k]<<"\n";
	}
	return 0;
}
