#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int N=1e5+10;
int n, m, vis[N], val[N];
vector<int> adj[N], ans;

void dfs(int v) {
	val[v] ^= 1;
	ans.push_back(v);
	vis[v]=1;
	for(int i=0;i<adj[v].size();i++) {
		int u =adj[v][i];
		if(vis[u]) continue;
		dfs(u);
		val[v] ^= 1;
		ans.push_back(v);
		if(val[u]) {
			val[u] ^= 1;
			ans.push_back(u);
			val[v] ^= 1;
			ans.push_back(v);
		}
	}
}

int main() {
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int a, b;
		scanf("%d%d", &a, &b); a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int r=-1;
	for(int i=0;i<n;i++) {
		scanf("%d", &val[i]);
		if(val[i]) r=i;
	}
	if(r==-1) cout << 0 << endl;
	else {
		dfs(r);
		for(int i=0;i<n;i++) if(i != r && !vis[i] && val[i]) {
			cout << -1 << endl;
			return 0;
		}
		if(val[r]) ans.pop_back();
		cout << ans.size() << endl;
		for(int i=0;i<ans.size();i++) cout << ans[i]+1 << " ";	cout << endl;
	}

	return 0;
}
