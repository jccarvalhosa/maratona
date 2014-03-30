#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
const int N=2e4+10;
vector<int> adj[N], dp[N];

int dfs(int v, int p) {
	int ret=1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u != p) {
			dp[v][i] = dfs(u, v);
			ret += dp[v][i];
		}
	}
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u == p) dp[v][i] = n - ret;
	}
	return ret;
}

void solve() {
	for(int i=1;i<=n;i++) dp[i] = vector<int>(adj[i].size());
	dfs(1, 1);
	int inv = 1e9;
	for(int i=1;i<=n;i++) {
		int sum=0;
		for(int j=0;j<dp[i].size();j++) sum += dp[i][j] * (dp[i][j]-1) / 2;
		inv = min(inv, sum);
	}
	ans = (n-1)*(n-2)/2 - inv;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		for(int i=1;i<=n;i++) adj[i].clear();
		for(int i=0;i<n-1;i++) {
			int a, b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		solve();
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}
