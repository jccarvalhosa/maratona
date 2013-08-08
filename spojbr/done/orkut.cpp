#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int N, M, teste=1, dep[30];
	int i, j, a, b;
	char amigo[16];
	map<string, int> id;
	map<int, string> nome;
	vector<int> grafo[30], topsort;
	while(scanf("%d", &N) && N)
	{
		printf("Teste %d\n", teste++);
		nome.clear();
		id.clear();
		topsort.clear();
		for(i=0;i<N;i++)
		{
			scanf(" %s ", amigo);
			id[amigo] = i;
			nome[i] = amigo;
			grafo[i].clear();
		}
		for(i=0;i<N;i++)
		{
			scanf(" %s ", amigo);
			a = id[amigo];
			scanf("%d", &M);
			dep[a] = M;
			if(!M) topsort.push_back(a);
			while(M--)
			{
				scanf(" %s ", amigo);
				b = id[amigo];
				grafo[b].push_back(a);
			}
		}
		for(i=0;i<topsort.size();i++)
		{
			a = topsort[i];
			for(j=0;j<grafo[a].size();j++)
			{
				b = grafo[a][j];
				dep[b]--;
				if(!dep[b]) topsort.push_back(b);
			}
		}
		if(topsort.size() != N) printf("impossivel");
		else for(i=0;i<topsort.size();i++) cout << nome[topsort[i]] << " ";
		printf("\n\n");
	}
	return 0;
}
