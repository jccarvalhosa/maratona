#include <cstdio>
#include <cstring>

using namespace std;

char s[22][22], g[7][22][22], vis[22][22];
int n;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, -1, 0, 1};

void go(int u, int v, int id, char c, char d) {
	int i, nu, nv;
	vis[u][v]=1;
	g[id][u][v]=d;
	for(i=0; i<4; i++) {
		nu=u+dx[i];
		nv=v+dy[i];
		if(nu>=0 && nu<n && nv>=0 && nv<n && !vis[nu][nv] && g[id][nu][nv]==c) go(nu, nv, id, c, d);
	}
}

int dfs(int u, int v, int id, char c) {
	int ret=1, nu, nv, i;
	vis[u][v]=1;
	for(i=0; i<4; i++) {
		nu=u+dx[i];
		nv=v+dy[i];
		if(nu>=0 && nu<n && nv>=0 && nv<n && !vis[nu][nv] && g[id][nu][nv]==c) ret+=dfs(nu, nv, id, c);
	}
	return ret;
}

int main() {
	int i, j, k, t, cont, ret, id, ans, num[7];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(num, 0, sizeof(num));
		for(i=0; i<n; i++) scanf("%s", s[i]);
		cont=0;
		for(i=0; i<n; i++) for(j=0; j<n; j++) if(s[i][j]==s[0][0]) cont++;
		if(cont==n*n) {
			printf("0\n0");
			for(i=1; i<6; i++) printf(" 0");
			printf("\n");
			continue;
		}
		for(i=1; i<7; i++) for(j=0; j<n; j++) for(k=0; k<n; k++) g[i][j][k]=s[j][k];
		cont=ans=0;
		while(cont!=n*n) {
			for(i=1; i<7; i++) {
				memset(vis, 0, sizeof(vis));
				go(0, 0, i, g[i][0][0], '0'+i);
			}
			for(i=1; i<7; i++) {
				memset(vis, 0, sizeof(vis));
				ret=dfs(0, 0, i, g[i][0][0]);
				if(ret>cont) cont=ret, id=i;
			}
			for(i=0; i<n; i++) for(j=0; j<n; j++) s[i][j]=g[id][i][j];
			for(i=1; i<7; i++) for(j=0; j<n; j++) for(k=0; k<n; k++) g[i][j][k]=s[j][k];
			num[id]++;
			ans++;
		}
		printf("%d\n", ans);
		printf("%d", num[1]);
		for(i=2; i<7; i++) printf(" %d", num[i]);
		printf("\n");
	}
	return 0;
}
