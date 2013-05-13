#include <stdio.h>

int main()
{
	int N;
	int Q[1000][1000];
	int i, j, soma, s, cmax, ok;
	scanf("%d", &N);
	for(i=0;i<N;i++) for(j=0;j<N;j++) scanf("%d", &Q[i][j]);
	ok = 1;
	cmax = N * N;
	soma = 0;
	for(i=0;i<N;i++)
	{
		if(Q[i][i] <= cmax) soma += Q[i][i];
		else ok = 0; 
	}
	s = 0;
	for(i=0;i<N;i++) 
	{
		if(Q[i][N-i-1] <= cmax) s += Q[i][N-i-1];
		else ok = 0;
	}
	if(s != soma) ok = 0;
	if(ok)
	{
		for(i=0;i<N;i++)
		{
			s = 0;
			for(j=0;j<N;j++)
			{
				if(Q[i][j] <= cmax) s += Q[i][j];
				else ok = 0; 
			}
			if(s != soma) ok = 0;
		}
		for(j=0;j<N;j++)
		{
			s = 0;
			for(i=0;i<N;i++)
			{
				if(Q[i][j] <= cmax) s += Q[i][j];
				else ok = 0; 
			}
			if(s != soma) ok = 0;
		}
	}
	if(ok) printf("%d\n", soma);
	else printf("0\n");
	return 0;
}
