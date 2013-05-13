#include <stdio.h>

int v[1002][1002], vinv[1002][1002], s[1002][1002], sinv[1002][1002];

int main()
{
	int N, i, j, npretas=0;
	int peca[1002];
	char c;
	scanf("%d", &N);
	for(i=1;i<=N;i++)
	{
		scanf(" %c ", &c);
		if(c == 'P')
		{
			peca[i] = 1;
			npretas++;
		}
		else peca[i] = 0;
	}
	if(npretas % 2 == 0) printf("0\n");
	else
	{
		for(i=1;i<=N;i++)
		{
			v[i][0] = vinv[i][0] = s[i][0] = 0;
			sinv[0][i] = 1;
		}
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=i;j++)
			{
				if(peca[i] == 0)
				{
					v[i][j] = s[i-1][j-1];
					vinv[i][j] = sinv[i-1][j];
				}
				else
				{
					v[i][j] = sinv[i-1][j];
					vinv[i][j] = s[i-1][j-1];
				}
			}
			for(j=1;j<=i+1;j++) s[i][j] = (s[i][j-1] + v[i][j]) % 10007;
			for(j=i;j>=1;j--) sinv[i][j] = (sinv[i][j+1] + vinv[i][j]) % 10007;
		}
		printf("%d\n", s[N][N]);
	}
	return 0;
}
