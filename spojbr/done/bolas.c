#include <stdio.h>

int N;
int B[1000][1000];

int max_pontos_jogo(int v)
{
	int maxv, i;

	for(i=N-1;i>v;i--)
	{
		if(B[i][v] > 0)
		{
			B[i-1][v] += B[i][v];
			B[i][v] = 0;
		}
	}

	maxv = B[v][v] > 0 ? B[v][v] : 0;
	
	if(v == N-1) return maxv;

	for(i=N-2;i>=v;i--)
	{
		if(B[i][v] < 0)
		{
			B[i+1][v+1] += B[i][v];
		}
	}

	return maxv + max_pontos_jogo(v+1);
}

int main()
{
	int x, y;
	while(scanf("%d", &N) && N)
	{
		for(x=0;x<N;x++) for(y=0;y<=x;y++) scanf("%d", &B[x][y]);
		printf("%d\n", max_pontos_jogo(0));
	}

	return 0;
}
