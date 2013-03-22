#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

string v[15];
int R, C, adj[15][15][4], vis[15][15], cont[10];

void dfs(int a, int b) {
	vis[a][b]=1;
	cont[v[a][b]-'0']++;
	int i, na, nb;
	for(i=0;i<4;i++) if(adj[a][b][i]) {
		na = a+dx[i];
		nb = b+dy[i];
		if(na>=0 && na<R && nb>=0 && nb<C && !vis[na][nb]) dfs(na, nb);
	}
}

int main() {
	int T, i, j, k, a, valid;
	cin>>T;
	while(T--) {
		cin>>R>>C;
		for(i=0;i<R;i++) cin>>v[i];
		memset(adj, 0, sizeof(adj));
		for(i=0;i<R;i++) for(j=0;j<C;j++) {
			cin>>a;
			for(k=0;k<4;k++) if(a & (1<<k)) adj[i][j][k]=1;
		}
		valid=1;
		for(i=0;i<R;i++) for(j=0;j<C;j++) {
			a = v[i][j]-'0';
			for(k=1;k<=a;k++) {
				if(i+k<R && v[i+k][j]==v[i][j]) break;
				if(i-k>=0 && v[i-k][j]==v[i][j]) break;
				if(j+k<C && v[i][j+k]==v[i][j]) break;
				if(j-k>=0 && v[i][j-k]==v[i][j]) break;
			}
			if(k <= a) valid=0;
		}
		memset(vis, 0, sizeof(vis));
		for(i=0;i<R;i++) for(j=0;j<C;j++) if(!vis[i][j]){
			memset(cont, 0, sizeof(cont));
			dfs(i, j);
			for(k=1;k<=8;k++) if(cont[k]>1) valid=0;
		}
		cout << (valid ? "valid" : "invalid") << endl;
	}
	return 0;
}
