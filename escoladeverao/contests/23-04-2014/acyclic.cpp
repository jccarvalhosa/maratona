#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int N=1e5+10;

vector<pii> adj[N];
vector<int> ans1, ans2;
int n, m, vis[N];

void dfs(int v) {
	vis[v]=1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		int e = adj[v][i].second;
		if(vis[u] == 1) ans2.push_back(e);
		else ans1.push_back(e);
		if(!vis[u]) dfs(u);
	}
	vis[v]=2;
}

int main() {
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int a, b;
		cin>>a>>b;
		adj[a].push_back(pii(b, i));
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	sort(ans1.begin(), ans1.end());
	sort(ans2.begin(), ans2.end());
	if(ans2.size() == 0) cout<<1<<endl;
	else cout<<2<<endl;
	cout<<ans1.size(); for(int i=0;i<ans1.size();i++) cout<<" "<<ans1[i]; cout<<endl;
	if(ans2.size() > 0) cout<<ans2.size(); for(int i=0;i<ans2.size();i++) cout<<" "<<ans2[i]; cout<<endl;
	return 0;
}
