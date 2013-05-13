#include <stdio.h>

int main()
{
	int N, S, i, j;
	scanf("%d%d", &N, &S);
	int delta = S - N * (1 + N*N) / 2;
	int num = 1;
	for(i=0;i<N;i++) 
	{
		for(j=0;j<N;j++)
		{
			if (i == 0 && delta < 0) printf("%d ", num++ + delta);
			else if (i == N-1 && delta > 0)	printf("%d ", num++ + delta);
			else printf("%d ", num++);
		}
		printf("\n");
	}
	return 0;
}
