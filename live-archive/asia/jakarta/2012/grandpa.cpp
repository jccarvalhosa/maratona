#include <iostream>
#include <cstring>
using namespace std;

int ans, n, m, v[55][55];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void go(int x, int y) {
	int leaf=1;
	for(int i=0;i<4;i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
		if(v[nx][ny] < v[x][y]) {
			leaf=0;
			go(nx, ny);
		}
	}
	if(leaf) ans++;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
		cin>>n>>m;
		memset(v, 0, sizeof(v));
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>v[i][j];
		ans=0;
		for(int x=1;x<=n;x++) for(int y=1;y<=m;y++) {
			int ok=1;
			for(int i=0;i<4;i++) if(v[x + dx[i]][y + dy[i]] > v[x][y]) ok=0;
			if(ok) go(x, y);
		}
		cout << ans << endl;
	}
	return 0;
}
