#include <cstdio>
#include <algorithm>
#include <queue>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

int N, vis[1000];
vector<pii> adj[1000];

int prim() {
	int i, v, d, sum=0;
	priority_queue<pii> q;
	for(i=0;i<N;i++) vis[i]=0;
	q.push(mp(0, 0));
	while(!q.empty()) {
		v=q.top().second;
		d=-q.top().first;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		sum+=d;
		for(i=0;i<adj[v].size();i++) q.push(mp(-adj[v][i].second, adj[v][i].first));
	}
	return sum;
}

int main() {
	int M, a, b, i, d;
	scanf("%d%d", &N, &M);
	for(i=0;i<M;i++) {
		scanf("%d%d%d", &a, &b, &d);
		adj[a].pb(mp(b, d));
		adj[b].pb(mp(a, d));
	}
	printf("%d", prim());
	return 0;
}
