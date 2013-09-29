#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int M = 100010;
const int t = 320;

vector<int> g[M], e[M];
ll a[M], v[t], sum[t];
int adj[t][M], id[M];

int main() {
	int n, m, q, mm=0;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) {
		int k;
		cin>>k;
		if(k > t) id[i]=mm++;
		for(int j=0;j<k;j++) {
			int x;
			cin>>x;
			g[x-1].push_back(i);
			e[i].push_back(x-1);
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<g[i].size();j++) {
			int x = g[i][j];
			if(e[x].size() > t) {
				for(int k=0;k<g[i].size();k++) {
					int y = g[i][k];
					adj[id[x]][y]++;
				}
			}
		}
	}
	for(int i=0;i<m;i++) if(e[i].size() > t) for(int j=0;j<e[i].size();j++) v[id[i]] += a[e[i][j]];
	while(q--) {
		char c;
		int x;
		cin>>c>>x; x--;
		if(c=='?') {
			if(e[x].size() > t) cout<<v[id[x]]<<endl;
			else {
				ll ans=0;
				for(int i=0;i<e[x].size();i++) ans += a[e[x][i]];
				for(int i=0;i<mm;i++) ans += sum[i] * adj[i][x];
				cout<<ans<<endl;
			}
		}
		if(c=='+') {
			ll k;
			cin>>k;
			for(int i=0;i<mm;i++) v[i] += k * adj[i][x];
			if(e[x].size() > t) sum[id[x]] += k;
			else for(int i=0;i<e[x].size();i++) a[e[x][i]] += k;
		}
	}
	return 0;
}
