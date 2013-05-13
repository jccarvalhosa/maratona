#include <stdio.h>
#include <utility>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

int mdc(int a, int b)
{
	if(a % b == 0) return b;
	return mdc(b, a % b);
}

int m[500000];
map<pair<int, int>, int > d[500000];
map<pair<int, int>, int >::iterator it;

int main()
{
	int N, x, y, i, j, id1, id2, c, u;
	int soma;
	map<pair<int, int>, int> id;
	vector<pair<int, int> > v;
	pair<int, int> p1, p2;
	scanf("%d", &N);
	memset(m, 0, sizeof(m));
	for(i=0;i<N;i++)
	{
		scanf("%d%d", &x, &y);
		v.push_back(make_pair(x, y));
	}
	for(i=0;i<N;i++) for(j=i+1;j<N;j++)
	{
		x = v[i].first + v[j].first;
		y = v[i].second + v[j].second;
		p1 = make_pair(x, y);
		if(id.count(p1) == 0) id1 = id[p1] = id.size() - 1;
		else id1 = id[p1];
		m[id1]++;
		x = v[i].first - v[j].first;
		y = v[i].second - v[j].second;
		if(x == 0 && y == 0) p2 = make_pair(0, 0);
		else if(x == 0) p2 = make_pair(0, 1);
		else if(y == 0) p2 = make_pair(1, 0);
		else
		{
			u = mdc(mod(x), mod(y));
			if(x < 0)
			{
				x = -x;
				y = -y;
			}
			x /= u;
			y /= u;
			p2 = make_pair(x, y);
		}
		if(d[id1].count(p2) == 0) d[id1][p2] = 1;
		else d[id1][p2]++;
	}
	soma = 0;
	for(i=0;i<id.size();i++)
	{
		c = m[i];
		soma  += c * (c - 1) / 2;
		for(it=d[i].begin(); it != d[i].end(); it++)
		{
			c = (*it).second;
			soma -= c * (c - 1) / 2;
		}
	}
	printf("%d\n", soma);
	return 0;
}
