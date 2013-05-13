#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
	int N, smax;
	int T, P, i, j, a, b;
	int tesouro[1000], soma[1000], graudep[1000];
	vector<int> grafo[1000], topsort;
	memset(graudep, 0, sizeof(graudep));
	while(scanf("%d", &N) && N)
	{
		for(i=0;i<N;i++) grafo[i].clear();
		topsort.clear();
		smax = 0;
		for(i=0;i<N;i++)
		{
			scanf("%d%d", &T, &P);
			tesouro[i] = soma[i] = T;
			while(P--)
			{
				scanf("%d", &j);
				grafo[i].push_back(j-1);
				graudep[j-1]++;
			}
		}

		for(i=0;i<N;i++) if(!graudep[i]) topsort.push_back(i);		
		for(i=0;i<topsort.size();i++) for(j=0;j<grafo[topsort[i]].size();j++)
		{
			a = grafo[topsort[i]][j];
			graudep[a]--;
			if(!graudep[a]) topsort.push_back(a);
		}

		for(i=0;i<topsort.size();i++)
		{
			a = topsort[i];
			if(smax < soma[a]) smax = soma[a];
			for(int ind=0;ind<grafo[a].size();ind++)
			{
				b = grafo[a][ind];
				if(soma[b] < soma[a] + tesouro[b]) soma[b] = soma[a] + tesouro[b];
			}
		}
		printf("%d\n", smax);
	}
	return 0;
}
