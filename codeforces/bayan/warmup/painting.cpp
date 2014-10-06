#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
using namespace std;
typedef pair<int, int> pii;

int n, m;
const int N=1e3+7;
char tab[N][N];
int dp[N][N], md[N][N], mr[N][N];

int sum(int x, int y, int nx, int ny) {
	return dp[nx][ny] - dp[x-1][ny] - dp[nx][y-1] + dp[x-1][y-1];	
}

int go(int x, int y, int dx, int dy, int cnt) {
	if(x > n || y > m) return -1;
	if(sum(x, y, x+max(dx, 1)-1, y+max(dy, 1)-1) != max(dx, 1)*max(dy, 1)) return -1;
	if(cnt + max(dx, 1)*max(dy, 1) == dp[n][m]) {
		return max(dx, 1) * max(dy, 1);
	}
	else {
		int ans1 = -1, ans2 = -1;
		if(dx == 0 || dx == md[x][y]) ans1 = go(x, y+1, md[x][y], dy, cnt+md[x][y]);
		if(dy == 0 || dy == mr[x][y]) ans2 = go(x+1, y, dx, mr[x][y], cnt+mr[x][y]);
		if(ans1 == -1) return ans2;
		if(ans2 == -1) return ans1;
		return min(ans1, ans2);
	}
}

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%s", tab[i]+1);
	for(int i=1;i<=n;i++) {
		for(int j=m;j>=1;j--) if(tab[i][j] == 'X') {
			if(j+1 <= m && tab[i][j+1] == 'X') mr[i][j] = 1+mr[i][j+1];
			else mr[i][j] = 1;
		}
	}
	for(int j=1;j<=m;j++) {
		for(int i=n;i>=1;i--) if(tab[i][j] == 'X') {
			if(i+1 <= n && tab[i+1][j] == 'X') md[i][j] = 1+md[i+1][j];
			else md[i][j] = 1;
		}
	}
	for(int i=1;i<=n;i++) {
		int total=0;
		for(int j=1;j<=m;j++) {
			if(tab[i][j] == 'X') total++;
			dp[i][j] = dp[i-1][j] + total;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(tab[i][j] == 'X') {
		int ans = go(i, j, 0, 0, 0);
		printf("%d\n", ans);
		return 0;
	}
}
