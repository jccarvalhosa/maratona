#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define mp make_pair
#define pb push_back
using namespace std;

int N, d[1002], vis[1002];
vector<pair<int, int> > adj[1002];

void dijkstra(int v) {
	int i, u, delta;
	priority_queue<pair<int, int> > q;
	for(i=0;i<N;i++) d[i] = 1<<20, vis[i]=0;
	d[0]=0;
	q.push(mp(0, 0));
	while(!q.empty()) {
		v=q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(i=0;i<adj[v].size();i++) {
			u = adj[v][i].first;
			delta = adj[v][i].second;
			if(d[u] > d[v] + delta) {
				d[u] = d[v]+delta;
				q.push(mp(-d[u], u));
			}
		}
	}
}

int main() {
	int M, a, b, delta, i;
	scanf("%d%d", &N, &M); N += 2;
	for(i=0;i<M;i++) {
		scanf("%d%d%d", &a, &b, &delta);
		adj[a].pb(mp(b, delta));
		adj[b].pb(mp(a, delta));
	}
	dijkstra(0);
	printf("%d", d[N-1]);
	return 0;
}
