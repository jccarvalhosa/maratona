#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define MAXL 600
#define MAXC 601

int N, C, L;
int G[MAXC][MAXL][2], vis[MAXC][MAXL];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pii q[MAXC*MAXL];

void bfs(int a, int b) {
	int i, na, nb, ca, cb, ini=0, fim=0;
	q[fim++] = pii(a, b);
	vis[a][b]=1;
	while(ini!=fim) {
		a = q[ini].first;
		b = q[ini++].second;
		for(i=0;i<4;i++) {
			na = a+dx[i];
			nb = b+dy[i];
			if(na<0 || nb<0 || na>=C || nb>=L || vis[na][nb]) continue;
			if(i<2) ca=na, cb=nb;
			else ca=a, cb=b;
			if(!G[ca][cb][i%2]) {
				q[fim++] = pii(na, nb);
				vis[na][nb]=1;
			}
		}
	}
}

int main() {
	char s[301];
	int i, j, k, mx, my;
	while(scanf("%d", &N)!=EOF) {
		L = 2*N;
		C = 2*N+1;
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		for(i=1;i<=2*N-1;i++) {
			scanf("%s", s);
			for(j=1;j<=N;j++) {
				my = i;
				if(i % 2 == 0) mx=2*j;
				else mx=2*j-1;
				if(s[j-1]=='H') { for(k=mx-1;k<mx+1;k++) G[k][my][1]=1; }
				if(s[j-1]=='V') { for(k=my-1;k<my+1;k++) G[mx][k][0]=1; }
			}
		}
		int cc=0;
		for(i=0;i<C;i++) for(j=0;j<L;j++) if(!vis[i][j]) {
			cc++;
			bfs(i, j);
		}
		printf("%d\n", cc-1);
	}
	return 0;
}
