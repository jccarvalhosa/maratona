#include <stdio.h>
#include <math.h>

int main()
{
	int N, i, maxn, a, b;
	double atual, maxd;
	scanf("%d", &N);
	scanf("%d%d", &a, &b);
	atual = b * log(a);
	maxd = atual;
	maxn = 0;
	for(i=1;i<N;i++)
	{
		scanf("%d%d", &a, &b);
		atual = b * log(a);
		if(maxd - atual < 0.0001)
		{
			maxn = i;
			maxd = atual;
		}
	}
	printf("%d\n", maxn);
	return 0;
}
