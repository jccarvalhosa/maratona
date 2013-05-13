#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#define INF 1000000

using namespace std;

vector<pair<int, int> > vp;
vector<pair<pair<int, int>, pair<int, int> > > vs;
int grafo[500][500], grau[500];
double dist[500][500], d[500];

int mod(int a) { return a > 0 ? a : -a;}

int prod(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
}
 
bool intersepta(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int p1 = prod(x1, y1, x2, y2, x3, y3);
	int p2 = prod(x1, y1, x2, y2, x4, y4);
	int p3 = prod(x3, y3, x4, y4, x1, y1);
	int p4 = prod(x3, y3, x4, y4, x2, y2);
	if (p1 == 0 || p2 == 0 || p3 == 0 || p4 == 0) return false;
	int s1 = p1 / mod(p1);
	int s2 = p2 / mod(p2);
	int s3 = p3 / mod(p3);
	int s4 = p4 / mod(p4);
	return s1 != s2 && s3 != s4;
}

double distancia(int x1, int y1, int x2, int y2)
{
	int S = vs.size();
	for(int i=0;i<S;i++) if(intersepta(x1, y1, x2, y2, vs[i].first.first, vs[i].first.second, vs[i].second.first, vs[i].second.second)) return INF;
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void dijkstra(int s, int dest)
{
	int i, u, v;
	priority_queue<pair<int, int> > Q;
	for(v=0;v<vp.size();v++) d[v] = INF;
	d[s] = 0;
	Q.push(make_pair(-d[s], s));
	while(!Q.empty())
	{
		u = Q.top().second;
		if(u == dest) break;
		Q.pop();
		for(i=0;i<grau[u];i++)
		{
			v = grafo[u][i];
			if(d[v] > d[u] + dist[u][v])
			{
				d[v] = d[u] + dist[u][v];
				Q.push(make_pair(-d[v], v));
			}
		}
	}
}

int main()
{
	int xi, xf, yi, yf, N, achou;
	int i, j;
	pair<int, int> p1, p2;
	pair<pair<int, int>, pair<int, int> > s;
	while(scanf("%d%d%d%d%d", &xi, &yi, &xf, &yf, &N) && (xi != 0 || yi != 0 || xf != 0 || yf != 0 || N != 0))
	{
		vp.clear();
		vs.clear();
		vp.push_back(make_pair(xi, yi));
		vp.push_back(make_pair(xf, yf));
		for(i=0;i<N;i++)
		{
			scanf("%d%d%d%d", &xi, &yi, &xf, &yf);
			p1 = make_pair(xi, yi);
			p2 = make_pair(xf, yf);
			vp.push_back(p1);
			vp.push_back(p2);
			vs.push_back(make_pair(p1, p2));
		}
		for(i=0;i<vp.size();i++) grau[i] = 0;
		achou = 0;
		for(i=0;i<vp.size();i++) for(j=i+1;j<vp.size();j++)
		{
			if(achou) break;
			dist[i][j] = dist[j][i] = distancia(vp[i].first, vp[i].second, vp[j].first, vp[j].second);
			if(dist[i][j] != INF) 
			{
				if(i == 0 && j == 1) achou = 1;
				grafo[i][grau[i]++] = j;
				grafo[j][grau[j]++] = i;
			}		
		}
		if(achou) printf("%.2lf\n", dist[0][1]);
		else
		{
			dijkstra(0, 1);
			printf("%.2lf\n", d[1]);
		}
	}
	return 0;
}
