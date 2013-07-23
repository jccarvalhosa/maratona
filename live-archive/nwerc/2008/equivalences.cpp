#include <iostream>
#include <vector>
using namespace std;

vector<int> g[22222], ginv[22222];

int a, b, n, m, ge[22222], gs[22222], vis[22222], comp[22222], ord[22222];

void dfs(int v) {
	vis[v]=1;
	for(int i=0;i<g[v].size();i++) {
		int u = g[v][i];
		if(!vis[u]) dfs(u);
	}
	ord[a++]=v;
}

void dfsinv(int v) {
	vis[v]=1;
	comp[v]=a;
	for(int i=0;i<ginv[v].size();i++) {
		int u = ginv[v][i];
		if(!vis[u]) dfsinv(u);
	}
}

void cfconexas() {
	a=0;
	for(int i=0;i<n;i++) vis[i]=0;
	for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
	a=0;
	for(int i=0;i<n;i++) vis[i]=0;
	for(int i=n-1;i>=0;i--) if(!vis[ord[i]]) dfsinv(ord[i]), a++;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=0;i<n;i++) {
			g[i].clear();
			ginv[i].clear();
		}
		for(int i=0;i<m;i++) {
			cin>>a>>b; a--; b--;
			g[a].push_back(b);
			ginv[b].push_back(a);
		}
		cfconexas();
		if(a==1) {
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<a;i++) ge[i] = gs[i] = 0;
		for(int v=0;v<n;v++) for(int i=0;i<g[v].size();i++) {
			int u = g[v][i];
			if(comp[v] != comp[u]) {
				gs[comp[v]]++;
				ge[comp[u]]++;
			}
		}
		int ne=0, ns=0;
		for(int i=0;i<a;i++) {
			if(ge[i]==0) ne++;
			if(gs[i]==0) ns++;
		}
		cout<<max(ne, ns)<<endl;
	}
	return 0;
}
