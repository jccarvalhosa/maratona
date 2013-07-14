#include <iostream>
#include <string>
using namespace std;

int adj[52][52], vis[52];

void dfs(int v) {
	int u, i;
	vis[v]=1;
	if(v%2==0) u=v+1;
	else u=v-1;
	for(i=0;i<52;i++) if(adj[u][i] && !vis[i]) dfs(i);
}

int cicle() {
	int v, i, j;
	for(i=0;i<52;i+=2) {
		for(j=0;j<52;j++) vis[j]=0;
		for(j=0;j<52;j++) if(adj[i][j]) dfs(j);
		if(vis[i+1]) return 1;
	}
	return 0;
}

int main() {
	int n, i, j;
	cin>>n;
	while(n--) {
		string s;
		cin>>s;
		int c=0, v[4];
		for(i=0;i<8;i+=2) if(s[i] != '0') v[c++] = 2*(s[i]-'A') + (s[i+1]=='+' ? 0 : 1);
		for(i=0;i<c;i++) for(j=i+1;j<c;j++) adj[v[i]][v[j]] = adj[v[j]][v[i]] = 1;
	}
	cout<<(cicle()?"unbounded":"bounded")<<endl;
	return 0;
}
