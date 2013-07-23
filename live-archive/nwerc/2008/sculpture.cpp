#include <iostream>
#include <cstring>
using namespace std;

int id[1111][3];
int vis[111][111][111];
int v[1111][3];
int p0[1111][3], p[1111][3];
int m[3];

int dx[] = {1, 0, 0, -1, 0, 0};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {0, 0, 1, 0, 0, -1};

int q[7777777][3];

void bfs() {
	int i=0, f=1;
	int x, y, z, nx, ny, nz;
	q[0][0] = q[0][1] = q[0][2] = 0;
	vis[0][0][0]=1;
	while(i!=f) {
		x = q[i][0];
		y = q[i][1];
		z = q[i][2];
		i++;
		for(int k=0;k<6;k++) {
			nx = x+dx[k];
			ny = y+dy[k];
			nz = z+dz[k];
			if(nx<0||nx>=m[0]||ny<0||ny>=m[1]||nz<0||nz>=m[2]) continue;
			if(!vis[nx][ny][nz]) {
				vis[nx][ny][nz]=1;
				q[f][0]=nx;
				q[f][1]=ny;
				q[f][2]=nz;
				f++;
			}
		}
	}
}

void compress(int n) {
	int vis[1111][3];
	memset(vis, 0, sizeof(vis));
	for(int i=0;i<n;i++) {
		int c0[3], c[3];
		for(int j=0;j<3;j++) cin>>c0[j];
		for(int j=0;j<3;j++) cin>>c[j];
		for(int j=0;j<3;j++) {
			p0[i][j] = c0[j];
			p[i][j] = c0[j] + c[j];
			vis[ p0[i][j] ][j]=1;
			vis[ p[i][j] ][j]=1;
		}
	}
	for(int i=0;i<3;i++) {
		m[i]=0;
		vis[0][i]=1;
		vis[1000][i]=1;
		for(int j=0;j<=1000;j++) if(vis[j][i]) {
			id[j][i] = m[i];
			v[m[i]][i] = j;
			m[i]++;
		}
	}
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n; 
		cin>>n;
		compress(n);
		
		memset(vis, 0, sizeof(vis));
		for(int i=0;i<n;i++) 
			for(int x=id[p0[i][0]][0];x<id[p[i][0]][0];x++) 
				for(int y=id[p0[i][1]][1];y<id[p[i][1]][1];y++) 
					for(int z=id[p0[i][2]][2];z<id[p[i][2]][2];z++) 
						vis[x][y][z]=2;
		
		bfs();

		int a=0;
		int vol=0;
		for(int x=0;x<m[0];x++) 
			for(int y=0;y<m[1];y++) 
				for(int z=0;z<m[2];z++) {
					if(vis[x][y][z]!= 1) vol += (v[x+1][0]-v[x][0])*(v[y+1][1]-v[y][1])*(v[z+1][2]-v[z][2]);
					if(vis[x][y][z]==2) {
						for(int i=0;i<6;i++) {
							int nx = x+dx[i];
							int ny = y+dy[i];
							int nz = z+dz[i];
							if(vis[nx][ny][nz]==1) {
								int na = 1;
								if(!dx[i]) na *= (v[x+1][0]-v[x][0]);
								if(!dy[i]) na *= (v[y+1][1]-v[y][1]);
								if(!dz[i]) na *= (v[z+1][2]-v[z][2]);
								a += na;
							}
						}
					}
				}

		cout << a << " " << vol << endl;
	}
	return 0;
}
