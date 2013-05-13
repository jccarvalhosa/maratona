#include <stdio.h>

int N, sum=0;
int v[100000];

void merge(int a, int b)
{
	int vleft[50000], vright[50000];
	int i, lcount, rcount, lsize, rsize;
	lsize = rsize = lcount = rcount = 0;
	i = a;
	while(i<=(a+b)/2) vleft[lsize++] = v[i++];
	while(i<=b) vright[rsize++] = v[i++];
	i = a;
	while(lcount < lsize && rcount < rsize)
	{
		if(vleft[lcount] < vright[rcount]) v[i++] = vleft[lcount++];
		else
		{
			v[i++] = vright[rcount++];		
			sum += lsize - lcount;
		}
	}
	while(lcount < lsize) v[i++] = vleft[lcount++];
	while(rcount < rsize) v[i++] = vright[rcount++];
}

void merge_sort(int a, int b)
{
	if(a == b) return;
	merge_sort(a, (a+b)/2);
	merge_sort((a+b)/2+1, b);
	merge(a, b);
}


int main()
{
	int i, c;
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d", &v[i]);
	merge_sort(0, N-1);
	printf("%d\n", sum);
	return 0;
}
