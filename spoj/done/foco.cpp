#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int N, A, B;
	int i, focos, fim;
	vector<pair<int, int> > v;

	while(scanf("%d", &N) != EOF) 
	{
		for(i=0;i<N;i++)
		{
			scanf("%d %d", &A, &B);
			v.push_back(make_pair(A, B));
		}
		sort(v.begin(), v.end());
		focos = 1;
		fim = v[N-1].first;
		for(i=N-2;i>=0;i--)
		{
			if(v[i].second < fim)
			{
				focos++;
				fim = v[i].first;
			}	
		}
		printf("%d\n", focos);
		v.clear();
	}
	return 0;
}
