#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int n, m, k;
char tab[111][111];
int adj[22][22], dist[111][111];
pii p[22];

void bfs(int x, int y) {
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) dist[i][j]=1e9;
	queue<pii> q;
	q.push(pii(x, y));
	dist[x][y]=0;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<8;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && tab[nx][ny] != '#' && dist[nx][ny] > dist[x][y]+1) {
				dist[nx][ny] = dist[x][y]+1;
				q.push(pii(nx, ny));
			}
		}
	}
}

int dp[22][(int)2e5];

int main() {
	while(scanf("%d%d%d", &n, &m, &k) && n) {
		for(int i=0;i<n;i++) scanf(" %s ", tab[i]);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(tab[i][j]=='C') p[k] = pii(i, j);
		int pos=0;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(tab[i][j]=='P') p[pos++] = pii(i, j);
		for(int i=0;i<=k;i++) {
			bfs(p[i].first, p[i].second);
			for(int j=0;j<=k;j++) adj[i][j] = dist[p[j].first][p[j].second];
		}
		for(int i=0;i<k;i++) for(int vis=0;vis<1<<k;vis++) dp[i][vis]=1e9; 
		for(int i=0;i<k;i++) dp[i][1<<i] = adj[k][i];
		for(int vis=1;vis<1<<k;vis++)
			for(int i=0;i<k;i++) if(vis & (1<<i))
				for(int j=0;j<k;j++) if(vis & (1<<j))
					if(i!=j)
						dp[i][vis] = min(dp[i][vis], dp[j][vis - (1<<i)] + adj[j][i]);
		int ans=1e9;
		for(int i=0;i<k;i++) ans = min(ans, dp[i][(1<<k)-1] + adj[i][k]);
		printf("%d\n", ans);
	}
	return 0;
}
