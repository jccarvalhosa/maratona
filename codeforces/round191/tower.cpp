#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

struct opp {
	char c;
	int i, j;
	opp(char c, int i, int j): c(c), i(i), j(j) {}
};

vector<opp> v;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int n, m, vis[502][502];
char G[502][502]; 

void dfs(int x, int y, int root) {
	vis[x][y]=1;
	v.push_back(opp('B', x, y));
	int i, nx, ny;
	for(i=0;i<4;i++) {
		nx = x+dx[i];
		ny = y+dy[i];
		if(G[nx][ny]!='#' && vis[nx][ny]==0) dfs(nx, ny, 0); 
	}
	if(!root) {
		v.push_back(opp('D', x, y));
		v.push_back(opp('R', x, y));
	}
}

int main() {
	int i, j;
	for(i=0;i<502;i++) for(j=0;j<502;j++) G[i][j] = '#';
	cin>>n>>m;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) cin>>G[i][j];
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(G[i][j] != '#' && vis[i][j]==0) dfs(i, j, 1);
	cout<<v.size()<<endl;
	for(i=0;i<v.size();i++) cout<<v[i].c<<" "<<v[i].i<<" "<<v[i].j<<endl;
	return 0;
}
