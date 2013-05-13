#include <stdio.h>
#include <string.h>

int main()
{
	int N, K, quantidade[1000];
	memset(quantidade, 0, sizeof(quantidade));
	
	int i, tipo, minimo;

	scanf("%d %d", &N, &K);

	for(i=0;i<N;i++)
	{
		scanf("%d", &tipo);
		quantidade[tipo-1]++;
	}

	minimo = quantidade[0];

	for(i=1;i<K;i++) if(minimo > quantidade[i]) minimo = quantidade[i];

	printf("%d\n", minimo);

	return 0;



}
