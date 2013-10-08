#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef pair<ll, int> pli;

int n, m;

void dijkstra(vector<vp> &adj, vector<ll> &d, int v) {
	d[v]=0;
	vector<int> vis(n+1, 0);
	priority_queue<pli> q;
	q.push(pli(0, v));
	while(!q.empty()) {
		v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(int i=0;i<adj[v].size();i++) {
			int u = adj[v][i].first;
			int delta = adj[v][i].second;
			if(d[u] > d[v]+delta) {
				d[u] = d[v]+delta;
				q.push(pli(-d[u], u));
			}
		}
	}
}

int main() {
	int T;
	while(cin>>T && !cin.eof()) while(T--) {
		cin>>n>>m;
		vector<vp> adj(n+1);
		vector<ll> d1(n+1, (ll)1e15);
		vector<ll> d2(n+1, (ll)1e15);
		for(int i=0;i<m;i++) {
			int a, b, c;
			cin>>a>>b>>c;
			adj[a].push_back(pii(b, c));
			adj[b].push_back(pii(a, c));
		}
		dijkstra(adj, d1, 1);
		dijkstra(adj, d2, 2);
		vector<ll> d3(n+1), d4(n+1);
		for(int i=1;i<=n;i++) {
			d3[i] = d1[i]-d2[i];
			d4[i] = d1[i]+d2[i];
		}
		sort(d3.begin()+1, d3.end());
		sort(d4.begin()+1, d4.end());
		int med = (1+n)/2;
		double x = (d4[med] + d3[med])/2.0;
		double y = (d4[med] - d3[med])/2.0;
		double ans=0;
		for(int i=1;i<=n;i++) {
			ans += max(fabs(d1[i]-x), fabs(d2[i]-y))/n;
		}
		printf("%.12lf\n", ans);
	}
	return 0;
}
