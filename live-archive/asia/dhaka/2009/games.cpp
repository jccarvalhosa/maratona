#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef vector<string> vs;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

vs play(vs v, int x, int y) {
	int q[16][2];
	int vis[4][4];
	memset(vis, 0, sizeof(vis));
	int i=0, f=1;
	q[0][0] = x;
	q[0][1] = y;
	vis[x][y]=1;
	while(i!=f) {
		x=q[i][0];
		y=q[i][1];
		i++;
		for(int k=0;k<4;k++) {
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0 && nx<4 && ny>=0 && ny<4 && !vis[nx][ny] && v[nx][ny]==v[x][y]) {
				q[f][0]=nx;
				q[f][1]=ny;
				vis[nx][ny]=1;
				f++;
			}
		}
		v[x][y]=' ';
	}
	for(int j=0;j<4;j++) {
		for(int i=3;i>=0;i--) if(v[i][j]==' ') {
			int x;
			for(x=i-1;x>=0;x--) if(v[x][j]!=' ') break;
			if(x>=0) swap(v[i][j], v[x][j]);
		}
	}
	return v;
}

map<vs, int> vis;

int go(vs v) {
	if(vis.count(v)) return vis[v];
	int x=0;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(v[i][j]!=' ') {
		vs u = play(v, i, j);
		int y = go(u);
		y = -y;
		if(y==0) x=1;
		else if(y>0) {
			if(x>0) x = min(x, y+1);
			else x=y+1;
		}
		else if(x<=0) x = min(x, y-1);
	}
	return vis[v]=x;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		string s;
		vs v;
		for(int i=0;i<4;i++) {
			cin>>s;
			v.push_back(s);
		}
		int x=go(v);
		cout<<"Case "<<t<<": ";
		if(x>0) cout<<"win "<<x<<endl;
		if(x<0) cout<<"loss "<<-x<<endl;
	}
	return 0;
}
