#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	int N, P, F, ind;
	int i, total=0, soma=0, ord[100000];
	priority_queue<pair<int, int> > p;
	vector<pair<int, pair<int, int> > > v;
	scanf("%d", &N);
	for(i=1;i<=N;i++)
	{
		scanf("%d%d", &P, &F);
		v.push_back(make_pair(-F-P, make_pair(P, i)));
		soma += P;
	}
	sort(v.begin(), v.end());
	total = i = 0;
	while(total < N)
	{
		while(i<N)
		{
			P = v[i].second.first;
			F = -v[i].first;
			ind = v[i].second.second;
			if(F >= soma) p.push(make_pair(-ind, P));
			else break;
			i++;
		}
		if(p.empty()) break;
		ord[total++] = -p.top().first;
		soma -= p.top().second;
		p.pop();
	}
	if(total != N) printf("IMPOSSIVEL\n");
	else for(i=0;i<total;i++) printf("%d\n", ord[i]);
	return 0;
}
