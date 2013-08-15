#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
using namespace std;

string heroi[100], civil[100];
map<string, int> idh, idc;
string s;
int N, adj[100][100], h[100], c[100], super[100], aux[100];
int vis[100], grafo[100][100], grau[100];

int dfs(int v) {
	int i, u;
	if(vis[v]) return 0;
	vis[v]=1;
	for(i=0;i<grau[v];i++) {
		u = grafo[v][i];
		if(super[u] == -1 || dfs(super[u])) {
			super[u] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	int E, M, H, C, i, j, u, v, a, b;
	scanf("%d%d", &N, &E);
	for(i=0;i<N;i++) {
		cin >> heroi[i];
		idh[heroi[i]]=i;
	}
	for(i=0;i<N;i++) {
		cin >> civil[i];
		idc[civil[i]]=i;
	}
	for(i=0;i<N;i++) for(j=0;j<N;j++) adj[i][j]=1;
	while(E--) {
		scanf("%d", &M);
		H=C=0;
		while(M--) {
			cin >> s;
			if(idh.count(s)) h[H++] = idh[s];
			else c[C++] = idc[s];
		}
		for(i=0;i<H;i++) for(j=0;j<C;j++) adj[h[i]][c[j]]=0;
	}
	for(i=0;i<N;i++) {
		grau[i]=0;
		super[i]=-1;
		for(j=0;j<N;j++) if(adj[i][j]) grafo[i][grau[i]++] = j;
	}
	for(i=0;i<N;i++) {
		memset(vis, 0, sizeof(vis));
		if(!dfs(i)) break;
	}
	if(i != N) printf("IMPOSSIVEL\n");
	else {
		memcpy(aux, super, sizeof(aux));
		for(v=0;v<N;v++) {
			cout << heroi[v] << ":";
			for(u=0;u<N;u++) if(super[u] == v) break;
			for(i=0;i<grau[v];i++) {
				memset(vis, 0, sizeof(vis));
				b = grafo[v][i];
				a = super[b];
				super[u] = -1;
				super[b] = v;
				vis[v] = 1;
				if(a == v || dfs(a)) cout << " " << civil[b];
				memcpy(super, aux, sizeof(aux));
			}
			cout << endl;
		}
	}
	return 0;
}
