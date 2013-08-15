#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
	int N, C, K, X;
	int i;
	vector<pair<int, int> > v;
	while(scanf("%d%d%d", &N, &C, &K) && N)
	{
		v.clear();
		for(i=1;i<=K;i++) v.push_back(make_pair(0, i));
		for(i=0;i<N*C;i++)
		{
			scanf("%d", &X);
			v[X-1].first++;
		}
		sort(v.begin(), v.end());
		printf("%d", v[0].second);
		for(i=1;v[i].first == v[0].first;i++) printf(" %d", v[i].second);
		printf("\n");
	}
	return 0;

}
