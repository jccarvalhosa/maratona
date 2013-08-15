#include <stdio.h>

int max(i, j) { return i > j ? i : j; }

int main()
{
	int i, j, m, n;
	int maxLinha[100000], maxColuna[100000], D[100000];
	while(scanf("%d%d", &m, &n) && n)
	{
		for(i=0;i<m*n;i++) scanf("%d", &D[i]);
		for(i=0;i<m;i++)
		{
			maxColuna[n-1] = D[i*n + n-1];
			if(n > 1) maxColuna[n-2] = D[i*n + n-2];
			else maxColuna[1] = 0;
			if(n > 2) maxColuna[n-3] = D[i*n + n-1] + D[i*n + n-3];
			for(j=n-4;j>=0;j--) maxColuna[j] = D[i*n + j] + max(maxColuna[j+2], maxColuna[j+3]);
			maxLinha[i] = max(maxColuna[0], maxColuna[1]);
		}
		maxColuna[m-1] = maxLinha[m-1];
		if(m > 1) maxColuna[m-2] = maxLinha[m-2];
		else maxColuna[1] = 0;
		if(m > 2) maxColuna[m-3] = maxLinha[m-1] + maxLinha[m-3];
		for(j=m-4;j>=0;j--) maxColuna[j] = maxLinha[j] + max(maxColuna[j+2], maxColuna[j+3]);
		maxLinha[i] = max(maxColuna[0], maxColuna[1]);
		printf("%d\n", max(maxColuna[0], maxColuna[1]));
	}
	return 0;
}

