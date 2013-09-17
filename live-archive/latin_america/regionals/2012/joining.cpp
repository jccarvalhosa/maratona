#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
#define MAX 100000

int mod(int a) { return a > 0 ? a : -a; }

int N, cc, dep, r, i, vis[MAX], comp[MAX], root[MAX], dist[MAX], pos[MAX], tam[MAX];
int pai[MAX][100];
vector<int> adj[MAX];
pii edge[MAX];

void dfs(int v, int p) {
	int i, u;
	vis[v] = ++dep;
	pai[v][0] = p;
	comp[v]=cc;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i];
		if(!vis[u]) dfs(u, v);
		else if(u != p && vis[u] < vis[v]) edge[cc] = pii(v, u);
	}
}

void dfs(int v, int p, int d) {
	int i, u;
	vis[v]=1;
	pai[v][0] = p;
	root[v]=r;
	dist[v]=d;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i];
		if(!vis[u]) dfs(u, v, d+1);
	}
}

int lca(int a, int b) {
	int i, loga=1;
	if(dist[a] < dist[b]) swap(a, b);
	while((1<<loga) <= dist[a]) loga++; loga--;
	for(i=loga;i>=0;i--) if(dist[a]-(1<<i) >= dist[b]) a = pai[a][i];
	if(a == b) return a;
	for(i=loga;i>=0;i--) if(pai[a][i] != pai[b][i]) a=pai[a][i], b=pai[b][i];
	return pai[a][0];
}

int ans(int a, int b) { 
	if(comp[a] != comp[b]) return -1;
	if(root[a] == root[b]) return dist[a]+dist[b]-2*dist[lca(a, b)];
	int v, dm;
	v = mod(pos[root[a]]-pos[root[b]]);
	dm = min(v, tam[comp[a]] - v);
	return dist[a]+dist[b]+dm;
}

int main() {
	int Q, i, j, f;
	while(scanf("%d", &N) != EOF) {
		// monta o grafo
		for(i=0;i<N;i++) adj[i].clear();
		for(i=0;i<N;i++) {
			scanf("%d", &f); f--;
			adj[i].push_back(f);
			adj[f].push_back(i);
		}
		// acha cada componente conexa e seu ciclo
		cc=0;
		for(i=0;i<N;i++) vis[i]=0;
		for(i=0;i<N;i++) if(!vis[i]) {
			edge[cc]=pii(i, i);
			dep=0;
			dfs(i, -1);
			cc++;
		}
		// acha as arvores
		for(i=0;i<N;i++) {
			vis[i]=0;
			root[i]=-1;
		}
		for(i=0;i<cc;i++) {
			tam[i]=0;
			for(j=edge[i].first; ;j=pai[j][0]) {
				pos[j] = tam[i]++;
				root[j] = j;
				vis[j]=1;
				if(j == edge[i].second) break;
			}
		}
		for(i=0;i<N;i++) if(root[i] == i) {
			r=i;
			dfs(i, i, 0);
		}
		//prepara o lca
		for(j=1;(1<<j)<N;j++) for(i=0;i<N;i++) pai[i][j]=pai[pai[i][j-1]][j-1];	
		// responde as queries
		scanf("%d", &Q);
		while(Q--) {
			scanf("%d%d", &i, &f);
			printf("%d\n", ans(i-1, f-1));
		}
	}
	return 0;
}
