#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 1000000000

using namespace std;

int pi[222], is[222], ans, n, d[222], vis[222];
vector<pair<int, int> > adj[222];

void prim()
{
	int i, u, v;
	priority_queue<pair<int, int> > q;
	for(i=1; i<=n; i++) d[i]=INF, vis[i]=0;
	for(i=1; i<=n; i++) if(is[i])
	{
		d[i]=0;
		q.push(make_pair(-d[i], i));
	}
	while(!q.empty())
	{
		u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		ans+=d[u];
		for(i=0; i<adj[u].size(); i++)
		{
			v=adj[u][i].first;
			int w=adj[u][i].second;
			if(!vis[v] && w<d[v])
			{
				d[v]=w;
				q.push(make_pair(-d[v], v));
			}
		}
	}
}

int main()
{
	int i, t=1, T, m, k, p, a, b, c;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &n, &m, &k);
		memset(is, 0, sizeof(is));
		ans=0;
		for(i=1; i<=n; i++) pi[i]=i, adj[i].clear();
		for(i=0; i<k; i++)
		{
			scanf("%d", &p);
			is[p]=1;
		}
		for(i=0; i<m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		prim();
		printf("Case #%d: %d\n", t++, ans);
	}
	return 0;
}
