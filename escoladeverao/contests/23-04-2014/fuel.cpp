#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
const int N=5e5+10;
int dist[N];
vector<int> adj[N];

int dfs(int v, int p) {
	if(p==-1) dist[v]=0;
	else dist[v] = dist[p]+1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u!=p) dfs(u, v);
	}
}

int main() {
	cin>>n>>m;
	for(int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	int x, dmax=-1;
	for(int i=1;i<=n;i++) {
		if(dist[i] > dmax) {
			dmax=dist[i];
			x=i;
		}
	}
	dfs(x, -1);
	dmax=-1;
	for(int i=1;i<=n;i++) {
		if(dist[i] > dmax) {
			dmax=dist[i];
			x=i;
		}
	}
	if(m <= dmax-1) {
		cout << m+1 << endl;
	}
	else {
		cout << dmax+1 + min(n-dmax-1, (m-dmax)/2) << endl;
	}
	return 0;
}
