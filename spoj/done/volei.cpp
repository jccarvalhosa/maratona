#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;

typedef struct
{
	int xi, xf, yi, yf;
} segmento;

vector<segmento> ladov, ladoh;
vector<int> retav, retah;
vector<pair<int, int> > ponto;
int adj[300][300], vis[300];
int soma, src, dest, chegou;

int fora(int x, int y)
{
	int i, numdir, cima, baixo, menor;
	for(i=0;i<ladoh.size();i++) if(ladoh[i].yi == y) if(ladoh[i].xi <= x && ladoh[i].xf >= x) return 0;
	for(i=0;i<ladov.size();i++) if(ladov[i].xi == x) if(ladov[i].yi <= y && ladov[i].yf >= y) return 0;
	cima = baixo = numdir = 0;
	for(i=0;i<ladov.size();i++) if(ladov[i].xi > x)
	{
		if(ladov[i].yi < y && ladov[i].yf > y) numdir++;
		else if(ladov[i].yi == y || ladov[i].yf == y)
		{
			if(ladov[i].yf > y) cima++;
			if(ladov[i].yi < y) baixo++;
			if(cima && baixo)
			{
				menor = min(cima, baixo);
				numdir += menor;
				cima -= menor;
				baixo -= menor;
			}
		}
	}
	if(numdir % 2 == 1) return 0;
	return 1;
}

void dfs(int v)
{
	int i;
	vis[v] = 1;
	if(v == dest)
	{
		soma++;
		chegou = 1;
		vis[v] = 0;
		return;
	}
	for(i=dest;i>0;i--) if(adj[v][i] && !vis[i])
	{
		dfs(i);
		if(chegou)
		{
			adj[v][i]--;
			adj[i][v]++;
			if(v == src) chegou = 0;
			else
			{
				vis[v] = 0;
				return;
			}
		}
	}
}


int main()
{
	int N, i, j, a, b, oldx, oldy, newx, newy;
	set<int> seth, setv;
	segmento l;
	while(scanf("%d", &N) && N)
	{
		ladoh.clear(); ladov.clear();
		retav.clear(); retah.clear();
		seth.clear(); setv.clear();
		ponto.clear();
		for(i=0;i<N;i++)
		{
			scanf("%d%d", &a, &b);
			ponto.push_back(make_pair(a, b));
		}
		for(i=0;i<N;i++)
		{
			if(ponto[i].first == ponto[(i+1)%N].first)
			{
				oldy = ponto[i].second;
				newy = ponto[(i+1)%N].second;
				l.yi = min(oldy, newy);
				l.yf = max(oldy, newy);
				l.xi = l.xf = ponto[i].first;
				ladov.push_back(l);
				if(setv.count(l.xi) == 0) retav.push_back(l.xi);
				setv.insert(l.xi);
			}
			else if(ponto[i].second == ponto[(i+1)%N].second)
			{
				oldx = ponto[i].first;
				newx = ponto[(i+1)%N].first;
				l.xi = min(oldx, newx);
				l.xf = max(oldx, newx);
				l.yi = l.yf = ponto[i].second;
				ladoh.push_back(l);
				if(seth.count(l.yi) == 0) retah.push_back(l.yi);
				seth.insert(l.yi);
			}
		}
		src = soma = chegou = 0;
		dest = retav.size() + retah.size() + 1;
		for(i=0;i<=retah.size()+retav.size()+1;i++)
		{
			vis[i] = 0;
			for(j=0;j<=retav.size()+retah.size()+1;j++) adj[i][j] = adj[j][i] = 0;
		}
		for(i=0;i<retav.size();i++) for(j=0;j<retah.size();j++) if(fora(retav[i], retah[j])) adj[i+1][retav.size()+j+1] = 1;
		for(i=1;i<=retav.size();i++) adj[src][i] = 1;
		for(i=1;i<=retah.size();i++) adj[retav.size()+i][dest] = 1;
		dfs(src);
		soma += (retav.size() + retah.size() - 2 * soma);
		printf("%d\n", soma);
	}
	return 0;
}
