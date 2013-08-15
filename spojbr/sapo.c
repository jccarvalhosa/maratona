#include <stdio.h>
#include <string.h>

int main()
{
	int G[101];
	int N, M, P, D;
	int i;
	scanf("%d%d", &N, &M);
	memset(G, 0, sizeof(G));
	while(M--)
	{
		scanf("%d%d", &P, &D);
		for(i=P%D;i<=N;i+=D) G[i] = 1;
	}
	for(i=1;i<=N;i++) printf("%d\n", G[i]);
	return 0;
}
