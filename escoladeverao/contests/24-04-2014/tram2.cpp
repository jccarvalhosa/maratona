#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n;
const int N=1e5+10;
const int L=30;
vector<pii> adj[N];
vector<int> ord;
int pai[N][L], dep[N];
ll d[N];

void dfs(int v, int p) {
	pai[v][0]=p;
	if(p==v) dep[v]=0;
	else dep[v] = dep[p]+1;
	if(adj[v].size() == 1) ord.push_back(v);
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		int dist = adj[v][i].second;
		if(u!=p) {
			d[u] = d[v] + dist;
			dfs(u, v);
		}
	}
}

void go(int v, int p) {
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i].first;
		int dist = adj[v][i].second;
		if(u!=p) {
			d[u] = d[v] + dist;
			go(u, v);
		}
	}
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i=L-1;i>=0;i--) if(dep[a]-(1<<i) >= dep[b]) a = pai[a][i];
	if(a == b) return a;
	for(int i=L-1;i>=0;i--) if(pai[a][i] != pai[b][i]) a=pai[a][i], b=pai[b][i];
	return pai[a][0];
}

int divisor(int a) {
	int v1 = ord[0];
	for(int i=1;i<=a;i++) v1 = lca(v1, ord[i]);	
	int v2 = ord[a+1];
	for(int i=a+2;i<ord.size();i++) v2 = lca(v2, ord[i]);
	return lca(v1, v2);
}

ll dist(int a, int b) { return d[a] + d[b] - 2*d[lca(a, b)]; }

int main() {
	cin>>n;
	for(int i=0;i<n-1;i++) {
		int a, b, d;
		cin>>a>>b>>d;
		adj[a].push_back(pii(b, d));
		adj[b].push_back(pii(a, d));
	}
	int r;
	for(int i=1;i<=n;i++) if(adj[i].size()!=1) { r=i; break; }
	d[r]=0;
	dfs(r, r);
	for(int i=1;i<L;i++) for(int j=1;j<=n;j++) pai[j][i] = pai[pai[j][i-1]][i-1];
	ll sum=0;
	int k = ord.size();
	for(int i=0;i<k-1;i+=2) sum += dist(ord[i], ord[i+1]);
	if(k%2==0) cout<<sum<<endl;
	else {
		ll dmin=sum;
		for(int i=k-2;i>=0;i--) {
			if(i&1) sum += dist(ord[i-1], ord[i+1]) - dist(ord[i-1], ord[i]);
			else sum += dist(ord[i+2], ord[i+1]) - dist(ord[i+2], ord[i]);
			dmin = min(dmin, sum);
		}
		cout<<dmin<<endl;
	}
	if(k%2==0) {
		int v = divisor(k/2-1);
		d[v]=0;
		go(v, v);
		sum=0;
		for(int i=0;i<k;i++) sum += d[ord[i]];
		cout<<sum<<endl;
	}
	else {
		ll dmax=0;
		int v = divisor(k/2);
		d[v]=0;
		go(v, v);
		sum=0;
		for(int i=0;i<k;i++) sum += d[ord[i]];
		ll dmin=1e18;
		for(int i=0;i<=k/2;i++) dmin = min(dmin, d[ord[i]]);
		dmax = max(dmax, sum-dmin);
		v = divisor(k/2-1);
		d[v]=0;
		go(v, v);
		sum=0;
		for(int i=0;i<k;i++) sum += d[ord[i]];
		dmin=1e18;
		for(int i=k/2;i<k;i++) dmin = min(dmin, d[ord[i]]);
		dmax = max(dmax, sum-dmin);
		cout<<dmax<<endl;
	}
	return 0;
}
