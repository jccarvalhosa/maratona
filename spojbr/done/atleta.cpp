#include <stdio.h>

int N, V, M[10][10], adj[10][10];

int G[20][20], grau[20], vis[20];

int ini[10], fim[10];

int go(int v)
{
	int i, u;
	vis[v] = 1;
	for(i=0;i<grau[v];i++)
	{
		u = G[v][i];
		if(vis[u] == 1) return 1;
		if(!vis[u] && go(u)) return 1;
	}
    vis[v] = 2;
	return 0;
}

int cycle()
{
	int i;
	for(i=0;i<V;i++) vis[i] = 0;
	for(i=0;i<V;i++) if(!vis[i] && go(i)) return 1;
	return 0;
}

void build_graph(int liar)
{
    int i, j;
    for(i=0;i<V;i++) grau[i] = 0;
    for(i=0;i<N;i++) for(j=0;j<N;j++) adj[i][j] = 0;
    for(i=0;i<N;i++)
    {
        G[ini[i]][grau[ini[i]]++] = fim[i];
        if(i == liar) continue;
        for(j=0;j<N;j++) if(M[i][j]) adj[i][j] = adj[j][i] = 1;
    }
    for(i=0;i<N;i++) for(j=i+1;j<N;j++) if(adj[i][j])
    {
        G[ini[i]][grau[ini[i]]++] = fim[j];
        G[ini[j]][grau[ini[j]]++] = fim[i];
    }
}

int dfs(int a, int b)
{
    int i;
    if(a >= N) return 1;
    if(b >= N) return dfs(a+1, a+2);
    if(adj[a][b]) return dfs(a, b+1);

    G[fim[a]][grau[fim[a]]++] = ini[b];
    if(!cycle() && dfs(a, b+1)) return 1;
    grau[fim[a]]--;

    G[fim[b]][grau[fim[b]]++] = ini[a];
    if(!cycle() && dfs(a, b+1)) return 1;
    grau[fim[b]]--;

    return 0;
}

int teste(int n) 
{
    build_graph(n);
    if(dfs(0, 1)) return 1;
    return 0;
}

int main()
{
    int i, j, k, p;
    for(i=0;i<10;i++)
    {
        ini[i] = 2*i;
        fim[i] = 2*i+1;
    }
    while(scanf("%d", &N) && N)
    {
        V = 2*N;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++) M[i][j] = 0;
            scanf("%d", &k);
            for(j=0;j<k;j++) scanf("%d", &p), M[i][p-1] = 1;
        }
        if(teste(N)) printf("nenhum mentiroso\n");
        else for(i=0;i<N;i++)
        {
            if(teste(i))
            {
                printf("%d\n", i+1);
                break;
            }
        }
    }
    return 0;
}
