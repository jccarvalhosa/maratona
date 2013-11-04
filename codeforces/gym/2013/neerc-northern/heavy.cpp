#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 111111;
string w[N], s[N], p[N];
int snk, ss[N], pp[N], mark[N], vis[N], fa[N], ii[N];
vector<int> adj[N];

int dfs(int v, int f, int fi) {
	vis[v]=1;
	fa[v]=f;
	ii[v]=fi;
	if(v==snk) return 1; 
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(!vis[u] && dfs(u, v, i)) return 1;
	}
	return 0;
}

int ford_fulkerson() {
	int flow=0;
	while(1) {
		for(int i=0;i<=snk;i++) vis[i]=0;
		if(!dfs(0, 0, 0)) break;
		for(int i=snk;i;i=fa[i]) {
			swap(adj[fa[i]][ii[i]], adj[fa[i]].back());
			adj[fa[i]].pop_back();
			adj[i].push_back(fa[i]);
		}
		flow++;
	}
	return flow;
}

int main() {
	ifstream in("heavy.in");
	ofstream out("heavy.out");
	int n, k;
	in>>n>>k;
	for(int i=0;i<n;i++) {
		in>>w[i];
		p[i] = w[i].substr(0, k);
		s[i] = w[i].substr(w[i].size()-k, k);
	}
	sort(p, p+n);
	int np = unique(p, p+n) - p;
	sort(s, s+n);
	int ns = unique(s, s+n) - s;
	for(int i=0;i<n;i++) {
		pp[i] = lower_bound(p, p+np, w[i].substr(0, k)) - p;
		ss[i] = lower_bound(s, s+ns, w[i].substr(w[i].size()-k, k)) - s;
	}
	snk=np+ns+1;
	for(int i=1;i<=np;i++) adj[0].push_back(i);
	for(int i=1;i<=ns;i++) adj[np+i].push_back(snk);
	for(int i=0;i<n;i++) adj[1+pp[i]].push_back(np+1+ss[i]);
	out << ford_fulkerson() << endl;
	for(int i=0;i<np;i++) if(!vis[i+1]) {
		vector<int> ans;
		for(int j=0;j<n;j++) if(!mark[j]) if(pp[j]==i) ans.push_back(j+1), mark[j]=1;
		out << ans.size();
		for(int j=0;j<ans.size();j++) out<<" "<<ans[j]; out<<endl;
	}
	for(int i=0;i<ns;i++) if(vis[i+np+1]) {
		vector<int> ans;
		for(int j=0;j<n;j++) if(!mark[j]) if(ss[j]==i) ans.push_back(j+1), mark[j]=1;
		out << ans.size();
		for(int j=0;j<ans.size();j++) out<<" "<<ans[j]; out<<endl;
	}
	return 0;
}
