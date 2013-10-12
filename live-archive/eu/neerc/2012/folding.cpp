#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int N = 15;
const int n = 'N'-'A'+1 + 'm'-'a'+1;
int px[n], py[n], t[n], d[n];
int vis[3][3][3];

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int ok(int i) { return i>=0 && i<3; }

int go(int x, int y, int z, int p, int d) {
	if(p==n) return 1;
	if(vis[x][y][z] != -1) return 0;
	vis[x][y][z] = p;
	for(int dd=0;dd<6;dd++) if((t[p]==0 && dd!=d) || (t[p]==1 && dd==d)) {
		int nx=x+dx[dd], ny=y+dy[dd], nz=z+dz[dd];
		if(ok(nx) && ok(ny) && ok(nz) && go(nx, ny, nz, p+1, dd)) return 1;
	}
	vis[x][y][z] = -1;
	return 0;
}

int main() {
	string tab[N];
	while(cin>>tab[0] && !cin.eof()) {
		for(int i=1;i<N;i++) cin>>tab[i];
		for(int i=0;i<n;i++) {
			char c='a'+i/2;
			if(i%2==0) c='A'+i/2;
			for(int x=0;x<N;x++) for(int y=0;y<N;y++) if(tab[x][y] == c) px[i]=x, py[i]=y;
		}
		for(int i=0;i<n-1;i++) for(int dd=0;dd<4;dd++) if(px[i]+dx[dd] == px[i+1] && py[i]+dy[dd] == py[i+1]) d[i]=dd;
		for(int i=1;i<n-1;i++) t[i] = (d[i-1]==d[i]);
		memset(vis, -1, sizeof(vis));
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int k=0;k<3;k++) for(int d=0;d<6;d++) if(go(i, j, k, 0, d)) goto print;
		print:
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(j>0) cout<<" ";
				for(int k=0;k<3;k++) {
					int v = vis[i][j][k];
					char c='a'+v/2;
					if(v%2==0) c='A'+v/2;
					cout<<c;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
