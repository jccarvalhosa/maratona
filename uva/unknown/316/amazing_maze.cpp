#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#define INF 1000000000
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

int M, N, c[101][101], ord[10], vis[101][101][4], d[101][101][4], dist[10][4][10][4], dp[10][4];
pii pos[10];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

pair<pii, pii> q[40000];

void bfs(int x, int y, int k) {
	int n, nx, ny, nk, i, j, jj, ini=0, fim=1;
	for(i=1;i<=M;i++) for(j=1;j<=N;j++) for(jj=0;jj<4;jj++) vis[i][j][jj]=0;
	q[0] = mp(mp(x, y), mp(k, 0));
	vis[x][y][k]=1;
	while(ini != fim) {
		x = q[ini].first.first;
		y = q[ini].first.second;
		k = q[ini].second.first;
		n = q[ini++].second.second;
		d[x][y][k]=n;
		i = (c[x][y] + k)%4;
		nk=(k+1)%4;
		nx=x+dx[i];
		ny=y+dy[i];
		if(!vis[x][y][nk]) {
			q[fim++] = mp(mp(x, y), mp(nk, n+1));
			vis[x][y][nk]=1;
		}
		if(nx>0 && nx<=M && ny>0 && ny<=N && !vis[nx][ny][nk]) {
			q[fim++] = mp(mp(nx, ny), mp(nk, n+1));
			vis[nx][ny][nk]=1;
		}
	}
}

int main() {
	int K, i, j, k, ni, nj, nk, a, b;
	string s;
	while(cin>>M>>N && M) {
		for(i=0;i<M;i++) {
			cin>>s;
			for(j=0;j<N;j++) {
				if(s[j]=='N') c[i+1][j+1]=0;
				if(s[j]=='E') c[i+1][j+1]=1;
				if(s[j]=='S') c[i+1][j+1]=2;
				if(s[j]=='W') c[i+1][j+1]=3;
			}
		}
		cin>>K;
		K+=2;
		for(i=0;i<K;i++) ord[i]=i;
		pos[0] = pii(1, 1);
		pos[K-1] = pii(M, N);
		for(i=1;i<K-1;i++) cin>>pos[i].first>>pos[i].second;
		for(a=0;a<K-1;a++) for(i=0;i<4;i++) {
			if(!a && i) continue;
			bfs(pos[a].first, pos[a].second, i);
			for(b=0;b<K;b++) for(j=0;j<4;j++) dist[a][i][b][j] = d[pos[b].first][pos[b].second][j];
		}
		int ans=INF;
		do {
			for(i=0;i<K;i++) for(j=0;j<4;j++) dp[i][j]=INF;
			for(j=0;j<4;j++) dp[1][j] = dist[0][0][ord[1]][j];
			for(i=2;i<K;i++) for(j=0;j<4;j++) for(k=0;k<4;k++) dp[i][j] = min(dp[i][j], dp[i-1][k] + dist[ord[i-1]][k][ord[i]][j]);
			for(j=0;j<4;j++) ans=min(ans, dp[K-1][j]);
		} while(next_permutation(ord+1, ord+K-1));
		cout << ans << endl;
	}
	return 0;
}
