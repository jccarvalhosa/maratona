#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<bool, int> pbi;
vector<vector<int> > adj;
int n;

pbi dfs(int v, int p) {
	bool odd = true;
	int ans = 0;
	for(int i=0; i < adj[v].size(); i++) {
		int u = adj[v][i];
		if (u == p) continue;
		pbi res = dfs(u, v);
		odd ^= res.first;
		ans += res.second;
	}
	if (!odd) ans++;
	return pbi(odd, ans);
}

int main() {
	int m;
	cin>>n>>m;
	adj.resize(n, vector<int>());
	for (int i=0; i < m; i++) {
		int a, b;
		cin>>a>>b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << dfs(0, -1).second - 1<< endl;
	return 0;
}
