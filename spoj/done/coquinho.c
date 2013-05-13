#include <stdio.h>
#include <string.h>

int main()
{
	int T, N, i, j, cont;
	long long int K, m[51][51], total, tabre;
	char seq[52];
	scanf("%d", &T);
	memset(m, 0, sizeof(m));
	m[0][0] = m[1][1] = 1;
	for(i=2;i<=50;i++)
	{
		m[i][0] = m[i-1][1];
		for(j=1;j<=i;j++) m[i][j] = m[i-1][j-1] + m[i-1][j+1];
	}
	for(i=0;i<=50;i++) for(j=0;j<=50;j++) m[i][j] = (1ll << i) - m[i][j];
	while(T--)
	{
		scanf("%d%lld", &N, &K);
		cont = 0;
		seq[N] = '\0';
		total = m[N][0];
		if(K >= total)
		{
			printf("-1\n");
			continue;
		}
		for(i=0;i<N;i++)
		{
			tabre = m[N-i-1][cont+1];
			if(K < tabre || K == 0)
			{
				seq[i] = '(';
				cont++;
			}
			else
			{
				seq[i] = ')';
				K -= tabre;
				cont--;
				if(cont < 0)
				{
					while(N > i+1)
					{
						if(K % 2 == 0) seq[N-1] = '(';
						else seq[N-1] = ')';
						K /= 2;
						N--;
					}
					break;
				}
			}
		}
		printf("%s\n", seq);
	}
	return 0;
}
