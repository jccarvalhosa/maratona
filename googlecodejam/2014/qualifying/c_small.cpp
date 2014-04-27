#include <iostream>
#include <cstdio>
using namespace std;

const int N=55;

int r, c, m;
char v[N][N];
int vis[N][N], adj[N][N];

int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

void dfs(int i, int j) {
	vis[i][j]=1;
	if(adj[i][j] == 0) {
		for(int k=0;k<8;k++) {
			int ii = i+dx[k];
			int jj = j+dy[k];
			if(ii>=0 && ii<r && jj>=0 && jj<c && !vis[ii][jj]) dfs(ii, jj);
		}
	}
}

int valid() {
	int ii=-1, jj=-1;
	for(int i=0;i<r;i++) for(int j=0;j<c;j++) vis[i][j]=0;
	for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
		if(v[i][j] == '*') continue;
		adj[i][j] = 0;
		for(int k=0;k<8;k++) {
			int ii = i+dx[k];
			int jj = j+dy[k];
			if(ii>=0 && ii<r && jj>=0 && jj<c && v[ii][jj] == '*') adj[i][j]++;
		}
		if(ii==-1 || adj[i][j]==0) ii=i, jj=j;
	}
	v[ii][jj]='c';
	dfs(ii, jj);
	for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(v[i][j]=='.' && !vis[i][j]) return 0;
	return 1;
}

int solve() {
	for(int mask=0;mask<1<<r*c;mask++) {
		if(__builtin_popcount(mask) != m) continue;
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
			if(mask & (1<<(i*c+j))) v[i][j]='*';
			else v[i][j]='.';
		}
		if(valid()) return 1;
	}
	return 0;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		printf("Case #%d:\n", t);
		cin>>r>>c>>m;
		if(!solve()) printf("Impossible\n");
		else {
			for(int i=0;i<r;i++) { for(int j=0;j<c;j++) printf("%c", v[i][j]); printf("\n"); }
		}
	}
	return 0;
}
