#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	int A, i, j, a, b, nautor, teste=1;
	int adj[100][100];
	int nerdos[100];
	char nome[4], sep, sobrenome[30];
	map <pair<string, string>, int > num;
	vector<int> artigo[100];
	vector<pair<string, string> > autores;
	pair<string, string> autor;
	queue<int> Q;
	while(scanf("%d", &A) && A)
	{
		memset(adj, 0, sizeof(adj));
		memset(nerdos, 0, sizeof(nerdos));
		autores.clear();
		num.clear();
		for(i=0;i<A;i++)
		{
			artigo[i].clear();
			do
			{
				scanf(" %c. %s", &nome[0], sobrenome);
				sep = sobrenome[strlen(sobrenome)-1];
				nome[1] = '.'; nome[2] = ' '; nome[3] = '\0';
				sobrenome[strlen(sobrenome)-1] = '\0';
				autor = make_pair(sobrenome, nome);
				if(num.find(autor) == num.end())
				{
					num[autor] = num.size()-1;
					autores.push_back(autor);
					if(autor.second == "P. " && autor.first == "Erdos")
					{
						nerdos[num[autor]] = 0;
						Q.push(num[autor]);
					}
					else nerdos[num[autor]] = 1000;
				}
				artigo[i].push_back(num[autor]);
				b = artigo[i][artigo[i].size()-1];
				for(j=0;j<artigo[i].size()-1;j++)
				{
					a = artigo[i][j];
					adj[a][b] = adj[b][a] = 1;
				}
			} while(sep == ',');
		}
		sort(autores.begin(), autores.end());
		while(!Q.empty())
		{
			a = Q.front();
			Q.pop();
			for(i=0;i<autores.size();i++) if(adj[a][i] && nerdos[i] == 1000)
			{
				Q.push(i);
				nerdos[i] = nerdos[a] + 1;
			}
		}
		printf("Teste %d\n", teste++);
		for(i=0;i<autores.size();i++) if(autores[i].first != "Erdos" || autores[i].second != "P. ")
		{
			nautor = nerdos[num[autores[i]]];
			cout << autores[i].second <<  autores[i].first << ": ";
			if(nautor == 1000) printf("infinito");
			else printf("%d", nautor);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
