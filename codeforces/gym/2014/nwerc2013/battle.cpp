#include <bits/stdc++.h>
using namespace std;

const int N=555;
int adj[N][N], w[N];
vector<int> g[N];


int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i=0;i<n;i++) scanf("%d", &w[i]);
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) adj[i][j]=0;
			g[i].clear();
		}
		for(int i=0;i<m;i++) {
			int a, b;
			scanf("%d%d", &a, &b); a--; b--;
			adj[a][b] = adj[b][a]=1;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int ans=0;
		for(int a=0;a<n;a++) ans = max(ans, w[a]);
		for(int a=0;a<n;a++) for(int b=a+1;b<n;b++) if(adj[a][b]) {
			ans = max(ans, w[a]+w[b]);
			//tam 3
			for(int i=0;i<g[a].size();i++) {
				int x = g[a][i];
				if(adj[x][b]) {
					ans = max(ans, w[a]+w[b]+w[x]);
				}
			}
			//tam 4
			for(int i=0;i<g[a].size();i++) {
				int aa = g[a][i];
				if(!adj[aa][b]) continue;
				for(int j=0;j<g[b].size();j++) {
					int bb = g[b][j];
					if(adj[bb][a] && adj[bb][aa]) ans = max(ans, w[a]+w[b]+w[aa]+w[bb]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
