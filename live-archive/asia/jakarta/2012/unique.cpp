#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj[11111];
int vis[11111], cycle[11111], pi[11111];

void dfs(int u, int p)
{
	int i, v;
	vis[u]=1;
	for(i=0; i<adj[u].size(); i++)
	{
		v=adj[u][i];
		if(v==p) continue;
		if(!vis[v])
		{
			pi[v]=u;
			dfs(v, u);
		}
		else if(vis[v]==1) cycle[u]=v;
	}
	vis[u]=2;
}

int go(int u, int p)
{
	int i, v, ret=1;
	vis[u]=1;
	for(i=0; i<adj[u].size(); i++)
	{
		v=adj[u][i];
		if(v==p) continue;
		if(!vis[v]) ret+=go(v, u);
	}
	return ret;
}

int main()
{
	int i, j, t=1, n, m, T, a, b, ans, ret;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n, &m);
		for(i=1; i<=n; i++)
		{
			adj[i].clear();
			vis[i]=cycle[i]=0;
			pi[i]=-1;
		}
		for(i=0; i<m; i++)
		{
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(1, 1);
		for(i=1; i<=n; i++) vis[i]=0;
		for(i=1; i<=n; i++) if(cycle[i] && !vis[i]) for(j=i; ; j=pi[j])
		{
			cycle[j]=cycle[i];
			vis[j]=1;
			if(j==cycle[i]) break;
		}
		for(i=1; i<=n; i++) if(!cycle[i]) vis[i]=0;
		ans=0;
		for(i=1; i<=n; i++) if(!cycle[i] && !vis[i])
		{
			ret=go(i, i);
			ans+=((ret*(ret-1))/2);
		}
		printf("Case #%d: %d\n", t++, ans);
	}
	return 0;
}
