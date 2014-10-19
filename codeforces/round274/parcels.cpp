#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int N=501;
int n, in[N], out[N], w[N], s[N], v[N];
int dp[N][2*N], ans[N][2*N];
vector<int> el[2*N];

int go(int pos, int S) {
	if(S<0) return 0;
	if(dp[pos][S] != -1) return dp[pos][S];
	ans[pos][out[pos]+1]=0;
	for(int i=out[pos];i>=in[pos];i--) {
		ans[pos][i] = ans[pos][i+1];
		for(int j=0;j<el[i].size();j++) {
			int npos = el[i][j];
			if(out[npos] > out[pos] || npos==pos) continue;
			ans[pos][i] = max(ans[pos][i], go(npos, min(S-w[npos], s[npos])) + ans[pos][out[npos]]);
		}
	}
	return dp[pos][S] = v[pos] + ans[pos][in[pos]];
}

int main() {
	memset(dp, -1, sizeof(dp));
	int S;
	cin>>n>>S;
	out[0]=2*n-1;
	for(int i=1;i<=n;i++) {
		cin>>in[i]>>out[i]>>w[i]>>s[i]>>v[i];
		el[in[i]].push_back(i);
	}
	cout << go(0, S) << endl;
	return 0;
}
