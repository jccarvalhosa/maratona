#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000000
#define N 25010
using namespace std;
typedef pair<int, int> pii;

int n, m, c, d[N], vis[N];
pii pos[1010], pai[N];
vector<pii> dist[N], edge[N];
vector<int> adj[N];

void dijkstra(int v) {
	int i, u, k;
	priority_queue<pii> q;
	for(i=1;i<=n;i++) d[i]=INF;
	d[v]=0;
	q.push(pii(0, v));
	while(!q.empty()) {
		v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(i=0;i<dist[v].size();i++) {
			u = dist[v][i].first;
			k = dist[v][i].second;
			if(d[u]>d[v]+k) {
				d[u] = d[v]+k;
				q.push(pii(-d[u], u));
			}
		}
	}
}

void dfs(int v, pii p) {
	int i, u;
	vis[v]=1;
	pai[v] = p;
	for(i=0;i<edge[v].size();i++) if(edge[v][i].second) {
		u = edge[v][i].first;
		if(!vis[u]) dfs(u, pii(v, i));
	}
}

int flow(int a, int b) {
	int v, u, i, f=0;
	if(a==b) return 1;
	for(i=0;i<=n;i++) edge[i].clear();
	for(i=a;i<=b;i++) edge[0].push_back(pii(pos[i].second, 1));
	for(v=1;v<=n;v++) for(i=0;i<adj[v].size();i++) {
		u = adj[v][i];
		edge[v].push_back(pii(u, 1));
	}
	while(1) {
		for(i=0;i<=n;i++) vis[i]=0;
		dfs(0, pii(-1, -1));
		if(!vis[1]) break;
		f++;
		for(i=1;i!=0;i=pai[i].first) {
			edge[pai[i].first][pai[i].second].second = 0;
			edge[i].push_back(pii(pai[i].first, 1));
		}
	}
	return f;
}

int main() {
	int i, f, a, b, t, ans=0;
	cin>>n>>m>>c;
	for(i=0;i<m;i++) {
		cin>>a>>b>>t;
		dist[a].push_back(pii(b, t));
		dist[b].push_back(pii(a, t));
	}
	dijkstra(1);
	for(a=1;a<=n;a++) for(i=0;i<dist[a].size();i++) {
		b = dist[a][i].first;
		t = dist[a][i].second;
		if(d[b]==d[a]-t) adj[a].push_back(b);
	}
	for(i=0;i<c;i++) {
		cin>>a;
		pos[i] = pii(d[a], a);
	}
	sort(pos, pos+c);
	for(i=0;i<c;i=f) {
		f=i;
		while(f<c && pos[f].first==pos[i].first) f++;
		ans += flow(i, f-1);
	}
	cout<<ans<<endl;
	return 0;
}
