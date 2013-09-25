#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, vis[1111111], cor[1111111];
int adj[1111111][4];
char tab[333][333];

void go(int x, int y, int d) {
	int c[2]={0};
	for(int i=0;i<d;i++) for(int j=0;j<d;j++) c[tab[x+i][y+j]-'0']++;
	int p = n;
	if(c[0]==0) cor[n++] = 1;
	else if(c[1]==0) cor[n++] = 0;
	else {
		cor[n++] = -1;
		for(int i=0;i<4;i++) {
			adj[p][i] = n;
			go(x + (i&1)*d/2, y + (i&2)*d/4, d/2);
		}
	}
}

int equal(int a, int b) {
	if(cor[a] != cor[b]) return 0;
	if(cor[a] == -1) for(int i=0;i<4;i++) if(!equal(adj[a][i], adj[b][i])) return 0;
	return 1;
}

int best(int p) {
	vis[p]=1;
	if(cor[p] != -1) return 1;
	int ans=1;
	for(int i=0;i<4;i++) {
		int j;
		for(j=0;j<n;j++) if(cor[adj[p][i]] == -1 && vis[j] && equal(adj[p][i], j)) break;
		if(j == n) ans += best(adj[p][i]);
	}
	return ans;
}

int main() {
	int x, y, L;
	while(1) {
		cin>>x>>y;
		if(!x) return 0;
		memset(tab, '0', sizeof(tab));
		int i, j;
		for(i=0;i<x;i++) for(j=0;j<y;j++) cin>>tab[i][j];
		for(i=1;1<<i<x;i++) ;
		L = 1<<i; 
		for(i=1;1<<i<y;i++) ;
		L = max(L, 1<<i);
		n=0;
		go(0, 0, L);
		for(int i=0;i<n;i++) vis[i]=0;
		cout<<n<<" "<<best(0)<<endl;
	}
}
