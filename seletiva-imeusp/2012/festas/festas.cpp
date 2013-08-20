#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, k;
int vis[1111], grau[1111], cont[1111];
int adj[1111][1111];

void dfs(int a) {
	vis[a]=1;
	for(int i=0;i<grau[a];i++) {
		int b = adj[a][i];
		cont[b]--;
		if(!vis[b] && cont[b]<k) dfs(b);
	}
}

int main() {
	while(scanf("%d%d%d", &n, &m, &k) != EOF) {
		for(int i=1;i<=n;i++) grau[i] = vis[i] = cont[i] = 0;
		for(int i=0;i<m;i++) {
			int a, b;
			cin>>a>>b;
			adj[a][grau[a]++] = b;
			adj[b][grau[b]++] = a;
		}
		for(int i=1;i<=n;i++) cont[i] = grau[i];
		for(int i=1;i<=n;i++) if(cont[i]<k && !vis[i]) dfs(i);
		vector<int> ans;
		for(int i=1;i<=n;i++) if(!vis[i]) ans.push_back(i);
		if(ans.empty()) cout<<0<<endl;
		else {
			cout<<ans[0];
			for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
			cout<<endl;
		}
	}
	return 0;
}
