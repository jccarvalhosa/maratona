#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
using namespace std;

const int N=555;
int n, m, c, D, h[N][N], w[N][N], vis[N][N], comp[N][N];

int mod(int a) {return a>0?a:-a;}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
	vis[x][y]=1;
	comp[x][y]=c;
	for(int i=0;i<4;i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && mod(h[x][y] - h[nx][ny]) <= D) {
			dfs(nx, ny);
		}
	}
}

int valid(int d) {
	D=d;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j]=0;
	c=0;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!vis[i][j]) {
		dfs(i, j);
		c++;
	}
	set<int> s;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(w[i][j]) {
		s.insert(comp[i][j]);
		if(s.size() > 1) return 0;
	}
	return 1;
}

int main() {
	ifstream in("ccski.in");
	ofstream out("ccski.out");
	in>>n>>m;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) in>>h[i][j];
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) in>>w[i][j];
	if(valid(0)) out<<0<<endl;
	else {
		int l=0, r=(int)1e9;
		while(l<r-1) {
			int mid = (r+l)/2;
			if(valid(mid)) r=mid;
			else l=mid;
		}
		out<<r<<endl;
	}
	return 0;
}
