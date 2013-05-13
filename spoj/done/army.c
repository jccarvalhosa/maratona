#include <stdio.h>

int main()
{
	int S, B, a, b, i;
	int L[100002], R[100002];
	while(scanf("%d%d", &S, &B) && S)
	{
		for(i=1;i<=S;i++) 
		{
			R[i] = i+1;
			L[i] = i-1;
		}
		while(B--)
		{
			scanf("%d%d", &a, &b);
			R[L[a]] = R[b];
			L[R[b]] = L[a];
			if(L[a] == 0) printf("* ");
			else printf("%d ", L[a]);
			if(R[b] == S+1) printf("*\n");
			else printf("%d\n", R[b]);
		}
		printf("-\n");
	}
	return 0;
}
