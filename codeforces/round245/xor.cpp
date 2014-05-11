#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
	
int n;
const int N=1e5+10;
vector<int> adj[N], ans;
int ini[N], fim[N];

void dfs(int v, int p, int fi, int fp) {
	if(ini[v] ^ fi ^ fim[v]) {
		ans.push_back(v);
		fi = 1-fi;
	}
	swap(fi, fp);
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u != p) dfs(u, v, fi, fp);
	}
}

int main() {
	cin>>n;
	for(int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=n;i++) scanf("%d", &ini[i]);
	for(int i=1;i<=n;i++) scanf("%d", &fim[i]);
	dfs(1, -1, 0, 0);
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
	return 0;
}
