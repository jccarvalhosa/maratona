#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, f, t, vis[300], pai[300], leaf[300], cid[600], ord[600], pd[601][601], h[300];
vector<int> adj[300];

void dfs(int v, int p, int d) {
	int i, u;
	vis[v] = 1;
	pai[v] = p;
	leaf[v] = 1;
	h[v] = d;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i];
		if(!vis[u]) {
			dfs(u, v, d+1);
			leaf[v] = 0;
		}
	}
}

int main() {
	int i, j, k, a, b, teste=1;
	while(scanf("%d%d", &n, &f) && n) {
		printf("Teste %d\n", teste++);
		for(i=0;i<n;i++) {
			adj[i].clear();
			vis[i] = 0;
		}
		for(i=0;i<n-1;i++) {
			scanf("%d%d", &a, &b);
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		dfs(0, -1, 0);
		for(i=0;i<f;i++) {
			scanf("%d", &a);
			cid[i] = a-1;
		}
		int ans=0;
		for(k=0;k<n;k++) if(leaf[k]) {
			t = 2*h[k]+1;
			for(j=k;j!=-1;j=pai[j]) ord[h[j]] = ord[2*h[k]-h[j]] = j;
			for(j=0;j<=f;j++) pd[0][j] = 0;
			for(i=1;i<=t;i++) for(j=1;j<=f;j++) {
				pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
				if(ord[i-1] == cid[j-1]) pd[i][j] = max(pd[i][j], max(pd[i][j-1], pd[i-1][j-1])+1);
			}
			ans = max(ans, pd[t][f]);
		}
		printf("%d\n\n", ans);
	}
	return 0;
}
