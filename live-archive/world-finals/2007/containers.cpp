#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define INF 1000000000

using namespace std;

char s[1111];

int n, match[2222], d[2222];
vector<int> adj[2222];

int bfs()
{
	int i;
	queue<int> q;
	for(i=0; i<=n; i++) {
		if(!match[i]) {
			d[i]=0;
			q.push(i);
		}
		else d[i]=INF;
	}
	d[0]=INF;
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		if(v==0) continue;
		for(i=0; i<adj[v].size(); i++)
		{
			int u=adj[v][i];
			if(d[match[u]]==INF) {
				d[match[u]]=d[v]+1;
				q.push(match[u]);
			}
		}
	}
	return d[0]!=INF;
}

int dfs(int v)
{
	if(!v) return 1;
	for(int i=0; i<adj[v].size(); i++) {
		int u=adj[v][i];
		if(d[match[u]]==d[v]+1 && dfs(match[u])) {
			match[v]=u;
			match[u]=v;
			return 1;
		}
	}
	d[v]=INF;
	return 0;
}

int hk() {
	int m=0;
	while(bfs()) for(int i=1; i<=n; i++) if(!match[i] && dfs(i)) m++;
	return m;
}

int main()
{
	int i, j, t=1;
	while(scanf("%s", s) && s[0]!='e')
	{
		n=strlen(s);
		for(i=0; i<=2*n; i++) adj[i].clear(), match[i]=0, d[i]=INF;
		for(i=0; i<n; i++) for(j=i+1; j<n; j++) if(s[i]>=s[j]) adj[i+1].push_back(n+j+1);
		printf("Case %d: %d\n", t++, n-hk());
	}
	return 0;
}
