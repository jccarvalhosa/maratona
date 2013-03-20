#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int adj[100][100], lang[100][100];
int n, m, vis[100];

void dfs(int v) {
	vis[v] = 1;
	for(int i=0;i<n;i++) if(adj[v][i] && !vis[i]) dfs(i);
}

int main() {
	scanf("%d%d", &n, &m);
	int i, j, k, dumbs=0;
	memset(adj, 0, sizeof(adj));
	memset(lang, 0, sizeof(lang));
	for(i=0;i<n;i++) {
		vis[i]=0;
		scanf("%d", &k);
		if(k==0) {
			dumbs++;
			vis[i]=1;
		}
		while(k--) {
			scanf("%d", &j);
			lang[i][j-1]=1;
		}
	}
	for(i=0;i<n;i++) for(j=i+1;j<n;j++) {
		for(k=0;k<m;k++) if(lang[i][k] && lang[j][k]) break;
		if(k != m) adj[i][j] = adj[j][i] = 1;
	}
	int c=0;
	for(i=0;i<n;i++) if(!vis[i]) dfs(i), c++;
	printf("%d\n", max(c-1, 0) + dumbs);
	return 0;
}
