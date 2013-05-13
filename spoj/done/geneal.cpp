#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> grafo[2000];
map<string, int> id;
int dmax, voposto;

void dfs(int v, int p, int d)
{
	if(d > dmax)
	{
		dmax = d;
		voposto = v;
	}
	for(int i=0;i<grafo[v].size();i++) if(grafo[v][i] != p) dfs(grafo[v][i], v, d+1);
}

int main()
{
	int N, a, b;
	char pai[51], filho[51];
	map<int, string> nome;
	vector<string> aux;
	scanf("%d", &N);
	while(N--)
	{
		scanf(" %s ", pai);
		scanf(" %s ", filho);
		if(id.find(pai) == id.end()) id[pai] = id.size() - 1;
		if(id.find(filho) == id.end()) id[filho] = id.size() - 1;
		a = id[pai]; 
		b = id[filho];
		nome[a] = pai;
		nome[b] = filho;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	dmax = 0;
	dfs(0, 0, 0);
	a = voposto;
	aux.push_back(nome[a]);
	dmax = 0;
	dfs(a, a, 0);
	b = voposto;
	aux.push_back(nome[b]);
	sort(aux.begin(), aux.end());
	cout << aux[0] << " " << aux[1] << " " << dmax << endl;
	return 0;
}
