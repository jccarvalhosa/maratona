#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ull;

int ans, n, m, sum;
int v[66];
int check[66], nstep[66], nx[66], ny[66];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int mod(int x) { return x>0 ? x : -x; }

int vis[10][10];

void dfs(int x, int y) {
	vis[x][y]=1;
	for(int i=0;i<4;i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) dfs(nx, ny);
	}
}

void go(int x, int y, int step, ull mask) {
	int id = x*m+y;
	if(mask & (1ull<<id)) return;
	if(check[id] != -1 && check[id] != step) return;
	if(v[step] != -1 && v[step] != id) return;
	if(mod(x-nx[step]) + mod(y - ny[step]) > nstep[step] - step) return;
	
	if(step == sum) ans++;
	else {
		step++;
		mask |= (1ull<<id);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j] = (mask&(1ull<<(i*m+j)))!=0;
		int nc=0;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!vis[i][j]) {
			dfs(i, j);
			nc++;
			if(nc==2) return;
		}
		for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) go(nx, ny, step, mask);
		}
	}
}

int main() {
	int t=1;
	while(cin>>n>>m && n) {
		sum = n*m;
		for(int i=0;i<sum;i++) check[i] = -1;
		for(int i=1;i<=sum;i++) v[i] = -1;
		check[0] = 1;
		v[1] = 0;
		check[1] = sum;
		v[sum] = 1;
		for(int i=1;i<=3;i++) {
			int x, y, pos = sum*i/4;
			cin>>x>>y;
			check[x*m+y] = pos;
			v[pos] = x*m+y;
		}
		for(int i=sum;i>=1;i--) {
			if(v[i] != -1) {
				nx[i] = v[i]/m;
				ny[i] = v[i]%m;
				nstep[i] = i;
			}
			else {
				nx[i] = nx[i+1];
				ny[i] = ny[i+1];
				nstep[i] = nstep[i+1];
			}
		}
		ans=0;
		go(0, 0, 1, 0);
		printf("Case %d: %d\n", t++, ans);
	}
	return 0;
}
