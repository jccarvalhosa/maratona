#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int N=(int)5e5+10;

int n, vis[N], a[N], dist[N], pai[N], ns[N];
vector<int> adj[N];
	
vector<pii> s;

void dfs(int v, int p) {
	pai[v]=p;
	dist[v] = dist[p]+1;
	ns[v]=0;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u != p) {
			dfs(u, v);
			ns[v] += 1 + ns[u];
		}
	}
}

int mark(int v) {
	if(vis[v]) return 0;
	vis[v]=1;
	int ret=1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(u != pai[v]) ret += mark(u);
	}
	return ret;
}

int valid(int x) {
	for(int i=1;i<=n;i++) vis[i]=0;
	int pos=0;
	for(int i=0;i<s.size();i++) {
		int v = s[i].second;
		ll d = x - s[i].first;
		if(vis[v]) continue;
		int nsub = mark(v) - 1;
		pos += nsub;
		if(pos > d) return 0;
		pos++;
	}
	return 1;
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dist[0]=-1;
	dfs(1, 0);
	for(int i=1;i<=n;i++) s.push_back(pii(dist[i] + a[i], i));
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	ll i=0, f=(ll)(*max_element(a+1, a+n+1) + n);
	while(i<f-1) {
		ll mid = (f+i)/2;
		if(valid(mid)) f=mid;
		else i=mid;
	}
	cout<<f<<endl;
	return 0;
}
