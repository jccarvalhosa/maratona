#include <stdio.h>
#define MAXN 400

int n, grau[MAXN], grafo[MAXN][MAXN];
int vis[MAXN], ordem[MAXN], art[MAXN], fim;


int dfs(int v, int level)
{  
	int i, u, k, menor, is=0;  
	vis[v] = 1;
	ordem[v] = level;
	menor = level;
	for(i=0;i<grau[v];i++)
	{  
		u = grafo[v][i];
		if(!vis[u])
		{  
			k = dfs(u, level+1);
			if(k >= level) is++;
			if(menor > k) menor = k;
		}
		else if (menor > ordem[i]) menor = ordem[i];
	}
	art[v] = (level && is) || (!level && (is>1));
	if(art[v] == 1) fim = 0;
	return menor;
}

int main()
{
	int i, m, a, b, teste=1;
	while(scanf("%d%d", &n, &m) && n)
	{
		for(i=0;i<n;i++) grau[i] = art[i] = vis[i] = 0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d", &a, &b);
			a--; b--;
			grafo[a][grau[a]++] = b;
			grafo[b][grau[b]++] = a;
		}
		fim = 1;
		dfs(0, 0);
		printf("Teste %d\n", teste++);
		if(fim) printf("nenhum");
		else for(i=0;i<n;i++) if(art[i]) printf("%d ", i + 1);
		printf("\n\n");
	}
	return 0;
}

