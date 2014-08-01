#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

const int N=1e5+1;
vector<int> adj[N], dp[N];
int n, w[N], sum, a[N], b[N], ai[N], bi[N];

int dfs(int v, int p) {
	int pi, ret = w[v];
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u != p) {
			dp[v][i] = dfs(u, v);
			ret += dp[v][i];
		}
		else pi = i;
	}
	if(p != -1) dp[v][pi] = sum - ret;
	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", w+i);
	for(int i=0;i<n;i++) sum += w[i];
	for(int i=1;i<n;i++) {
		scanf("%d%d", &a[i], &b[i]); a[i]--; b[i]--;
		ai[i] = adj[a[i]].size();
		bi[i] = adj[b[i]].size();
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	for(int i=0;i<n;i++) dp[i] = vector<int>(adj[i].size(), 0);
	dfs(0, -1);
	int ans = 1e9;
	for(int i=1;i<n;i++) ans = min(ans, mod(dp[a[i]][ai[i]] - dp[b[i]][bi[i]]));
	printf("%d\n", ans);
	return 0;
}
