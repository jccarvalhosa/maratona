#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000000000000ll
typedef long long ll;
typedef pair<int, int> pii;

int n, N;
ll cont[5000], total, best;
vector<pii> adj[5000];

void go(int v, int p) {
	int i, u;
	n++;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i].first;
		if(u!=p) go(u, v);
	}
}

ll dfs(int v, int p, ll dist) {
	int i, u;
	ll w, ret=dist;
	cont[v]=1;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i].first;
		w = adj[v][i].second;
		if(u!=p) {
			ret += dfs(u, v, dist+w);
			cont[v] += cont[u];
			total += w*cont[u]*(n-cont[u]);
		}
	}
	return ret;
}

void find(int v, int p, ll sum) {
	best = min(best, sum);
	int i, u;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i].first;
		ll w = adj[v][i].second;
		if(u != p) find(u, v, sum + w*(n-2*cont[u]));
	}
}

int main() {
	int i, na, nb, a[5000], b[5000], w[5000];
	cin>>N;
	for(i=0;i<N-1;i++) {
		cin>>a[i]>>b[i]>>w[i];
		a[i]--; b[i]--;
		adj[a[i]].push_back(pii(b[i], w[i]));
		adj[b[i]].push_back(pii(a[i], w[i]));
	}
	ll ans=INF;
	for(i=0;i<N-1;i++) {
		n=total=0;
		go(a[i], b[i]);
		na=n;
		nb=N-n;
		
		n=na;
		best = dfs(a[i], b[i], 0);
		find(a[i], b[i], best);
		total += best*nb;
		
		n=nb;
		best = dfs(b[i], a[i], 0);
		find(b[i], a[i], best);
		total += best*na;

		ans = min(ans, total + 1ll*na*nb*w[i]);
	}
	cout<<ans<<endl;
	return 0;
}
