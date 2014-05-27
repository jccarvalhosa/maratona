#include <bits/stdc++.h>
using namespace std;

const int N=111;
double dp[N][N], b[2], x[N], y[N], dist[N][N], pi[N][N], pj[N][N];

int reduce(int i, int j, double v) {
	if(dp[i][j] <= v+1e-9) return 0;
	dp[i][j] = v;
	return 1;
}

int main() {
	int T=1, n;
	while(cin>>n>>b[0]>>b[1] && n) {
		for(int i=0;i<n;i++) cin>>x[i]>>y[i];
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) dist[i][j] = hypot(x[i]-x[j], y[i]-y[j]);
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = 1e9;
		dp[0][0] = 0;
		if(b[1] != 1) dp[1][0] = dist[0][1];
		if(b[0] != 1) dp[0][1] = dist[0][1];
		for(int i=1;i<n;i++) for(int j=0;j<i;j++) {
			if(reduce(i, i, dp[i][j] + dist[j][i])) {
				pj[i][i] = j;
				pi[i][i] = -1;
			}
			if(reduce(i, i, dp[j][i] + dist[j][i])) {
				pj[i][i] = -1;
				pi[i][i] = j;
			}
			if(b[1] != i+1) {
				if(reduce(i+1, j, dp[i][j] + dist[i][i+1])) {
					pi[i+1][j] = i;
					pj[i+1][j] = -1;
				}
				if(reduce(i+1, i, dp[j][i] + dist[j][i+1])) {
					pi[i+1][i] = j;
					pj[i+1][i] = -1;
				}
			}
			if(b[0] != i+1) {
				if(reduce(j, i+1, dp[j][i] + dist[i][i+1])) {
					pi[j][i+1] = -1;
					pj[j][i+1] = i;
				}
				if(reduce(i, i+1, dp[i][j] + dist[j][i+1])) {
					pi[i][i+1] = -1;
					pj[i][i+1] = j;
				}
			}
		}
		printf("Case %d: %.2lf\n", T++, dp[n-1][n-1]);
		int a=n-1, b=n-1;
		vector<int> va, vb;
		while(a+b != 1) {
			va.push_back(a);
			vb.push_back(b);
			if(pi[a][b] != -1) a = pi[a][b];
			else b = pj[a][b];
		}
		va.push_back(a);
		va.push_back(0);
		vb.push_back(b);
		vb.push_back(0);
		reverse(va.begin(), va.end());
		for(int i=0;i<vb.size();i++) va.push_back(vb[i]);
		va.erase(unique(va.begin(), va.end()), va.end());
		if(va[1] != 1) reverse(va.begin(), va.end());
		for(int i=0;i<va.size();i++) printf("%d%c", va[i], i < va.size() -1 ? ' ' : '\n');
	}
	return 0;
}
