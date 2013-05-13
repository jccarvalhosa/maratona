#include <stdio.h>
#include <string.h>

int Q[202][202];
int soma = 0;

void dfs(int X, int Y)
{
	int i, j;
	soma++;
	Q[X][Y] = 1;
	for(i=-1;i<=1;i++) for(j=-1;j<=1;j++) if(Q[X+i][Y+j] == 0) dfs(X+i, Y+j);
}

int main()
{
	int N, M, X, Y, K, A, B;
	int i, j;
	memset(Q, 0, sizeof(Q));
	scanf("%d%d%d%d%d", &N, &M, &X, &Y, &K);
	for(i=0;i<=N+1;i++)
	{
		Q[i][0] = 1;
		Q[i][M+1] = 1;
	}
	for(j=0;j<=M+1;j++)
	{
		Q[0][j] = 1;
		Q[N+1][j] = 1;
	}
	while(K--)
	{
		scanf("%d%d", &A, &B);
		Q[A][B] = 1;
	}
	dfs(X, Y);
	printf("%d\n", soma);
	return 0;
}
