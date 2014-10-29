#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
vector<int> adj[N];
int cont[N], dist[N];
int n, k, a, b;

long long bfs() {
	queue<int> q;
	dist[0]=0;
	for(int i=1;i<n;i++) dist[i]=-1;
	q.push(0);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int i=0;i<adj[v].size();i++) {
			int u = adj[v][i];
			if(dist[u]==-1) {
				dist[u] = dist[v]+1;
				if(u==n-1) return dist[u];
				q.push(u);
			}
		}
	}
	return 1e9;
}

long long solve() {
	for(int i=0;i<n;i++) cont[i]=0;
	for(int i=0;i<adj[0].size();i++) cont[adj[0][i]]++;
	vector<int> naosei;
	for(int i=1;i<n;i++) naosei.push_back(i);
	int d=1;
	while(1) {
		vector<int> novo;
		int sz=naosei.size();
		int f = n - sz;
		vector<int> found;
		for(int i=0;i<naosei.size();i++) {
			int v = naosei[i];
			if(cont[v] == f) novo.push_back(v);
			else {
				if(v==n-1) return d;
				found.push_back(v);
			}
		}
		for(int i=0;i<found.size();i++) {
			int v = found[i];
			for(int j=0;j<adj[v].size();j++) {
				cont[adj[v][j]]++;
			}
		}
		d++;
		if(naosei.size() == novo.size()) break;
		naosei = novo;
	}
	return 1e9;
}

int main() {
	while(scanf("%d%d%d%d", &n, &k, &a, &b) != EOF) {
		for(int i=0;i<n;i++) adj[i].clear();
		while(k--) {
			int x, y;
			scanf("%d%d", &x, &y); x--; y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		cout << min(solve()*b, bfs()*a) << endl;
	}
	return 0;
}
