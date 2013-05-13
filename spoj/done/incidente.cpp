#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <algorithm>
#define INF 1000000

using namespace std;

int tp[500];
vector<pair<int, int> > vp;
vector<pair<pair<int, int>, pair<int, int> > > vs;
double dist[500][500][2], d[500][500];

int mod(int a) { return a > 0 ? a : -a;}

int prod(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
}

bool intersepta(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int p1 = prod(x1, y1, x2, y2, x3, y3);
	int p2 = prod(x1, y1, x2, y2, x4, y4);
	int p3 = prod(x3, y3, x4, y4, x1, y1);
	int p4 = prod(x3, y3, x4, y4, x2, y2);
	if(p1 == 0)
	{
		if(x3 > min(x1, x2) && x3 < max(x1, x2)) return true;
		return false;
	}
	if(p2 == 0)
	{
		if(x4 > min(x1, x2) && x4 < max(x1, x2)) return true;
		return false;
	}
	if(p3 == 0)
	{
		if(p4 != 0) return false;
		if(x1 < min(x3, x4) && x2 < min(x3, x4)) return false;
		if(x1 > max(x3, x4) && x2 > max(x3, x4)) return false;
		return true;
	}
	if(p4 == 0) return false;
	int s1 = p1 / mod(p1);
	int s2 = p2 / mod(p2);
	int s3 = p3 / mod(p3);
	int s4 = p4 / mod(p4);
	return s1 != s2 && s3 != s4;
}

double distancia(int x1, int y1, int x2, int y2)
{
	for(int i=0;i<vs.size();i++)
	{
		if(intersepta(x1, y1, x2, y2, vs[i].first.first, vs[i].first.second, vs[i].second.first, vs[i].second.second)) return INF;
	}
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


void dijkstra(int s, int T)
{
	int i, u, v, t;
	priority_queue<pair<double, pair<int, int> > > Q;
	for(v=0;v<vp.size();v++) for(i=0;i<=T;i++) d[v][i] = INF;
	d[s][T] = 0;
	Q.push(make_pair(-d[s][T], make_pair(s, T)));
	while(!Q.empty())
	{
		u = Q.top().second.first;
		t = Q.top().second.second;
		Q.pop();
		for(v=0;v<vp.size();v++) 
		{
			if(d[v][t] > d[u][t] + dist[u][v][0])
			{
				d[v][t] = d[u][t] + dist[u][v][0];
				Q.push(make_pair(-d[v][t], make_pair(v, t)));
			}
			if(dist[u][v][1] == 0 && t != 0 && d[v][t-1] > d[u][t])
			{
				d[v][t-1] = d[u][t];
				Q.push(make_pair(-d[v][t-1], make_pair(v, t-1)));
			}
		}
	}
}


int main()
{
	int T, M, C;
	int xi, xf, yi, yf, i, j, src, dest;
	double dmin;
	pair<int, int> p1, p2;
	pair<pair<int, int>, pair<int, int> > s;
	while(scanf("%d%d%d", &T, &M, &C) != EOF)
	{
		vp.clear();
		vs.clear();
		for(i=0;i<M;i++)
		{
			scanf("%d%d%d%d", &xi, &yi, &xf, &yf);
			p1 = make_pair(xi, yi);
			p2 = make_pair(xf, yf);
			vp.push_back(p1);
			vp.push_back(p2);
			tp[vp.size()-1] = tp[vp.size()-2] = 0;	
			vs.push_back(make_pair(p1, p2));
		}
		for(i=0;i<C;i++)
		{
			scanf("%d%d", &xi, &yi);
			vp.push_back(make_pair(xi, yi));
			tp[vp.size()-1] = 1;
		}
		scanf("%d%d%d%d", &xi, &yi, &xf, &yf);
		p1 = make_pair(xi, yi);
		p2 = make_pair(xf, yf);
		vp.push_back(p1);
		vp.push_back(p2);
		tp[vp.size()-1] = tp[vp.size()-2] = 0;
		for(i=0;i<vp.size();i++)
		{
			dist[i][i][0] = 0;
			dist[i][i][1] = INF;
			for(j=i+1;j<vp.size();j++)
			{
				dist[i][j][0] = dist[j][i][0] = distancia(vp[i].first, vp[i].second, vp[j].first, vp[j].second);
				if(tp[i] && tp[j] && dist[i][j][0] != INF) dist[i][j][1] = dist[j][i][1] = 0;
				else dist[i][j][1] = dist[j][i][1] = INF;
			}
		}
		src = vp.size() - 2;
		dest = vp.size() - 1;
		dijkstra(src, T);
		dmin = d[dest][0];
		for(i=1;i<=T;i++) if(dmin > d[dest][i]) dmin = d[dest][i];
		printf("%.1lf\n", dmin);
	}
	return 0;
}
