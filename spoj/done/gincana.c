#include <stdio.h>

int main()
{
	int n, m, a, b, total, g_atual[1001];
	int i, j, gmin, gmax;
	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++) g_atual[i] = i;
	total = n;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d", &a, &b);
		if(g_atual[a] != g_atual[b])
		{
			total--;
			if(g_atual[a] > g_atual[b])
			{
				gmin = g_atual[b];
				gmax = g_atual[a];
			}
			else
			{
				gmin = g_atual[a]; 
				gmax = g_atual[b];
			}
			for(j=1;j<=n;j++) if(g_atual[j] == gmax) g_atual[j] = gmin;
		}
	}
	printf("%d\n", total);
	return 0;
}

