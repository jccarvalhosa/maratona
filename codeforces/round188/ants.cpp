#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define S 500

int g[1000][1000];
int mod(int a) { return a>0?a:-a;}

int main() {
	int x, y, n, t, f, k, v, d;
	cin>>n;
	g[S][S]=n;
	d=0;
	while(1) {
		f=1;
		for(x=S-d;x<=S+d;x++) for(y=S-d;y<=S+d;y++) {
			if(g[x][y] >= 4) {
				if(x==S-d || x==S+d || y==S-d || y==S+d) d++;
				v = g[x][y]/4;
				g[x][y] %= 4;
				g[x+1][y] += v;
				g[x-1][y] += v;
				g[x][y+1] += v;
				g[x][y-1] += v;
				f=0;
			}
		}
		if(f) break;
	}
	cin>>t;
	while(t--) {
		cin>>x>>y;
		if(mod(x)<S&&mod(y)<S) cout << g[S+x][S+y]<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
