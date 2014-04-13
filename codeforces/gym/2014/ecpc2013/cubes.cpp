#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t=1, T, n, a[111], i;
	freopen("cubes.in", "r", stdin);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++) scanf("%d", &a[i]);
		printf("Case %d:\n", t++);
		sort(a, a+n);
		vector<int> v1, v2;
		for(i=n-2; i>=0; i-=2) v1.push_back(a[i]);
		for(i=n-1; i>=0; i-=2) v2.push_back(a[i]);
		reverse(v2.begin(), v2.end());
		int f=0;
		for(i=0; i<v1.size(); i++)
		{
			if(f) printf(" ");
			f=1;
			printf("%d", v1[i]);
		}
		for(i=0; i<v2.size(); i++)
		{
			if(f) printf(" ");
			f=1;
			printf("%d", v2[i]);
		}
		printf("\n");
	}
	return 0;
}
