#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int ans[11111];

int main()
{
	int n, h, a, b, c;
	while(scanf("%d %d %d %d", &n, &h, &a, &b)!=EOF)
	{
		priority_queue<pair<int, int> > q;
		for(int i=1; i<=n; i++) ans[i]=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &c);
			q.push(make_pair(-c, i));
			int p;
			while(1)
			{
				p=q.top().second;
				if(i-p>=h) q.pop();
				else break;
			}
			ans[p]++;
		}
		printf("%d", ans[a]);
		for(int i=a+1; i<=b; i++) printf("\t%d", ans[i]);
		printf("\n");
	}
}
