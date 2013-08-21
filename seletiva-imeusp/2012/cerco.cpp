#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1000000000
typedef pair<int, int> pii;

int n, m, k, a;
vector<int> adj[1111];
int total[1111], d[1111], vis[1111];

void dijkstra(int v) {
	for(int i=1;i<=n;i++) {
		d[i]=INF;
		vis[i]=0;
	}
	priority_queue<pii> q;
	q.push(pii(-total[v], v));
	d[v] = total[v];
	while(!q.empty()) {
		v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(int i=0;i<adj[v].size();i++) {
			int u = adj[v][i];
			if(d[u] > d[v] + total[u]) {
				d[u] = d[v] + total[u];
				q.push(pii(-d[u], u));
			}
		}
	}
}

double exp(double p, int e) {
	if(e==0) return 1;
	if(e%2==0) return exp(p*p, e/2);
	return p*exp(p, e-1);
}

int main() {
	double p;
	int a, b;
	while(scanf("%d", &n) != EOF) {
		cin>>m>>k>>p;
		for(int i=1;i<=n;i++) adj[i].clear();
		for(int i=1;i<=n;i++) total[i]=0;
		for(int i=0;i<m;i++) {
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		cin>>a;
		for(int i=0;i<a;i++) {
			int x;
			cin>>x;
			total[x]++;
		}
		cin>>a>>b;
		dijkstra(a);
		if(d[b] > k) cout<<"0.000"<<endl;
		else printf("%.3lf\n", exp(p, d[b]));
	}
	return 0;
}
