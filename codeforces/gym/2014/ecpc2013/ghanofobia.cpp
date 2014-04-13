#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t=1, T, a, b;
	freopen("ghanophobia.in", "r", stdin);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d:%d", &a, &b);
		printf("Case %d: ", t++);
		if(a==6 && b==1) printf("PENALTIES\n");
		else
		{
			if(a-b>5) printf("YES\n");
			else if(a-b<5) printf("NO\n");
			else if(a==5) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
