#include <iostream>
#include <cstdio>

using namespace std;

int sz(int p)
{
	int r = 0;
	while(p > 0)
	{
		p/=10;
		r++;
	}
	return r;
}

int main()
{
	int n, x, c=1;
	while(1)
	{
		int m=0, p[222], v=0;
		scanf("%d", &n);
		for(int i=0;i<=n;i++)
		{
			cin >> p[i];
			if(i == 0) m++;
			else if(p[i]==0) m += 2;
			else m += (3+sz(p[i]));
		}
		if(n == 0) break;
		m--;
		scanf("%d", &x);
		for(int i=0;i<=n;i++)
		{
			if((n-i)%2) v += (p[i]*x);
			else v += (p[i]*x*x);
		}
		printf("Polynomial %d: %d %d\n", c++, v, m);
	}
	return 0;
}
