#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int adj[N], vis[N], cc, tam[N], cycle[N], a[N], b[N], dp[N];

void dfs(int u, int d) {
	vis[u]=1;
	tam[u]=d;
	int v=adj[u];
	if(!vis[v]) dfs(v, d+1);
	else if(vis[v]==1) {
		cycle[v]=++cc;
		a[cc]=tam[u]-tam[v]+1;
	}
	vis[u]=2;
	cycle[u]=cycle[v];
	b[cycle[u]]++;
}

int main() {
	int n, s;
	cin >> n >> s;
	for(int i=0; i<n; i++) {
		cin >> adj[i];
		adj[i]--;
	}
	for(int i=0; i<n; i++) if(!vis[i]) dfs(i, 1);
	dp[0]=1;
	int sum=0, ans;
	for(int i=1; i<=cc; i++) {
		for(int j=sum; j>=0; j--) if(dp[j]) for(int k=a[i]; k<=b[i] && j+k<=s; k++) dp[j+k]=1;
		sum+=b[i];
		sum=min(sum, s);
	}
	for(int i=0; i<=s; i++) if(dp[i]) ans=i;
	printf("%d\n", ans);
	return 0;
}
