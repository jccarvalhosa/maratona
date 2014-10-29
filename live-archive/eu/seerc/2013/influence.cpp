#include <bits/stdc++.h>
using namespace std;

const int N=5e3+10;
vector<int> adj[N], ord;
bitset<N> b[N];
int x[N], vis[N], g[N];
char s[1111111];

void dfs(int u) {
	vis[u]=1;
	for(int i=0; i<adj[u].size(); i++) {
		int v=adj[u][i];
		if(!vis[v]) dfs(v);
	}
	ord.push_back(u);
}

int main() {
	int n, k;
	while(scanf("%d %d", &n, &k)!=EOF) {
		for(int i=0; i<k; i++) scanf("%d", &x[i]);
		ord.clear();
		for(int i=0; i<n; i++) for(int j=0; j<n; j++) b[i][j]=0;
		for(int i=0; i<n; i++) b[i][i]=1, vis[i]=g[i]=0, adj[i].clear();
		getchar();
		for(int i=0; i<n; i++) {
			scanf("%[^\n]", s);
			getchar();
			char *p;
			p=strtok(s, " ");
			int f=0, a, b;
			while(p!=NULL) {
				if(!f) {
					sscanf(p, "%d", &a);
					a--;
					f=1;
				}
				else {
					sscanf(p, "%d", &b);
					b--;
					adj[a].push_back(b);
					g[b]++;
				}
				p=strtok(NULL, " ");
			}
		}
		for(int i=0; i<n; i++) if(!vis[i] && !g[i]) dfs(i);
		for(int i=0; i<n; i++) {
			int u=ord[i];
			for(int j=0; j<adj[u].size(); j++) {
				int v=adj[u][j];
				b[u]|=b[v];
			}
		}
		int ans=0, _max=-1;
		for(int i=0; i<n; i++) {
			int cnt=0;
			for(int j=0; j<n; j++) if(b[i][j]) cnt++;
			if(cnt>_max) _max=cnt, ans=i;
		}
		printf("%d\n", ans+1);
	}
	return 0;
}
