#include <cstdio>
#include <cstring>

int main() {
	int N, M, sol=-1, a, b, c, d, i, j, k, adj[101][101];
	scanf("%d%d", &N, &M);
	memset(adj, 0, sizeof(adj));
	for(i=0;i<M;i++) {
		scanf("%d%d%d", &a, &b, &d);
		adj[a][b] = adj[b][a] = d;
	}
	for(i=1;i<=N;i++) for(j=i+1;j<=N;j++) for(k=j+1;k<=N;k++) {
		d = adj[i][j] + adj[i][k] + adj[j][k];
		if(sol < d) sol=d, a=i, b=j, c=k;
	}
	printf("%d %d %d", a, b, c);
	return 0;
}
