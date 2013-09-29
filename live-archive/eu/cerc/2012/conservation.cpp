#include<iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int l[111111];
vector <int> adj[111111];
queue <int> q[3];
int g[3][111111];
int c[3];
int cnt, n;

void go(int k, int idx) {
	if(cnt == n) return;
	while(!q[k].empty()) {
		int u = q[k].front();
		cnt++;
		q[k].pop();
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i];
			g[idx][v]--;
			if(g[idx][v] == 0) q[l[v]].push(v);
		}
	}
	c[idx]++;
	if(k == 1) go(2,idx);
	else go(1,idx);
}

int main() {
	int t, m, a, b;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		c[1] = c[2] = 0;
		for(int i=0;i<n;i++) {
			cin >> l[i];
			g[1][i] = g[2][i] = 0;
			adj[i].clear();
		}
		for(int i=0;i<m;i++) {
			cin >> a >> b;
			a--; b--;
			adj[a].push_back(b);
			g[1][b]++;
			g[2][b]++;
		}
		cnt = 0;
		for(int i=0;i<n;i++) if(!g[1][i]) q[l[i]].push(i);
		go(1,1);
		cnt = 0;
		for(int i=0;i<n;i++) if(!g[2][i]) q[l[i]].push(i);
		go(2,2);
		cout << (min(c[1],c[2])-1) << endl;
	}
	return 0;
}
