#include <bits/stdc++.h>
using namespace std;

const int N=2e5+7;
int val[N], vis[N], aux[N];
vector<int> adj[N];
const int INF=1e9;

int dfs(int v, int x) {
	aux[v]=x;
	if(val[v] != -1 && aux[v] != val[v]) return INF;
	int ret=x;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(aux[u] != -1 && aux[u] != 1-x) return INF;
		if(aux[u] == -1) {
			ret += dfs(u, 1-x);
			if(ret >= INF) return INF;
		}
	}
	return ret;
}

void clean(int v) {
	aux[v]=-1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(aux[u] != -1) clean(u);
	}
}

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		val[i]=-1;
		aux[i]=-1;
	}
	while(m--) {
		int a, b, s;
		scanf("%d%d%d", &a, &b, &s);
		if(s==0) {
			if(val[a] == 1 || val[b] == 1) {
				cout << "impossible" << endl;
				return 0;
			}
			val[a]=val[b]=0;
		}
		else if(s==2) {
			if(val[a] == 0 || val[b] == 0) {
				cout << "impossible" << endl;
				return 0;
			}
			val[a]=val[b]=1;
		}
		else {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(aux[i]==-1) {
		int v0 = dfs(i, 0);
		clean(i);
		int v1 = dfs(i, 1);
		clean(i);
		if(v0 == INF && v1 == INF) {
			cout << "impossible" << endl;
			return 0;
		}
		if(v0 < v1) ans += dfs(i, 0);
		else ans += dfs(i, 1);
	}
	cout << ans << endl;
	return 0;
}
