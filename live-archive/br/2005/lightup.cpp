#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX 8

using namespace std;

int N, M, sol;

int G[MAX][MAX];
int ilum[MAX][MAX];
int adj[MAX][MAX];

int valido()
{
	int i, j;
	for(i=0;i<N;i++) for(j=0;j<M;j++)
	{
		if(G[i][j] == INF && !ilum[i][j]) return 0;
		if(G[i][j] == 5 && ilum[i][j] > 1) return 0;
		if(G[i][j] >= 0 && G[i][j] <= 4 && adj[i][j] != G[i][j]) return 0;
	}
	return 1;
}

int da[] = {1, 0, -1, 0};
int db[] = {0, 1, 0, -1};

void liga(int a, int b, int k)
{
	int i, j, na, nb;
	if(k == 1) G[a][b] = 5;
    else G[a][b] = INF;
	ilum[a][b] += k;
	for(i=0;i<4;i++) for(j=1;true;j++)
    {
        na = a + j*da[i];
        nb = b + j*db[i];
        if(na < 0 || na >= N || nb < 0 || nb >= M) break;
        if(j == 1) adj[na][nb] += k;
        ilum[na][nb] += k;
        if(G[na][nb] != INF) break;
    }
}

int dfs(int a, int b, int l)
{
	int ret, i, j;
	if(a == N)
    {
		if(valido()) return l;
		return INF;
	}
	if(b == M) return dfs(a+1, 0, l);
	ret = dfs(a, b+1, l);
	if(G[a][b] == INF && !ilum[a][b])
	{
		liga(a, b, 1);
		ret = min(ret, dfs(a, b+1, l+1));
		liga(a, b, -1);
	}
	return ret;
}

int main()
{
    int B, i, j, r, c, k;
    while(scanf("%d%d", &N, &M) && N)
    {
		for(i=0;i<N;i++) for(j=0;j<M;j++)
		{
			G[i][j] = INF;
			adj[i][j] = 0;
			ilum[i][j] = 0;
		}
		scanf("%d\n", &B);
        for(i=0;i<B;i++) scanf("%d%d%d", &r, &c, &k), G[r-1][c-1] = k;
        sol = dfs(0, 0, 0);
        if(sol != INF) printf("%d\n", sol);
        else printf("No solution\n");
    }
    return 0;
}
