#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int N;
int dep[50000], vsort[50000];
vector<int> grafo[50000];
set<int> nodep;

int topsort(int ind)
{
	set<int>::iterator it;
	int i, v, w;
	if(ind == N) return 1;
	if(nodep.empty()) return 0;
	it = nodep.begin();
	v = *it;
	vsort[ind] = v;
	nodep.erase(it);
	for(i=0;i<grafo[v].size();i++)
	{
		w = grafo[v][i];
		dep[w]--;
		if(!dep[w]) nodep.insert(w);
	}
	return topsort(ind+1);
}

int main()
{
	int M, a, b, i,  j;
	scanf("%d%d", &N, &M);
	memset(dep, 0, N * sizeof(int));
	while(M--)
	{
		scanf("%d%d", &a, &b);
		grafo[a].push_back(b);
		dep[b]++;
	}
	for(i=0;i<N;i++) if(dep[i] == 0) nodep.insert(i);
	if(!topsort(0)) printf("*\n");
	else for(i=0;i<N;i++) printf("%d\n", vsort[i]);
	return 0;
}
