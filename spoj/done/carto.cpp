#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector<int> grafo[1000000];
int dmax;
int voposto;

void dfs(int v, int pai, int d)
{
	int i, c;
	for(i=0;i<grafo[v].size();i++)
	{
		c = grafo[v][i];
		if(c != pai)
		{
			if(dmax < d+1)
			{
				dmax = d+1;	
				voposto = c;
			}
			dfs(c, v, d+1);
		}
	}
}

int main()
{
	int N, A, B;
	int start, d, i, j, first, second, c;
	scanf("%d", &N);

	for(i=0;i<N-1;i++)
	{
		scanf("%d%d", &A, &B);
		A--; B--;
		grafo[A].push_back(B);
		grafo[B].push_back(A);
	}
	
	dfs(0, 0, 0);
	dfs(voposto, voposto, 0);

	printf("%d\n", dmax);

	return 0;
}
