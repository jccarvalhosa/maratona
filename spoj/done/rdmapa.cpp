#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, sum=0;
int vis[500];
int dist[500][500];
vector<int> grafo[500];
priority_queue<pair<int,int> > pdis;

void prim()
{
	pair<int, int> ptop;
	int v, d, i, a;
	while(!pdis.empty())
	{
		ptop = pdis.top();
		d = -ptop.first;
		v = ptop.second;
		pdis.pop();
		if(!vis[v])
		{
			vis[v] = 1;
			sum += d;
			for(i=0;i<grafo[v].size();i++)
			{
				a = grafo[v][i];
				if(!vis[a]) pdis.push(make_pair(-dist[v][a], a));
			}
		}
	}
}

int main()
{
	int M, a, b, d, i;
	scanf("%d%d", &N, &M);
	memset(vis, 0, sizeof(vis));
	while(M--)
	{
		scanf("%d%d%d", &a, &b, &d);
		a--; b--;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		dist[a][b] = dist[b][a] = d;
	}
	vis[0] = 1;
	for(i=0;i<grafo[0].size();i++)
	{
		a = grafo[0][i];
		pdis.push(make_pair(-dist[a][0], a));
	}
	prim();
	printf("%d\n", sum);
	return 0;
}
