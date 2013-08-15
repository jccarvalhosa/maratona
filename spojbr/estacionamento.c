#include <stdio.h>
#include <string.h>

int main()
{
	int C, N, P, Q;
	int lucro, i, j, vi, vf, vt;
	char c;
	int est[1000];
	int ini[10000];
	int fim[10000];
	while(scanf("%d%d", &C, &N) != EOF)
	{
		lucro = 0;
		memset(ini, 0, sizeof(ini));
		memset(fim, 0, sizeof(fim));
		memset(est, 0, sizeof(est));
		while(N--)
		{
			scanf(" %c ", &c);
			if(c == 'C') 
			{
				scanf("%d%d", &P, &Q);
				vt = -1;
				for(i=0;i<C;i++)
				{
					if(est[i] == 0)
					{
						if(vt == -1) vi = i;
						vf = i;
						vt = vf - vi + 1;
						if(vt == Q)
						{
							lucro += 10;
							ini[P] = vi;
							fim[P] = vf;
							for(j=vi;j<=vf;j++) est[j] = 1;
							break;
						}
					}
					if(est[i] == 1) vt = -1;
				}
			}
			if(c == 'S')
			{
				scanf("%d", &P);
				for(i=ini[P];i<=fim[P];i++) est[i] = 0;
			}
		}
		printf("%d\n", lucro);
	}
	return 0;
}
