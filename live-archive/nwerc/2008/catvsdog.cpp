#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n;
int adj[555][555], pai[555], vis[555];

string s[555][2];

void dfs(int v, int p) {
	vis[v]=1;
	pai[v]=p;
	for(int i=0;i<=n+1;i++) if(adj[v][i] && !vis[i]) dfs(i, v);
}

int flow() {
	int f=0;
	while(1) {
		for(int i=0;i<=n+1;i++) vis[i]=0;
		dfs(0, -1);
		if(!vis[n+1]) break;
		for(int i=n+1;i!=0;i=pai[i]) {
			adj[i][pai[i]]++;
			adj[pai[i]][i]--;
		}
		f++;
	}
	return f;
}

int main() {
	int T, c, d;
	cin>>T;
	while(T--) {
		memset(adj, 0, sizeof(adj));
		cin>>c>>d>>n;
		for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
		for(int i=1;i<=n;i++) {
			if(s[i][0][0]=='C') adj[0][i]=1;
			if(s[i][0][0]=='D') adj[i][n+1]=1;
		}
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {
			if(s[i][0]==s[j][1] || s[i][1] == s[j][0]) {
				if(s[i][0][0]=='C') adj[i][j]=1;
				else adj[j][i]=1;
			}
		}
		cout<<n - flow()<<endl;
	}
	return 0;
}
