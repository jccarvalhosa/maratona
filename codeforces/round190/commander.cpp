#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

char cor[100000];
vector<int> adj[100000];

vector<int> dfs(int v, int p) {
	int i, j, u;
	vector<int> cont(26, 0), aux;
	for(i=0;i<adj[v].size();i++) {
		u=adj[v][i];
		if(u==p) continue;
		aux = dfs(u, v);
		for(j=0;j<26;j++) cont[j] += aux[j];
	}
	for(j=25;j>=0;j--) if(cont[j]>=2) break;
	for(i=j+1;i<26;i++) if(cont[i]==0) break;
	cor[v]='Z'-i;
	cont[i]=1;
	for(j=i-1;j>=0;j--) cont[j]=0;
	return cont;
}

int main() {
	int n, a, b, i;
	cin>>n;
	for(i=0;i<n-1;i++) {
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	dfs(0, -1);
	for(i=0;i<n;i++) cout<<cor[i]<<" ";
	cout<<endl;
	return 0;
}
