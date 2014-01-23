#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int N=5e4+10;
vector<pii> adj[N];
int vis[N];

void dijkstra(ll* d, int v, int n) {
	for(int i=0;i<=n;i++) {
		d[i] = 1e15;
		vis[i]=0;
	}
	d[v]=0;
	priority_queue<pii> q;
	q.push(pii(0, v));
	while(!q.empty()) {
		v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(int i=0;i<adj[v].size();i++) {
			int u = adj[v][i].first;
			ll dist = adj[v][i].second;
			if(d[u] > d[v] + dist) {
				d[u] = d[v] + dist;
				q.push(pii(-d[u], u));
			}
		}
	}
}

ll d[4][N], dist[N];

int main() {
	int n, m, v[4], ord[4];
	cin>>n>>m;
	v[0]=1;
	for(int i=1;i<=3;i++) cin>>v[i];
	for(int i=0;i<m;i++) {
		int a, b, d;
		cin>>a>>b>>d;
		adj[a].push_back(pii(b, d));
		adj[b].push_back(pii(a, d));
	}
	for(int i=1;i<=n;i++) adj[i].push_back(pii(n+1, 0));
	for(int i=0;i<4;i++) {
		ord[i]=i;
		dijkstra(d[i], v[i], n);
	}
	ll ans=1e15;
	do {
		adj[0].clear();
		adj[n+1].clear();
		for(int i=1;i<=n;i++) {
			adj[0].push_back(pii(i, d[ord[0]][i] + d[ord[1]][i]));
			adj[i].back().second = d[ord[2]][i] + d[ord[3]][i];
		}
		dijkstra(dist, 0, n+1);
		ans = min(ans, dist[n+1]);
	} while(next_permutation(ord, ord+3));
	cout << ans << endl;
	return 0;
}
