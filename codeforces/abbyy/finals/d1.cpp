#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#define M 33
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int dx[] = {0, 1, 0, -1, 0};
int dy[] = {0, 0, -1, 0, 1};
int G[M][M], vis[M][M], ord[M][M];

int main() {
	int n, b;
	cin>>n>>b;
	while(n--) {
		int i, xi, xf, yi, yf;
		cin>>xi>>yi>>xf>>yf;
		if(xi==xf) {
			if(yi>yf) i=2;
			else i=4;
		}
		else {
			if(xi>xf) i=3;
			else i=1;
		}
		G[xf][yf]=i;
		while(xi!=xf || yi!=yf) {
			G[xi][yi]=i;
			xi+=dx[i];
			yi+=dy[i];
		}
	}
	int q, x, y;
	char c;
	ll t;
	map<char, int> m;
	m['L'] = 3; m['R'] = 1; m['U'] = 4; m['D'] = 2;
	cin>>q;
	vector<pii> vp(M*M);
	for(;q!=0;q--) {
		cin>>x>>y>>c>>t;
		int vx = dx[m[c]];
		int vy = dy[m[c]];
		int i=0;
		while(x>=0 && x<=b && y>=0 && y<=b && t!=0) {
			if(G[x][y]) {
				vx = dx[G[x][y]];
				vy = dy[G[x][y]];
			}
			if(vis[x][y]==q && G[x][y]) {
				int a = ord[x][y];
				int pos = t%(i-a);
				x = vp[a+pos].first;
				y = vp[a+pos].second;
				break;
			}
			vis[x][y]=q;
			ord[x][y]=i;
			vp[i++] = pii(x, y);
			x += vx;
			y += vy;
			t--;
		}
		if(x<0) x=0;
		if(x>b) x=b;
		if(y<0) y=0;
		if(y>b) y=b;
		printf("%d %d\n", x, y);
	}
	return 0;
}
