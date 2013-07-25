#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
using namespace std;
typedef pair<int, int> pii;
#define INF 1000000000

int n, m, D[1000][1000], vis[1000][1000];
string G[1111];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y) {
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) D[i][j] = INF;
	queue<pair<pii, int> > q;
	memset(vis, 0, sizeof(vis));
	q.push(make_pair(pii(x, y), 0));
	vis[x][y] = 1;
	while(!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int d = q.front().second;
		q.pop();
		D[a][b] = d;
		for(int i=0;i<4;i++) {
			int na = a+dx[i];
			int nb = b+dy[i];
			if(na<0 || na>=n || nb<0 || nb>=m) continue;
			if(!vis[na][nb] && G[na][nb] != 'T') {
				vis[na][nb]=1;
				q.push(make_pair(pii(na, nb), d+1));
			}
		}
	}
}

int main() {
	int i, j, mydist;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>G[i];
	for(i=0;i<n;i++) for(j=0;j<m;j++) if(G[i][j] == 'E') bfs(i, j);
	for(i=0;i<n;i++) for(j=0;j<m;j++) if(G[i][j] == 'S') mydist = D[i][j];
	long long ans=0;
	for(i=0;i<n;i++) for(j=0;j<m;j++) if(G[i][j] >= '1' && G[i][j] <= '9' && D[i][j]<=mydist) ans+=G[i][j]-'0';
	cout<<ans<<endl;
	return 0;
}
