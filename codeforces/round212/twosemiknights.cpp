#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string tab[10];
int vis[10][10][10][10];

int dx[] = {2, 2, -2, -2};
int dy[] = {2, -2, 2, -2};

void go(int x1, int y1, int x2, int y2) {
	if(x1<0 || x1>=8 || y1<0 || y1>=8) return;
	if(x2<0 || x2>=8 || y2<0 || y2>=8) return;
	if(vis[x1][y1][x2][y2]) return;
	vis[x1][y1][x2][y2] = 1;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++) go(x1+dx[i], y1+dy[i], x2+dx[j], y2+dy[j]);
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		for(int i=0;i<8;i++) cin>>tab[i];
		int n=0;
		memset(vis, 0, sizeof(vis));
		int x[2], y[2];
		for(int i=0;i<8;i++) for(int j=0;j<8;j++) if(tab[i][j]=='K') {x[n]=i; y[n]=j; n++; }
		if(n==2) go(x[0], y[0], x[1], y[1]);
		else go(x[0], y[0], x[0], y[0]);
		int valid=0;
		for(int i=0;i<8;i++) for(int j=0;j<8;j++) if(vis[i][j][i][j] && tab[i][j]!='#') {valid=1; break; }
		if(valid) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
