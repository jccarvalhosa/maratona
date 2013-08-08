#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	int Xi, Xf, Yi, Yf;
	int A[100][100];
	int i, j, soma=0;
	memset(A, 0, sizeof(A));
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d%d%d%d", &Xi, &Xf, &Yi, &Yf);
		for(i=Xi-1;i<Xf-1;i++) for(j=Yi-1;j<Yf-1;j++)
		{
			if(A[i][j] == 0) soma++;
			A[i][j] = 1;
		}
	}
	printf("%d\n", soma);
	return 0;
}
