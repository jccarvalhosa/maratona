#include <stdio.h>
#include <string.h>

int main()
{
	int N, X, Y;
	int raio[501][501];
	int i, duas;
	memset(raio, 0, sizeof(raio));
	duas = 0;
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%d%d", &X, &Y);
		if(raio[X][Y]) duas = 1;
		raio[X][Y] = 1;
	}
	if(!duas) printf("0\n");
	else printf("1\n");
	return 0;
}

