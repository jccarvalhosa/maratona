#include <stdio.h>
#include <string.h>

int grau[7], adj[7][7], cor[7];

void dfs(int ini)
{
	int i;
	cor[ini]=1;
	for(i=0;i<7;i++) if(adj[ini][i] && !cor[i]) dfs(i);
}

int conexo()
{
	int i, partida;
	memset(cor, 0, sizeof(cor));
	partida=0;
	while(!grau[partida]) partida++;
	dfs(partida);
	for(i=0;i<7;i++) if(grau[i] && !cor[i]) return 0;
	return 1;
}

int euleriano()
{
	int i, n_impares=0;
	for(i=0;i<7;i++) if(grau[i] % 2 == 1) n_impares++;
	if(n_impares <= 2) return 1;
	return 0;
}

int main()
{
	int i, n, x, y, teste=1;
	while(scanf("%d", &n) && n)
	{
		memset(grau, 0, sizeof(grau));
		memset(adj, 0, sizeof(adj));
		for(i=0;i<n;i++)
		{
			scanf("%d%d", &x, &y);
			grau[x]++;
			grau[y]++;
			adj[x][y]=1;
			adj[y][x]=1;
		}
		printf("Teste %d\n", teste++);
		if(conexo())
		{
			if(euleriano())	printf("sim\n\n");
			else printf("nao\n\n");
		}
		else printf("nao\n\n");
	}
	return 0;
}
