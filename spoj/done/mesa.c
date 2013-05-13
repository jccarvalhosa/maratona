#include <stdio.h>
	
int n, m, grafo[100][100], cor[100], grau[100], vis[100];

int colore(int v)
{
	int i;
	vis[v] = 1;
	for(i=0;i<grau[v];i++)
	{
		if(cor[grafo[v][i]] == cor[v]) return 0;
		else if(!vis[grafo[v][i]])
		{
			cor[grafo[v][i]] = 1 + (cor[v] % 2);
			if(!colore(grafo[v][i])) return 0;
		}
	}
	return 1;
}

int main()
{
	int i, a, b, pode, teste=1;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(i=0;i<n;i++) grau[i] = cor[i] = vis[i] = 0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d", &a, &b);
			a--; b--;
			grafo[a][grau[a]++] = b;
			grafo[b][grau[b]++] = a;
		}
		pode = 1;
		for(i=0;i<n;i++) if(cor[i] == 0)
		{
			cor[i] = 1;
			if(!colore(i))
			{
				pode = 0;
				break;
			}
		}
		printf("Instancia %d\n", teste++);
		if(pode) printf("sim\n\n");
		else printf("nao\n\n");
	}
	return 0;
}
