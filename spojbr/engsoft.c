#include <stdio.h>

int adj[300][300], n, total, vis[300], teste;
int pai[300], src, dest;

void dfs(int v)
{
	int i;
	vis[v] = 1;
	for(i=dest;i>=0;i--) if(adj[v][i] && !vis[i])
	{
		pai[i] = v;
		dfs(i);
		if(vis[dest]) break;
	}
}

void ford_fulkerson()
{
	int i, j, v;
	total = 0;
	while(1)
	{
		for(i=0;i<=2*n+1;i++)
		{
			vis[i] = 0;
			pai[i] = -1;
		}
		dfs(0);
		if(vis[dest])
		{
			for(i=dest;pai[i]!=-1;i=pai[i])
			{
				adj[i][pai[i]]++;
				adj[pai[i]][i]--;
			}
			total++;
		}
		else break;
	}
}


int main()
{
	int k, i, j, u, v, teste, p;
	scanf("%d", &k);
	for(teste=1;teste<=k;teste++)
	{
		scanf("%d", &n);
		src = 0;
		dest = 2*n+1;
		for(i=0;i<=2*n+1;i++) for(j=0;j<=2*n+1;j++) adj[i][j]=0;
		for(i=1;i<=n;i++) adj[src][i] = 1;
		for(i=n+1;i<=2*n;i++) adj[i][dest] = 1;
		for(u=1;u<=n;u++)
		{
			scanf("%d", &p);
			for(i=0;i<p;i++)
			{
				scanf("%d", &v);
				adj[u][v+n] = 1;
			}
		}
		printf("Instancia %d\n", teste);
		ford_fulkerson();
		if(total != n) printf("extreme programming\n\n");
		else printf("pair programming\n\n");
	}
	return 0;
}

