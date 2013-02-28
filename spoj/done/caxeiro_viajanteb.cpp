#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000
typedef pair<int, bool> pib;

vector<int> adj[300];
int n, vis[300], lista[300];

pib dfs(int v) {
	int i, u, num=0, find=0;
	vis[v] = 1;
	if(lista[v]) find=1;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i];
		pib p = pib(0, 0);
		if(!vis[u]) p = dfs(u);
		if(p.second) {
			num += 2+p.first;
			find=1;
		}
	}
	return pib(num, find);
}

int main() {
	int v, i, a, b, t=1;
	while(scanf("%d%d", &n, &v) && n) {
		for(i=0;i<n;i++) adj[i].clear();
		for(i=0;i<n-1;i++) {
			scanf("%d%d", &a, &b);
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		for(i=0;i<n;i++) vis[i] = lista[i] = 0;
		for(i=0;i<v;i++) {
			scanf("%d", &a);
			lista[a-1]=1;
		}
		printf("Teste %d\n", t++);
		printf("%d\n\n", dfs(0).first);
	}
	return 0;
}
