#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> adj[111];
int dep[111];

void dfs(int v, int p) {
	if(p==v) dep[v]=1;
	else dep[v]=dep[p]+1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u!=p) dfs(u, v);
	}
}

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	double sum=0;
	for(int i=1;i<=n;i++) sum += 1.0/dep[i];
	cout<<(int)(sum+1e-30)<<endl;
	return 0;
}
