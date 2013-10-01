#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define M 4444

pii vote[M][2];
int t, n, N, v[M], vis[M], ord[M], comp[M];
vector<pii> adj[M][2];
vector<int> g[M], ginv[M];

int dfs_ini(int p, int x) {
	if(v[p] != -1 && v[p] != x) return 0;
	if(v[p] == x) return 1;
	v[p] = x;
	for(int i=0;i<adj[p][x].size();i++) if(!dfs_ini(adj[p][x][i].first, adj[p][x][i].second)) return 0;
	return 1;
}

void dfs(int v) {
	vis[v]=1;
	for(int i=0;i<g[v].size();i++) {
		int u=g[v][i];
		if(!vis[u]) dfs(u);
	}
	ord[t++] = v;
}

void dfsinv(int v) {
	vis[v]=1;
	comp[v]=t;
	for(int i=0;i<ginv[v].size();i++) {
		int u=ginv[v][i];
		if(!vis[u]) dfsinv(u);
	}
}

void cfconexas() {
	t=0;
	for(int i=0;i<N;i++) vis[i]=0;
	for(int i=0;i<N;i++) if(!vis[i]) dfs(i);
	t=0;
	for(int i=0;i<N;i++) vis[i]=0;
	for(int i=N-1;i>=0;i--) if(!vis[ord[i]]) dfsinv(ord[i]), t++;
}

int main() {
	int m;
	while(scanf("%d %d", &n, &m) != EOF) {
		for(int i=1;i<=n;i++) v[i] = -1;
		for(int i=1;i<=n;i++) for(int j=0;j<2;j++) adj[i][j].clear();
		for(int i=0;i<m;i++) {
			int a, b;
			cin>>a>>b;
			int va = a>0;
			int vb = b>0;
			if(a<0) a=-a;
			if(b<0) b=-b;
			vote[i][0] = pii(a, va);
			vote[i][1] = pii(b, vb);
			adj[a][1-va].push_back(pii(b, vb));
			adj[b][1-vb].push_back(pii(a, va));
		}
		for(int i=1;i<=n;i++) vis[i]=0;
		if(!dfs_ini(1, 1)) {
			cout<<"no"<<endl;
			continue;
		}
		N = 2*n+2;
		for(int i=0;i<N;i++) {
			g[i].clear();
			ginv[i].clear();
		}
		for(int i=0;i<m;i++) {
			int a = vote[i][0].first;
			int va = vote[i][0].second;
			int b = vote[i][1].first;
			int vb = vote[i][1].second;
			if(v[a] == -1 && v[b] == -1) {
				int nota = 2*a + (1-va);
				a = 2*a + va;
				int notb = 2*b + (1-vb);
				b = 2*b + vb;
				g[nota].push_back(b);
				g[notb].push_back(a);
				ginv[a].push_back(notb);
				ginv[b].push_back(nota);
			}
		}
		cfconexas();
		int i;
		for(i=1;i<=n;i++) if(comp[2*i] == comp[2*i+1]) break;
		if(i <= n) cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
	return 0;
}
