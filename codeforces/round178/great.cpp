#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000000000000ll
typedef long long ll;
typedef pair<int, int> pii;

int N, n, cont[5000];
ll total, extra, best;
vector<pii> adj[5000];

ll dfs(int v, int p, ll dist) {
	ll ret=dist;
	cont[v]=1;
	n++;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		ll w = adj[v][i].second;
		if(u!=p) {
			ret += dfs(u, v, dist+w);
			cont[v] += cont[u];
		}
	}
	return ret;
}

void find(int v, int p, ll sum) {
	best = min(best, sum);
	total += sum;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		ll w = adj[v][i].second;
		if(u != p) find(u, v, sum + w*(n-2*cont[u]));
	}
}

void look_tree(int v, int p) {
	n=0;
	best = dfs(v, p, 0);
	find(v, p, best);
	extra += best*(N-n);
}

int main() {
	int i, a[5000], b[5000];
	ll w[5000], ans=INF;
	cin>>N;
	for(i=0;i<N-1;i++) {
		cin>>a[i]>>b[i]>>w[i];
		a[i]--; b[i]--;
		adj[a[i]].push_back(pii(b[i], w[i]));
		adj[b[i]].push_back(pii(a[i], w[i]));
	}
	for(i=0;i<N-1;i++) {
		total=extra=0;
		look_tree(a[i], b[i]);
		look_tree(b[i], a[i]);
		extra += w[i]*n*(N-n);
		ans = min(ans, total/2 + extra);
	}
	cout<<ans<<endl;
	return 0;
}
