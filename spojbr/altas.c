#include <stdio.h>

long long int A[50001][31];

int main()
{
	int i, j, n, k, ret = 0;
	long long int soma=0;
	scanf("%d %d", &n, &k);
	for(i=0;i<50001;i++) for(j=0;j<31;j++) A[i][j] = 0;
	for(i=1;i<50001;i++){
		A[i][1] = i;
		for(j=1;j<31;j++) A[i][j] = A[i-1][j-1] + A[i-1][j] + 1;
	}
	if(k == 1)
		printf("%d\n", n);
	else{
		if(k > 30)
			k = 30;
		for(i=1;A[i][k]<n;i++);
		printf("%d\n", i);
	}
	return 0;
}
