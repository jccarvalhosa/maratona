#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
	
int n, m, match[2222], d[2222];
vector<int> adj[2222];

int bfs() {
    queue<int> q;
	for(int i=0;i<=n;i++) {
		if(!match[i]) {
			d[i]=0;
			q.push(i);
		}
		else d[i]=INF;
	}
	d[0]=INF;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		if(v==0) continue;
		for(int i=0;i<adj[v].size();i++) {
			int u = adj[v][i];
			if(d[match[u]] == INF) {
				d[match[u]] = d[v]+1;
				q.push(match[u]);
			}
		}
	}
	return d[0] != INF;
}

int dfs(int v) {
	if(!v) return 1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(d[match[u]] == d[v]+1 && dfs(match[u])) {
			match[v] = u;
			match[u] = v;
			return 1;
		}
	}
	d[v] = INF;
	return 0;
}

int hopcroft_karp() {
	int matching=0;
	while(bfs()) for(int i=1;i<=n;i++) if(!match[i] && dfs(i)) matching++;
	return matching;
}

int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i=0;i<=2*n;i++) {
			adj[i].clear(); 
			match[i] = 0;
			d[i] = INF;
		}
		for(int i=0;i<m;i++) {
			int a, b;
			cin>>a>>b;
			adj[a].push_back(n+b);
		}
		printf("%d\n", n - hopcroft_karp());
	}
	return 0;
}
