#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

ll best[111];

int main()
{
	int i, T, t=1, n;
	ll t0, s, r;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		priority_queue<ll> vis[111];
		printf("Case #%d:\n", t++);
		for(i=0;i<=100;i++) best[i] = -1e18;
		for(i=0; i<n; i++)
		{
			char c;
			scanf(" %c", &c);
			if(c=='P')
			{
				scanf("%lld %lld %lld", &t0, &s, &r);
				vis[r].push(s-r*t0);
				best[r] = vis[r].top();
			}
			else
			{
				scanf("%lld", &t0);
				int id;
				ll ans=-(ll)(1e18);
				for(int j=0; j<=100; j++)
				{
					ll v=best[j]+t0*j;
					if(v>=ans) ans=v, id=j;
				}
				vis[id].pop();
				if(vis[id].empty()) best[id] = -1e18;
				else best[id] = vis[id].top();
				printf("%lld %d\n", ans, id);
			}
		}
	}
	return 0;
}
