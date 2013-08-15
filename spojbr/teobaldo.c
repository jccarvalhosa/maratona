#include <stdio.h>
#include <string.h>

int adj[100][100], caminhos[201][100];

void conta(int passos, int fonte, int n) {
	int j, t, k;
	for (j=0;j<n;j++) caminhos[1][j] = adj[fonte][j];
	for(t=2;t<=passos;t++) for(j=0;j<n;j++) for(k=0;k<n;k++) if(adj[k][j] && caminhos[t-1][k]) caminhos[t][j] = 1;
}

int main()
{
	int N, M, u, v, fonte, destino, dias=0, i, j;
	while(scanf("%d %d", &N, &M) && N)
	{
		for(i=0;i<N;i++) for(j=0;j<N;j++) adj[i][j]=0;
		for(i=0;i<M;i++)
		{
			scanf("%d %d", &u, &v);
			u--, v--;
			adj[u][v] = 1;
			adj[v][u] = 1;
		}
		scanf("%d %d %d", &fonte, &destino, &dias);
		fonte--, destino--;
		for(i=0;i<=dias;i++) for(j=0;j<N;j++) caminhos[i][j]=0;
		conta(dias, fonte, N);
		if((dias == 0 && fonte == destino) || caminhos[dias][destino]) printf("Yes, Teobaldo can travel.\n");
		else printf("No, Teobaldo can not travel.\n");
	}
	return 0;
}
