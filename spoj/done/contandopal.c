#include <stdio.h>

int main()
{
	int N, K;
	int i, j;
	long long int I, div, prod;
	char alfa[27];
	char seq[200];
	int left, right;
	scanf("%d", &N);
	scanf("%s", alfa);
	scanf("%d%lld", &K, &I);
	left = (K+1)/2;
	for(i=0;i<left;i++)
	{
		div = I;
		for(j=0;j<left-i-1;j++) div /= N;
		prod = div;
		if(div != 0) for(j=0;j<left-i-1;j++) prod *= N;
		I -= prod;
		if(I == 0) div = ((div - 1) + N)% N;
		seq[i] = alfa[div];
	}
	for(i=0;i<left;i++) printf("%c", seq[i]);
	for(i=left-K%2-1;i>=0;i--) printf("%c", seq[i]);
	printf("\n");
	return 0;
}
