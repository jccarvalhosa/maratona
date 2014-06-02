#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int> adj[N];
int c[N], vis[N];
long long total[N];

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<m;i++) {
		int a, b;
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	for(int i=0;i<n;i++) for(int j=0;j<adj[i].size();j++) total[i] += c[adj[i][j]];
	long long ans=0;
	for(int it=0;it<n;it++) {
		int best=-1, mm=-1;
		for(int i=0;i<n;i++) if(!vis[i]) {
			if(mm < c[i]) {
				mm = c[i];
				best=i;
			}
		}
		vis[best]=1;
		ans += total[best];
		for(int i=0;i<adj[best].size();i++) {
			int v = adj[best][i];
			total[v] -= c[best];
		}
	}
	cout << ans << endl;
	return 0;
}
