#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) { return *(int*) a - *(int*) b; }
int num[10], vis[10], ordem[10], n;

void chama(int v, int pos)
{
	int i;
	vis[v] = 1;
	ordem[pos] = v;
	if(pos == n-1)
	{
		for(i=0;i<n;i++) printf("%d ", num[ordem[i]]);
		printf("\n");
	}
	else
	{
		for(i=0;i<n;i++) if(!vis[i]) chama(i, pos+1);
	}
	vis[v] = 0;
}

int main()
{
	int i;
	while(scanf("%d", &n) && n)
	{
		for(i=0;i<n;i++) scanf("%d", &num[i]);
		qsort(num, n, sizeof(int), compare);
		for(i=0;i<n;i++) chama(i, 0);
	}
	return 0;
}
