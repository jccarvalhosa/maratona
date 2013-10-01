#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int t[111111], vis[111111], pi[111111], dep[111111], num[111111];
int val[111111];
vector<int> adj[111111];

void dfs(int v, int p, int d) {
	vis[v]=1;
	dep[v] = d;
	pi[v] = p;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(!vis[u]) dfs(u, v, d+1);
	}
}

int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>t[i];
	for(int i=1;i<=n;i++) {
		int a;
		cin>>a;
		num[a]++;
		val[i] = a;
	}
	for(int i=1;i<=n;i++) {
		int a = val[i];
		if(a!=0 && num[a]==1 && t[a] != 1) adj[i].push_back(a);
	}
	for(int i=1;i<=n;i++) dep[i]=-1;
	for(int i=1;i<=n;i++) if(t[i] == 1) dfs(i, -1, 0);
	int p = max_element(dep+1, dep+n+1) - dep;
	vector<int> ans;
	while(p != -1) {
		ans.push_back(p);
		p = pi[p];
	}
	cout<<ans.size()<<endl;
	cout<<ans[0];
	for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
