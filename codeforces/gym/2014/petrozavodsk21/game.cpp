#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1200;

vector<int> adj[N];
int match[N], pi[N], vis[N], aux[N];

int dfs(int v) {
	int i, u;
	if(vis[v]) return 0;
	vis[v]=1;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i];
		if(match[u] == -1 || dfs(match[u])) {
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int n1, n2;

int solve(int rem) {
	for(int i=1;i<=n1+n2;i++) match[i]=aux[i];
	if(match[rem] == -1) return 0;
	for(int i=1;i<=n1;i++) vis[i]=0;
	match[match[rem]] = -1;
	if(rem <= n1) {
		vis[rem] = 1;
	}
	else {
		match[rem] = 0;
		vis[0]=1;
	}
	for(int i=1;i<=n1;i++) if(match[i] == -1 && dfs(i)) return 0;
	return 1;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int m;
	cin>>n1>>n2>>m;
	for(int i=0;i<m;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(n1+b);
	}
	for(int i=1;i<=n1+n2;i++) match[i]=-1;
	for(int i=1;i<=n1;i++) {
		for(int j=1;j<=n1;j++) vis[j]=0;
		dfs(i);
	}
	for(int i=n1+1;i<=n1+n2;i++) if(match[i] != -1) match[match[i]]=i;
	for(int i=1;i<=n1+n2;i++) aux[i]=match[i];
	for(int i=1;i<=n1;i++) cout << (solve(i) ? "N": "P"); cout << endl;
	for(int i=1;i<=n2;i++) cout << (solve(n1+i) ? "N": "P"); cout << endl;
	return 0;
}
