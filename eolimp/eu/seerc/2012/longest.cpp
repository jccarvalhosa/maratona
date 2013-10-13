#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef long long ll;

int g[10000000][3];
int estados;

void init()
{
	for(int i=0;i<3;i++) g[0][i] = -1;
	estados = 1;
}

void add(ll d, int b, int id)
{
	int e=0;
	for(int i=31;i>31-b;i--) {
		int next = ((d & (1ll<<i)) > 0);
		if(g[e][next] == -1) {
			g[e][next] = estados;
			for(int j=0;j<3;j++) g[estados][j] = -1;
			estados++;
		}
		e = g[e][next];
	}
	g[e][2] = id;
}

int go(ll d)
{
	int e=0;
	int l=-1;
	if(g[e][2] != -1) l = g[e][2];
	for(int i=31;i>=0;i--)
	{
		e = g[e][(d & (1ll<<i)) > 0 ];
		if(e == -1) break;
		if(g[e][2] != -1) l = g[e][2];
	}
	return l;
}

int main()
{
	int n, m, b;
	ll d;
	cin >> n >> m;
	init();
	for(int i=0;i<n;i++)
	{
		scanf("%llx %d", &d, &b);
		add(d,b,i);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%llx", &d);
		cout << go(d) << endl;
	}
	return 0;
}
