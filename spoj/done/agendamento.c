#include <stdio.h>
	
int G[1200][1200];

int main()
{
	int N, i, j;
	int a, b, p, d, prazomax, mini[2000], prazo[2000], maxi[2000], dep[2000], topsort[2000], topsize;
	while(scanf("%d", &N) && N)
	{
		for(i=0;i<N;i++)
		{
			mini[i] = 0;
			for(j=0;j<N;j++) G[i][j] = 0;
		}
		topsize = 0;
		for(i=0;i<N;i++)
		{
			scanf("%d%d%d", &a, &p, &d);
			prazo[a] = p;
			dep[a] = d;
			if(!dep[a]) topsort[topsize++] = a;
			for(j=0;j<d;j++)
			{
				scanf("%d", &b);
				G[b][a] = 1;
			}
		}
		for(i=0;i<topsize;i++)
		{
			a = topsort[i];
			for(j=0;j<N;j++) if(dep[j] && G[a][j])
			{
				dep[j]--;
				if(mini[j] < mini[a] + prazo[a]) mini[j] = mini[a] + prazo[a];
				if(!dep[j]) topsort[topsize++] = j;
			}
		}
		prazomax = mini[0] + prazo[0];
		for(i=1;i<N;i++) if(prazomax < mini[i] + prazo[i]) prazomax = mini[i] + prazo[i];
		for(i=0;i<N;i++) maxi[i] = prazomax - prazo[i];
		for(i=N-1;i>=0;i--)
		{
			a = topsort[i];
			for(j=0;j<N;j++) if(G[j][a] && maxi[j] > maxi[a] - prazo[j]) maxi[j] = maxi[a] - prazo[j];
		}
		printf("Prazo: %d dias\n", prazomax);
		for(i=0;i<N;i++) printf("Tarefa #%d: min=%d, max=%d\n", i, mini[i], maxi[i]);
		printf("---\n");
	}
	return 0;
}


