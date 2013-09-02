#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, ans;
vector<pii> adj[22222];

int dfs(int v, int p) {
	int sum=0;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		if(u==p) continue;
		int delta = dfs(u, v);
		int d = adj[v][i].second;
		if(d < 0) {
			if(delta > 0) sum += delta;
			else {
				ans += 1-delta;
				sum++;
			}
		}
		else if(delta < 0) sum += delta;
		else sum--;
	}
	return sum;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		for(int i=0;i<n;i++) adj[i].clear();
		for(int i=0;i<n-1;i++) {
			int a, b;
			cin>>a>>b;
			adj[a].push_back(pii(b, 1));
			adj[b].push_back(pii(a, -1));
		}
		ans=0;
		int x = dfs(0, -1);
		if(x<0) ans -= x;
		printf("Case %d: %d\n", t, ans);

	}
	return 0;
}
