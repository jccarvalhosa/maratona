#include <stdio.h>
#include <string.h>

int min(a, b) { return a < b ? a : b; }

int main()
{
	int N, M, soma, i;
	char L;
	int ne[61];
	int nd[61];
	while(scanf("%d", &N) != EOF)
	{
		memset(ne, 0, sizeof(ne));
		memset(nd, 0, sizeof(nd));
		while(N--)
		{
			scanf("%d %c ", &M, &L);
			if(L == 'D') nd[M]++;
			if(L == 'E') ne[M]++;
		}
		soma = 0;
		for(i=30;i<=60;i++) soma += min(ne[i], nd[i]);
		printf("%d\n", soma);
	}
	return 0;
}
