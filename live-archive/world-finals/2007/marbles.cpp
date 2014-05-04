#include <bits/stdc++.h>
using namespace std;
typedef vector<char> vc;
typedef vector<vc> vv;

map<vv, int> vis;

int n;
const int INF=1e9;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int adj[5][5][5];

void print(vv tab) { for(int i=0;i<n;i++) { for(int j=0;j<n;j++) printf("%c", tab[i][j]); printf("\n"); } }

void solve(vv v) {
	queue<vv> q;
	q.push(v);
	vis.clear();
	vis[v] = 0;
	while(!q.empty()) {
		v = q.front();
		q.pop();
		int step = vis[v];
		for(int i=0;i<4;i++) {
			vv u = v;
			int valid=1;
			if(dx[i] == -1) {
				for(int y=0;y<n;y++) {
					int stop=-1;
					for(int x=0;x<n;x++) if(islower(u[x][y])) {
						int xx=x;
						while(1) {
							if(!adj[xx][y][i]) {
								stop = xx;
								break;
							}
							if(isupper(u[xx-1][y])) {
								if(u[xx-1][y] - 'A' != u[xx][y] - 'a') valid=0;
								u[xx][y] = '.';
								u[xx-1][y] = '.';
								break;
							}
							if(stop == xx-1) {
								stop=xx;
								break;
							}
							else {
								swap(u[xx][y], u[xx-1][y]);
								xx--;
							}
						}
					}
				}
			}
			if(dx[i] == 1) {
				for(int y=0;y<n;y++) {
					int stop=n;
					for(int x=n-1;x>=0;x--) if(islower(u[x][y])) {
						int xx=x;
						while(1) {
							if(!adj[xx][y][i]) {
								stop = xx;
								break;
							}
							if(isupper(u[xx+1][y])) {
								if(u[xx+1][y] - 'A' != u[xx][y] - 'a') valid=0;
								u[xx][y] = '.';
								u[xx+1][y] = '.';
								break;
							}
							if(stop == xx+1) {
								stop=xx;
								break;
							}
							else {
								swap(u[xx][y], u[xx+1][y]);
								xx++;
							}
						}
					}
				}
			}
			if(dy[i] == -1) {
				for(int x=0;x<n;x++) {
					int stop=-1;
					for(int y=0;y<n;y++) if(islower(u[x][y])) {
						int yy=y;
						while(1) {
							if(!adj[x][yy][i]) {
								stop = yy;
								break;
							}
							if(isupper(u[x][yy-1])) {
								if(u[x][yy-1] - 'A' != u[x][yy] - 'a') valid=0;
								u[x][yy] = '.';
								u[x][yy-1] = '.';
								break;
							}
							if(stop == yy-1) {
								stop=yy;
								break;
							}
							else {
								swap(u[x][yy], u[x][yy-1]);
								yy--;
							}
						}
					}
				}
			}
			if(dy[i] == 1) {
				for(int x=0;x<n;x++) {
					int stop=n;
					for(int y=n-1;y>=0;y--) if(islower(u[x][y])) {
						int yy=y;
						while(1) {
							if(!adj[x][yy][i]) {
								stop = yy;
								break;
							}
							if(isupper(u[x][yy+1])) {
								if(u[x][yy+1] - 'A' != u[x][yy] - 'a') valid=0;
								u[x][yy] = '.';
								u[x][yy+1] = '.';
								break;
							}
							if(stop == yy+1) {
								stop=yy;
								break;
							}
							else {
								swap(u[x][yy], u[x][yy+1]);
								yy++;
							}
						}
					}
				}
			}
			if(valid && !vis.count(u)) {
				vis[u] = step+1;
				q.push(u);
			}
		}
	}
}


int main() {
	int m, w, T=1;
	while(cin>>n>>m>>w && n) {
		vv tab(n);
		for(int i=0;i<n;i++) {
			tab[i].resize(n);
			for(int j=0;j<n;j++) tab[i][j]='.';
		}
		vv dest = tab;
		for(int i=0;i<m;i++) {
			int x, y;
			cin>>x>>y;
			tab[x][y] = 'a'+i;
		}
		for(int i=0;i<m;i++) {
			int x, y;
			cin>>x>>y;
			tab[x][y] = 'A'+i;
		}
		for(int x=0;x<n;x++) for(int y=0;y<n;y++) for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			adj[x][y][i] = nx >= 0 && nx < n && ny >= 0 && ny < n;
		}
		for(int i=0;i<w;i++) {
			int x, y, xx, yy;
			cin>>x>>y>>xx>>yy;
			for(int i=0;i<4;i++) {
				if(x + dx[i] == xx && y + dy[i] == yy) adj[x][y][i] = 0;
				if(xx + dx[i] == x && yy + dy[i] == y) adj[xx][yy][i] = 0;
			}
		}
		solve(tab);
		printf("Case %d: ", T++);
		if(!vis.count(dest)) printf("impossible\n");
		else printf("%d moves\n", vis[dest]);
		printf("\n");
	}
	return 0;
}
