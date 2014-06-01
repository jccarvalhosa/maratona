#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > adj[5555];
vector<pair<int, pair<int, int> > > travel[11111];
int vis[3600][555], d[3600][555];

void dijkstra(int t, int u)
{
	int v, i, j, dist, id; 
	priority_queue<pair<int, pair<int, int> > > q;
	d[t][u]=720;
	q.push(make_pair(-d[t][u], make_pair(t, u)));
	while(!q.empty())
	{
		dist=-q.top().first;
		t=q.top().second.first;
		u=q.top().second.second;
		q.pop();
		if(vis[t][u]) continue;
		vis[t][u]=1;
		if(d[t+1][u]>d[t][u]+1) {
			d[t+1][u]=d[t][u]+1;
			q.push(make_pair(-d[t+1][u], make_pair(t+1, u)));
		}
		for(i=0; i<adj[u].size(); i++)
		{
			v=adj[u][i].first;
			id=adj[u][i].second;
			for(j=0; j<travel[id].size(); j++)
			{
				int start=travel[id][j].first;
				int stop=travel[id][j].second.first;
				int tempo=travel[id][j].second.second;
				int daux=dist%1440;
				if(daux<start || daux>stop) continue;
				if(min(t/2, 240)>=tempo && d[min(t, 480)-2*tempo][v]>d[t][u]+tempo)
				{
					d[min(t, 480)-2*tempo][v]=d[t][u]+tempo;
					q.push(make_pair(-d[min(t, 480)-2*tempo][v], make_pair(min(t, 480)-2*tempo, v)));
				}
			}
		}
	}
}

int main()
{
	int i, n, m, j;
	while(scanf("%d %d", &n, &m) && (n || m))
	{
		for(i=0; i<3600; i++) for(j=0; j<n; j++) d[i][j]=INF, vis[i][j]=0;
		for(i=0; i<n; i++) adj[i].clear();
		for(i=0; i<m; i++)
		{
			int a, b;
			travel[i].clear();
			scanf("%d %d", &a, &b);
			adj[a].push_back(make_pair(b, i));
			adj[b].push_back(make_pair(a, i));
			int start, stop, t;
			while(1)
			{
				scanf("%d %d %d", &start, &stop, &t);
				travel[i].push_back(make_pair(start, make_pair(stop, t)));
				if(stop==1439) break;
			}
		}
		dijkstra(480, 0);
		int ans=INF;
		for(i=0; i<3600; i++) ans=min(ans, d[i][n-1]);
		printf("%d\n", ans-720);
	}
	return 0;
}
