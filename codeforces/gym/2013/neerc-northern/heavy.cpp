#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 111111;
const int INF = (int)1e9;
string w[N], s[N], p[N];
int ss[N], pp[N], mark[N];

int src, snk, E;
int Q[N], fin[N], pro[N], dist[N];
int flow[N], cap[N], nn[N], to[N];

void init(int n) {
	E=src=0;
	snk=n;
	for(int i=0;i<=n;i++) fin[i]=-1;
}

void create_edge(int u, int v, int _cap) {
	to[E] = v, cap[E] = _cap, flow[E] = 0;
	nn[E] = fin[u], fin[u] = E++;
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
		for(i=fin[u]; i>=0; i=nn[i]) {
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
	for(int &e=pro[u], v, df; e>=0; e=nn[e]) {
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
	ifstream in("heavy.in");
	ofstream out("heavy.out");
	int n, k;
	in>>n>>k;
	for(int i=0;i<n;i++) {
		in>>w[i];
		p[i] = w[i].substr(0, k);
		s[i] = w[i].substr(w[i].size()-k, k);
	}
	sort(p, p+n);
	int np = unique(p, p+n) - p;
	sort(s, s+n);
	int ns = unique(s, s+n) - s;
	for(int i=0;i<n;i++) {
		pp[i] = lower_bound(p, p+np, w[i].substr(0, k)) - p;
		ss[i] = lower_bound(s, s+ns, w[i].substr(w[i].size()-k, k)) - s;
	}
	init(np+ns+1);
	for(int i=1;i<=np;i++) add(src, i, 1);
	for(int i=1;i<=ns;i++) add(np+i, snk, 1);
	for(int i=0;i<n;i++) add(1+pp[i], np+1+ss[i], 1);
	out << dinitz() << endl;
	for(int i=0;i<np;i++) if(dist[i+1]==-1) {
		vector<int> ans;
		for(int j=0;j<n;j++) if(!mark[j]) if(pp[j]==i) ans.push_back(j+1), mark[j]=1;
		out << ans.size();
		for(int j=0;j<ans.size();j++) out<<" "<<ans[j]; out<<endl;
	}
	for(int i=0;i<ns;i++) if(dist[i+np+1]!=-1) {
		vector<int> ans;
		for(int j=0;j<n;j++) if(!mark[j]) if(ss[j]==i) ans.push_back(j+1), mark[j]=1;
		out << ans.size();
		for(int j=0;j<ans.size();j++) out<<" "<<ans[j]; out<<endl;
	}
	return 0;
}
