#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, a[200000], vis[200000][2];
long long dp[200000][2];

long long dfs(int x, int dir) {
	if(x < 0 || x >= n) return 0;
	if(vis[x][dir] == 1) return -1;
	if(vis[x][dir] == 2) return dp[x][dir];
	vis[x][dir] = 1;
	long long val = (dir == 0) ? dfs(x + a[x], 1) : dfs(x - a[x], 0);
	vis[x][dir] = 2;
	if(val == -1) return dp[x][dir] = -1;
	return dp[x][dir] = val + a[x];
}

int main() {
	int i;
	scanf("%d", &n);
	for(i=1;i<n;i++) scanf("%d", &a[i]);
	memset(vis, 0, sizeof(vis));
	vis[0][0] = 1;
	for(i=1;i<n;i++) {
		if(!vis[i][1]) dfs(i, 1);
		if(dp[i][1] == -1) printf("-1\n");
		else cout << dp[i][1] + i << endl;
	}
	return 0;
}
