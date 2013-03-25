#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef long long ll;

priority_queue<pii> q;
vector<pii> adj[10000];
int n, m, best[10000], toll[10000], vis[10000];

ll solve() {
	priority_queue<pip> q;
	int u, v, w, i, j;
	ll ans = 0;
	if(toll[0] != 0) return INF;
	for(i=0;i<n;i++) {
		vis[i]=0;
		best[i]=INF;
	}
	best[0]=0;
	for(v=0;v<n;v++) {
		for(i=0;i<adj[v].size();i++) {
			u = adj[v][i].first;
			w = adj[v][i].second;
			if(toll[v]>toll[u]) {
				if(toll[v] >= toll[u]+w) {
					ans += toll[v]-toll[u]-w;
					best[v]=0;
				}
				else best[v] = min(best[v], toll[u]+w-toll[v]);
			}
		}
		q.push(pip(-toll[v], pii(-best[v], v)));
	}
	while(!q.empty()) {
		w = -q.top().second.first;
		v = q.top().second.second;
		q.pop();
		if(vis[v]) continue;
		if(w == INF) return INF;
		ans += w;
		vis[v] = 1;
		for(i=0;i<adj[v].size();i++) {
			u = adj[v][i].first;
			w = adj[v][i].second;
			if(toll[v] == toll[u] && best[u] > w) {
				best[u] = w;
				q.push(pip(-toll[u], pii(-best[u], u)));
			}
		}
	}
	return ans;
}

int main() {
	int T, t, i, u, v, w;
	cin>>T;
	for(t=1;t<=T;t++) {
		printf("Case %d: ", t);
		cin>>n>>m;
		for(i=0;i<n;i++) cin>>toll[i];
		for(i=0;i<n;i++) adj[i].clear();
		for(i=0;i<m;i++) {
			cin>>v>>u>>w;
			adj[v].push_back(pii(u, w));
			adj[u].push_back(pii(v, w));
		}
		ll ans = solve();
		if(ans == INF) cout<<"Bad King"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
