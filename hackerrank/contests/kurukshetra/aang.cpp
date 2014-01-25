#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

const int N=2e3+10;
char tab[N][N];
int n, m, vis[N][N];

void dfs(int x, int y) {
	vis[x][y]=1;
	for(int i=0;i<4;i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny]) continue;
		if(tab[nx][ny]=='B') dfs(nx,ny);
		else if(tab[nx][ny]=='G') {
			tab[nx][ny]='B';
			dfs(nx,ny);
		}
		else if(tab[nx][ny]=='R') {
			tab[nx][ny]='G';
		}
	}
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int x0, y0, x1, y1;
		cin>>n>>m>>x0>>y0>>x1>>y1;x0--;y0--;x1--;y1--;
		for(int i=0;i<n;i++) scanf("%s", tab[i]);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j]=0;
		dfs(x0, y0);
		cout << (vis[x1][y1] ? "Yes" : "No") << endl;
	}
	return 0;
}
