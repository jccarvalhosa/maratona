#include <cstdio>
#include <algorithm>
using namespace std;

int dp[22][22][2222];
int x[1111], y[1111], t[1111];


int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
	int n, m, k;
	while(scanf("%d%d%d", &n, &m, &k) && n) {
		int oldt=0;
		for(int i=0;i<k;i++) {
			scanf("%d%d%d", &x[i], &y[i], &t[i]);
		}
		int x0, y0;
		scanf("%d%d", &x0, &y0);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j][0] = -1e9;
		dp[x0][y0][0]=0;
		for(int pos=0;pos<k;pos++) {
			while(oldt<t[pos]) {
				for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
					dp[i][j][oldt+1] = dp[i][j][oldt];
					for(int jj=0;jj<8;jj++) {
						int nx = i+dx[jj];
						int ny = j+dy[jj];
						if(nx>=1 && nx<=n && ny>=1 && ny<=m) {
							dp[i][j][oldt+1] = max(dp[i][j][oldt+1], dp[nx][ny][oldt]);
						}
					}
				}
				oldt++;
			}
			for(int j=0;j<8;j++) {
				int nx = x[pos]+dx[j];
				int ny = y[pos]+dy[j];
				dp[x[pos]][y[pos]][t[pos]] = max(dp[x[pos]][y[pos]][t[pos]], 1+dp[x[pos]][y[pos]][t[pos]-1]);
				if(nx>=1 && nx<=n && ny>=1 && ny<=m) {
					dp[x[pos]][y[pos]][t[pos]] = max(dp[x[pos]][y[pos]][t[pos]], 1+dp[nx][ny][t[pos]-1]);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans = max(ans, dp[i][j][oldt]);
		printf("%d\n", ans);
	}
	return 0;
}
