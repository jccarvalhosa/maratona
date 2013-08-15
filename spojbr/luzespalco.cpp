#include <stdio.h>
#include <vector>

using namespace std;

int L, B, soma;
int luz[10000], vis[10000];
vector<int> grafo[10000];

void dfs(int v)
{
	vis[v] = 1;
	if(luz[v]) soma++;
	for(int i=0;i<grafo[v].size();i++) if(!vis[grafo[v][i]]) dfs(grafo[v][i]);
}

int impossivel()
{
	for(int i=0;i<L;i++) vis[i] = 0;
	for(int i=0;i<L;i++) if(!vis[i])
	{
		soma = 0;
		dfs(i);
		if(soma % 2 == 1) return 1;
	}
	return 0;
}

int main()
{
	int i, a, b;
	scanf("%d%d", &L, &B);
	for(i=0;i<L;i++) scanf("%d", &luz[i]);
	for(i=0;i<L;i++)
	{
		scanf("%d", &a);
		luz[i] = (luz[i] + a) % 2;
	}
	for(i=0;i<B;i++)
	{
		scanf("%d%d", &a, &b);
		grafo[a-1].push_back(b-1);
		grafo[b-1].push_back(a-1);
	}
	if(impossivel()) printf("N\n");
	else printf("S\n");
	return 0;
}
