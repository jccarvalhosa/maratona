#include <stdio.h>

int mod(int a) { return a> 0 ? a : -a; }

int main()
{
	int N, K, X, Y, D, i, j, nsol, soli, solj;
	int mapa[100][100];
	scanf("%d%d", &N, &K);
	for(i=0;i<N;i++) for(j=0;j<N;j++) mapa[i][j] = 1;
	while(K--)
	{
		scanf("%d%d%d", &X, &Y, &D);
		for(i=0;i<N;i++) for(j=0;j<N;j++) if(mod(X-i) + mod(Y-j) != D) mapa[i][j] = 0;
	}
	nsol = 0;
	for(i=0;i<N;i++) for(j=0;j<N;j++) if(mapa[i][j] == 1)
	{
		nsol++;
		soli = i;
		solj = j;
	}
	if(nsol > 1) printf("-1 -1\n");
	else printf("%d %d\n", soli, solj);
	return 0;
}
