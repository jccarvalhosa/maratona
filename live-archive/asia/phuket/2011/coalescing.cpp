#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int abs(int a) { return a>0?a:-a; }

string tab[20];
int nc, ans, qx, qy;
struct cont {
	int x, y, a, b;
	cont() {}
	cont(int x, int y, int a, int b) : x(x), y(y), a(a), b(b) {}
};

cont c[5];
int vis[5][5];

void go(int p, int v) {
	if(p==nc) ans = min(ans, v);
	else {
		for(int i=0;i<5;i++) for(int j=0;j<5;j++) {
			if(i+c[p].a > 5) continue;
			if(j+c[p].b > 5) continue;
			int valid=1;
			for(int a=0;a<c[p].a;a++) for(int b=0;b<c[p].b;b++) if(vis[i+a][j+b]) valid=0;
			if(!valid) continue;
			for(int a=0;a<c[p].a;a++) for(int b=0;b<c[p].b;b++) vis[i+a][j+b]=1;
			int delta = abs(c[p].x - qx - i) + abs(c[p].y - qy - j);
			go(p+1, v+delta);
			for(int a=0;a<c[p].a;a++) for(int b=0;b<c[p].b;b++) vis[i+a][j+b]=0;
		}
	}
}

bool cmp(const cont &a, const cont &b) { return a.a*a.b > b.a*b.b; }

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		for(int i=0;i<20;i++) cin>>tab[i];
		ans=1<<30;
		nc=0;
		for(int i=0;i<20;i++) for(int j=0;j<20;j++) if(tab[i][j] == 'x') {
			if(i!=0 && tab[i-1][j]=='x') continue;
			if(j!=0 && tab[i][j-1]=='x') continue;
			int a=1;
			int b=1;
			while(i+a != 20 && tab[i+a][j] == 'x') a++;
			while(j+b != 20 && tab[i][j+b] == 'x') b++;
			c[nc++] = cont(i, j, a, b);
		}
		sort(c, c+nc, cmp);
		for(qx=0;qx<=16;qx++) for(qy=0;qy<=16;qy++) {
			memset(vis, 0, sizeof(vis));
			go(0, 0);
		}
		printf("Case %d: ", t);
		if(ans == (1<<30)) printf("invalid data\n");
		else cout<<ans<<endl;
	}
	return 0;
}
