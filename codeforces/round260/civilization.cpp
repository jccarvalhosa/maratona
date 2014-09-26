#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N=3e5+1;
vector<int> adj[N];
int vis[N], pi[N], diam[N], b, d, color, comp;

int find(int v) { return pi[pi[v]] == pi[v] ? pi[v] : pi[v] = find(pi[v]); }

void dfs(int v, int dist) {
	vis[v] = color;
	if(dist > d) {
		b = v;
		d = dist;
	}
	pi[v] = comp;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(vis[u] != color) dfs(u, dist+1);
	}
}

int main() {
	int n, m, q;
	cin>>n>>m>>q;
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) {
		b=i, d=0, comp=i;
		color = 2*i;
		dfs(i, 0);
		int a=b;
		d=0;
		color = 2*i+1;
		dfs(b, 0);
		diam[i] = d;
	}
	while(q--) {
		int t;
		scanf("%d", &t);
		if(t==1) {
			int x;
			scanf("%d", &x);
			printf("%d\n", diam[find(x)]);
		}
		else {
			int x, y;
			scanf("%d%d", &x, &y);
			int px = find(x);
			int py = find(y);
			if(px != py) {
				pi[px] = py;
				diam[py] = max(max(diam[px], diam[py]), (diam[px]+1)/2 + (diam[py]+1)/2 + 1);
			}
		}
	}
	return 0;
}
