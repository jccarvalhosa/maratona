#include <iostream>
#include <algorithm>
using namespace std;

const int M = 10007;
int u[105], v[105], c[105], w[105], cac[105], comb[105][105];
int N, t, vis[105][105][1005], dp[105][105][1005], mult[105][105];

int go(int s, int n, int sum) {
	if(sum == 0) return n==0;
	if(s >= N) return 0;
	if(vis[s][n][sum] == t) return dp[s][n][sum];
	vis[s][n][sum]=t;
	int ret=0;
	int imax = min(c[s], min(n, w[s]==0 ? c[s] : sum/w[s]));
	for(int i=0;i<=imax;i++) ret += (go(s+1, n-i, sum-i*w[s]) * comb[i][n])%M;
	return dp[s][n][sum] = ret%M;
}

int main() {
	for(int i=0;i<=100;i++) {
		comb[0][i]=1;
		for(int j=1;j<=i;j++) comb[j][i] = (comb[j-1][i-1] + comb[j][i-1])%M;
	}
	int T;
	cin>>T;
	for(t=1;t<=T;t++) {
		int n, W;
		cin>>n>>W;
		for(int i=0;i<=100;i++) c[i]=0;
		for(int i=0;i<n;i++) cin>>v[i];
		for(int i=0;i<n;i++) u[i]=v[i];
		sort(u, u+n);
		N = unique(u, u+n)-u;
		for(int i=0;i<N;i++) w[i] = u[i];
		for(int i=0;i<n;i++) c[lower_bound(u, u+N, v[i])-u]++;
		cac[N] = 0;
		for(int i=N-1;i>=0;i--) cac[i] = cac[i+1] + c[i];
		for(int j=0;j<=n;j++) {
			mult[0][j]=1;
			int sum=j;
			for(int i=1;i<=N;i++) {
				mult[i][j] = (mult[i-1][j] * comb[c[i-1]][c[i-1]+sum]) % M;
				sum += c[i-1];
			}
		}
		int ans=0;
		for(int sum=W;sum>=0;sum--) {
			int s=0;
			int pos = upper_bound(u, u+N, W-sum)-u;
			for(int i=0;i<pos;i++) s += c[i]*w[i];
			if(s > sum) break;
			for(int q=0;q<=cac[pos];q++) ans = (ans + go(pos, q, sum-s) * mult[pos][q])%M;
		}
		cout<<"Case "<<t<<": "<<ans<<endl;
	}
	return 0;
}
