#include <stdio.h>
#include <string.h>

int N, M, t;
int R[1000][1000], art[1000][1000];
int vis[1000], men[1000];

void dfsbridge(int v,int p)
{
    int w;
    if(!vis[v])
	{
		vis[v] = ++t;
		men[v] = vis[v];
		for(w=0;w<N;w++) if(R[v][w] || R[w][v])
		{
			if(w != p)
			{
				if(vis[w] && men[v] > vis[w]) men[v] = vis[w];
				else
				{
					dfsbridge(w,v);
					if(men[v] > men[w])	men[v] = men[w];
				}
			}
		}
		if(p >= 0 && men[v] >= vis[v]) art[p][v] = 1;
	}
}

void bridge()
{
    int i;
	memset(vis, 0, sizeof(int) * N);
	for(i=0;i<N;i++) memset(art[i], 0, sizeof(int) * N);
    t = 0;
    for(i=0;i<N;i++) if(!vis[i]) dfsbridge(i,-1);
}

int dfs(int v)
{
	int i, soma=0;
	vis[v] = 1;
	for(i=0;i<N;i++) if(!vis[i] && R[v][i]) soma += dfs(i);
	return 1 + soma;
}

int dfsinv(int v)
{
	int i, soma=0;
	vis[v] = 1;
	for(i=0;i<N;i++) if(!vis[i] && R[i][v]) soma += dfsinv(i);
	return 1 + soma;
}

int dfsnd(int v)
{
	int i, soma=0;
	vis[v] = 1;
	for(i=0;i<N;i++) if(!vis[i] && (R[v][i] || R[i][v])) soma += dfsnd(i);
	return 1 + soma;
}

int conexo(int v)
{
	memset(vis, 0, sizeof(int) * N);
	if(dfs(v) != N) return 0;
	memset(vis, 0, sizeof(int) * N);
	if(dfsinv(v) != N) return 0;
	return 1;
}

int conexond(int v)
{
	memset(vis, 0, sizeof(int) * N);
	if(dfsnd(v) != N) return 0;
	return 1;
}

int mao_unica()
{
	int i, j;
	bridge();
	for(i=0;i<N;i++) for(j=0;j<N;j++) if(art[i][j] && (R[j][i] != 1 || R[i][j] != 1)) return 0;
	return 1;
}

int main()
{
	int A, B, T;
	int i;
	while(scanf("%d%d", &N, &M) != EOF)
	{	
		scanf("%d%d%d", &A, &B, &T);
		for(i=0;i<N;i++) memset(R[i], 0, sizeof(int) * N);
		for(i=1;i<M;i++)
		{
			scanf("%d%d%d", &A, &B, &T);
			A--; B--;
			if(T == 1) R[A][B] = 1;
			if(T == 2) R[A][B] = R[B][A] = 1;
		}
		if(conexo(0)) printf("-\n");
		else
		{
			if(!conexond(0)) printf("*\n");
			else
			{
				if(mao_unica()) printf("1\n");
				else printf("2\n");
			}
		}
	}
	return 0;
}
