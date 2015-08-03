#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int M = 1e9+7;
const int N=1e5+1;
vector<int> adj[N];
int n, b[N];
ll dp[N][2];

void dfs(int v, int p) {
	dp[v][0]=1;
	dp[v][1]=0;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u==p) continue;
		
		dfs(u, v);
		
		dp[v][1] *= dp[u][0];
		dp[v][1] += dp[u][1] * dp[v][0];
		dp[v][1] %= M;

		dp[v][0] *= dp[u][0];
		dp[v][0] %= M;
	}
	if(b[v]) {
		dp[v][1] = dp[v][0];
	}
	else {
		dp[v][0] += dp[v][1];
		dp[v][0] %= M;
	}
}

int main() {
	cin>>n;
	for(int i=1;i<n;i++) {
		int x;
		cin>>x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	for(int i=0;i<n;i++) cin>>b[i];
	dfs(0, 0);
	cout << dp[0][1] << endl;
	return 0;
}
