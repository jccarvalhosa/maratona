#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll v[111111], d[111111];
vector<int> adj[111111];

int overflow=0;

ll mdc(ll a, ll b) { return !b ? a : mdc(b, a%b); }
ll mmc(ll a, ll b) { return a/mdc(a, b)*b; }

void dfs(int x, int p) {
	if(x==0) d[x]=1;
	else {
		ll k = adj[p].size() - 1;
		if(p==0) k++;
		d[x] = d[p]*k;
		if(d[x]/k != d[p]) overflow=1;
	}
	for(int i=0;i<adj[x].size();i++) {
		int u = adj[x][i];
		if(u == p) continue;
		dfs(u, x);
		v[x] += v[u];
	}
}

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n-1;i++) {
		int a, b;
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	if(overflow) cout<<v[0]<<endl;
	else {
		ll m=1;
		for(int i=0;i<n;i++) {
			m = mmc(m, d[i]);
			if(m > v[0]) break;
		}
		if(m > v[0]) cout<<v[0]<<endl;
		else {
			ll ans=v[0];
			for(int i=0;i<n;i++) ans = min(ans, v[i]*d[i]/m*m);
			cout << v[0] - ans << endl;
		}
	}
	return 0;
}
