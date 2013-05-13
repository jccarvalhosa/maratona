#include <stdio.h>
#include <string.h>

char c[10000];
int palin[2000][2000];

int main()
{
	int N, teste=1, min[2000];
	int i, j;
	while(scanf("%d", &N) && N)
	{
		printf("Teste %d\n", teste++);
		scanf("%s", c);
		for(i=0;i<N;i++) memset(palin[i], 0, N * sizeof(int));
		for(i=0;i<N;i++)
		{
			palin[i][i] = 1;
			for(j=1;i+j<N && i-j >= 0;j++)
			{
				if(c[i-j] == c[i+j]) palin[i-j][i+j] = 1; 
				else break;
			}
			if(i != N-1 && c[i] == c[i+1])
			{
				palin[i][i+1] = 1;
				for(j=1;i+j+1<N && i-j >= 0;j++)
				{
					if(c[i-j] == c[i+j+1]) palin[i-j][i+j+1] = 1;
					else break;
				}
			}
		}
		memset(min, 0, N * sizeof(int));
		min[0] = 1;
		for(i=1;i<N;i++)
		{
			if(palin[0][i]) min[i] = 1;	
			else
			{
				min[i] = min[i-1] + 1;
				for(j=1;j<i;j++) if(palin[j][i] && min[i] > min[j-1] + 1) min[i] = min[j-1] + 1;
			}
		}
		printf("%d\n\n", min[N-1]);
	}
	return 0;
}
