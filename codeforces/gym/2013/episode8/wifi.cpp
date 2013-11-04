#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N=555;
const int INF = (int)1e9;
int n, adj[N][N], vis[N], x[N], y[N], r[N], s[N];

int src, snk, E;
int Q[N], fin[N], pro[N], dist[N];
int flow[N*N], cap[N*N], ne[N*N], to[N*N];

void init(int n) {
	E=src=0;
	snk=n;
	for(int i=0;i<=n;i++) fin[i]=-1;
}

void create_edge(int u, int v, int _cap) {
	to[E] = v, cap[E] = _cap, flow[E] = 0;
	ne[E] = fin[u], fin[u] = E++;
}

void add(int u, int v, int _cap) {
	create_edge(u, v, _cap);
	create_edge(v, u, 0);
}

bool bfs() {
	int st, en, i, u, v;
	for(i=0;i<=snk;i++) dist[i]=-1;
	dist[src] = st = en = 0;
	Q[en++] = src;
	while(st < en) {
		u = Q[st++];
		for(i=fin[u]; i>=0; i=ne[i]) {
			v = to[i];
			if(flow[i] < cap[i] && dist[v]==-1) {
				dist[v] = dist[u]+1;
				Q[en++] = v;
			}
		}
	}
	return dist[snk]!=-1;
}

int dfs(int u, int fl) {
	if(u==snk) return fl;
	for(int &e=pro[u], v, df; e>=0; e=ne[e]) {
		v = to[e];
		if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
			df = dfs(v, min(cap[e]-flow[e], fl));
			if(df>0) {
				flow[e] += df;
				flow[e^1] -= df;
				return df;
			}
		}
	}
	return 0;
}

int dinitz() {
	int ret=0, df;
	while(bfs()) {
		for(int i=0;i<=snk;i++) pro[i] = fin[i];
		while(1) {
			df = dfs(src, INF);
			if(df) ret += df;
			else break;
		}
	}
	return ret;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i]>>y[i]>>r[i]>>s[i];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(r[i]*r[i] >= (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])) adj[i][j]=1;
	init(n+1);
	for(int i=0;i<n;i++) {
		if(s[i]>0) add(0, i+1, s[i]);
		else add(i+1, snk, -s[i]);
	}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j && adj[i][j]) add(i+1, j+1, INF);
	int sum=0;
	for(int i=0;i<n;i++) if(s[i]>0) sum += s[i];
	cout << sum-dinitz() << endl;
	return 0;
}
