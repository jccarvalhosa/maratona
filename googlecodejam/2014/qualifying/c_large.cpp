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
	dfs(ii, jj);
	for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(v[i][j]=='.' && !vis[i][j]) return 0;
	return 1;
}


int solve() {
	int x = r*c-m;
	for(int i=0;i<r;i++) for(int j=0;j<c;j++) v[i][j]='*';
	if(x==1) {
		v[0][0]='c';
		return 1;
	}
	if(r==1) {
		for(int i=0;i<x;i++) v[0][i]='.';
		v[0][0]='c';
		return 1;
	}
	if(c==1) {
		for(int i=0;i<x;i++) v[i][0]='.';
		v[0][0]='c';
		return 1;
	}
	for(int rr=2;rr<=r;rr++) for(int cc=2;cc<=c;cc++) {
		m = rr*cc - x;
		if(m < 0) continue;
		if(m >= min(rr, cc)) continue;
		if(rr==2 || cc==2) {
			if(m == 0) {
				for(int i=0;i<rr;i++) for(int j=0;j<cc;j++) v[i][j]='.';
				v[0][0]='c';
				return 1;
			}
		}
		else if(m < max(rr, cc)-1) {
			for(int i=0;i<rr;i++) for(int j=0;j<cc;j++) v[i][j]='.';
			v[0][0]='c';
			if(m < rr-1) { for(int ii=0;ii<m;ii++) v[rr-1-ii][cc-1]='*'; }
			else for(int jj=0;jj<m;jj++) v[rr-1][cc-1-jj]='*';
			return 1;
		}
		else {
			if(rr==3) continue;
			for(int i=0;i<rr;i++) for(int j=0;j<cc;j++) v[i][j]='.';
			v[0][0]='c';
			m++;
			for(int i=0;i<m/2;i++) v[rr-1-i][cc-1]='*';
			for(int j=0;j<m-m/2;j++) v[rr-1][cc-1-j]='*';
			return 1;
		}
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
			if(!valid()) printf("Wrong Answer!\n");
			else for(int i=0;i<r;i++) { for(int j=0;j<c;j++) printf("%c", v[i][j]); printf("\n"); }
		}
	}
	return 0;
}
