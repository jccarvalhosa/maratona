#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Edge { 
	int from, to, cost, id; 
	Edge(int from=0, int to=0, int cost=0, int id=0) : from(from), to(to), cost(cost), id(id) {}
};

const int N=2e3+10;
const int M=1e4+10;
char owner[N];
int n, a[N], best[N], step[N], lose[N], dist[N][2*N], back[N][2*N], ans[N];
vector<Edge> adj[N];
Edge e[M];

void answer(int v) {
	for(int i=step[v];i>0;i--) {
		int u = e[back[v][i]].from;
		ans[u] = back[v][i];
		v = u;
	}
	for(int i=1;i<=n;i++) {
		if(owner[i]=='A') ans[i]=0;
		else if(!ans[i]) ans[i]=adj[i][0].id;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
}

int canLose() {
	for(int i=1;i<=n;i++) if(step[i] >= n && lose[i]) {
		cout << "Lose" << endl;
		answer(i);
		return 1;
	}
	return 0;
}

int canDraw() {
	for(int i=1;i<=n;i++) if(step[i] >= n && !lose[i]) {
		cout << "Draw" << endl;
		answer(i);
		return 1;
	}
	return 0;
}

int main() {
	freopen("mean.in", "r", stdin);
	freopen("mean.out", "w", stdout);
	int m, s;
	scanf("%d %d %s %d", &n, &m, owner+1, &s);;
	for(int i=1;i<=m;i++) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		e[i] = Edge(a, b, d, i);
		adj[a].push_back(e[i]);
	}
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		if(a[i]) {
			adj[i].clear();
			adj[i].push_back(e[a[i]]);
		}
	}
	for(int i=1;i<=n;i++) for(int j=0;j<=2*n;j++) dist[i][j]=1e9;
	for(int i=1;i<=n;i++) best[i]=1e9;
	dist[s][0]=0;
	for(int j=0;j<=2*n;j++) for(int i=1;i<=n;i++) {
		if(dist[i][j]==1e9) continue;
		if(dist[i][j] <= best[i]) {
			lose[i] = dist[i][j] < best[i];
			best[i] = dist[i][j];
			step[i] = j;
		}
		for(int k=0;k<adj[i].size();k++) {
			int v = adj[i][k].to;
			int d = adj[i][k].cost;
			int id = adj[i][k].id;
			if(dist[v][j+1] > dist[i][j]+d) {
				dist[v][j+1] = dist[i][j] + d;
				back[v][j+1] = id;
			}
		}
	}
	if(!canLose() && !canDraw()) {
		cout << "Win" << endl;
	}
	return 0;
}
