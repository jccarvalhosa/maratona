#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
using namespace std;

int n, m, vis[444];
vector<int> adj[444];

void dfs(int v) {
	vis[v]=1;
	for(int i=0;i<adj[v].size();i++) {
		int u = adj[v][i];
		if(!vis[u]) dfs(u);
	}
}

int main() {
	cin>>n>>m;
	string vert, hor;
	cin>>hor;
	cin>>vert;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		for(int ii=0;ii<n;ii++) {
			if((vert[j] == '^' && ii < i) || (vert[j] == 'v' && ii > i)) adj[m*i+j].push_back(m*ii+j);
		}
		for(int jj=0;jj<m;jj++) {
			if((hor[i] == '>' && jj > j) || (hor[i] == '<' && jj < j)) adj[m*i+j].push_back(m*i+jj);
		}
	}
	int ok=1;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		for(int ii=0;ii<n;ii++) for(int jj=0;jj<m;jj++) vis[m*ii+jj]=0;
		dfs(m*i+j);
		for(int ii=0;ii<n;ii++) for(int jj=0;jj<m;jj++) if(!vis[m*ii+jj]) ok=0;
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
