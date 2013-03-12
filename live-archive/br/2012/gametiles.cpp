#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define MAX 51
typedef pair<int, int> pii;

int r, c, vis[MAX][MAX], cor[MAX*MAX], vis2[MAX*MAX], match[MAX*MAX];
char tab[MAX][MAX];
map<pii, int> m;
vector<int> adj[2500];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int dfsc(int a, int b, int x) {
	int i, na, nb, pos;
	vis[a][b] = 1;
	pos = m.size();
	m[pii(a, b)] = pos;
	adj[pos].clear();
	cor[pos] = x;
	for(i=0;i<4;i++) {
		na = a+dx[i];
		nb = b+dy[i];
		if(na >= 0 && nb >= 0 && na < r && nb < c && tab[na][nb] == '.') {
			if(!vis[na][nb]) dfsc(na, nb, x^1);
			adj[pos].push_back(m[pii(na, nb)]);
		}
	}
}

int dfsm(int v) {
	int i, u;
	if(vis2[v]) return 0;
	vis2[v]=1;
	for(i=0;i<adj[v].size();i++) {
		u = adj[v][i];
		if(match[u] == -1 || dfsm(match[u])) {
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	int i, j, k, tam, c0, c1;
	while(scanf("%d%d", &r, &c) != EOF) {
		for(i=0;i<r;i++) scanf("%s", tab[i]);
		memset(vis, 0, sizeof(vis));
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) if(tab[i][j] == '.' && !vis[i][j]) {
				m.clear();
				dfsc(i, j, 0);
				tam = m.size();
				c0 = c1 = 0;
				for(k=0;k<tam;k++) if(cor[k] == 1) {
					match[k]=-1;
					c1++;
				}
				c0 = tam - c1;
				if(c0 != c1) break;
				for(k=0;k<tam;k++) if(cor[k] == 0) {
					memset(vis2, 0, sizeof(vis2));
					if(!dfsm(k)) break;
				}
				if(k != tam) break;
			}
			if(j != c) break;
		}
		if(i == r) printf("2\n");
		else printf("1\n");
	}
	return 0;
}
