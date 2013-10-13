#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n;
const int N = 50001;
vector<pii> adj[N];
vector<int> dp[N];
int best[N];

int dfs(int v, int p) {
	int ans=0;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		int d = adj[v][i].second;
		if(u==p) continue;
		dp[v][i] = dfs(u, v) + d;
		ans = max(ans, dp[v][i]);
	}
	return ans;
}

void go(int v, int p) {
	best[v]=-1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		int d = adj[v][i].second;
		if(u==p) {
			for(int j=0;j<adj[p].size();j++) {
				int uu = adj[p][j].first;
				if(uu != v) dp[v][i] = max(dp[v][i], dp[p][j] + d);
			}
			best[v] = dp[v][i];
		}
	}
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		if(u != p) {
			best[v] = max(best[v], dp[v][i]);
			go(u, v);
		}
	}
}

int main() {
	cin>>n;
	for(int i=0;i<n-1;i++) {
		int a, b, d;
		cin>>a>>b>>d;
		adj[a].push_back(pii(b, d));
		adj[b].push_back(pii(a, d));
	}
	for(int i=1;i<=n;i++) dp[i] = vector<int>(adj[i].size(), 0);
	dfs(1, 1);
	go(1, 1);
	for(int i=1;i<=n;i++) cout<<best[i]<<endl;
	return 0;
}
