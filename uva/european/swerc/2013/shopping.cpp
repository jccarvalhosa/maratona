#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 222;
int n, m, f[N], x[N], y[N];
long double adj[N][N], dp[N][N];

int main() {
	int T=0;
	while(cin>>n>>m && !cin.eof()) {
		if(T) cout<<endl;
		T++;
		for(int i=0;i<n;i++) cin>>f[i]>>x[i]>>y[i];
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) adj[i][j] = 1e12;
		for(int i=0;i<n;i++) adj[i][i]=0;
		for(int i=0;i<m;i++) {
			int a, b;
			string s;
			cin>>a>>b>>s;
			long double d = sqrt(1ll*(x[a]-x[b])*(x[a]-x[b]) + 1ll*(y[a]-y[b])*(y[a]-y[b]) + 25ll*(f[a]-f[b])*(f[a]-f[b]));
			if(s == "walking") {
				adj[a][b] = min(adj[a][b], d);
				adj[b][a] = min(adj[b][a], d);
			}
			if(s == "stairs") {
				adj[a][b] = min(adj[a][b], d);
				adj[b][a] = min(adj[b][a], d);
			}
			if(s == "lift") {
				adj[a][b] = min(adj[a][b], (long double)1.0);
				adj[b][a] = min(adj[b][a], (long double)1.0);
			}
			if(s == "escalator") {
				adj[a][b] = min(adj[a][b], (long double)1.0);
				adj[b][a] = min(adj[b][a], 3*d);
			}
		}
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = adj[i][j];
		for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		int q;
		cin>>q;
		while(q--) {
			int a, b;
			cin>>a>>b;
			cout<<a;
			while(a != b) {
				int na=-1;
				for(int i=0;i<n;i++) if(i != a && adj[a][i] < 1e12 - 1e-5) {
					if(na == -1) na = i;
					else if(adj[a][i] + dp[i][b] < adj[a][na] + dp[na][b]) na=i;
				}
				cout<<" "<<na;
				a = na;
			}
			cout<<endl;
		}
	}
	return 0;
}
