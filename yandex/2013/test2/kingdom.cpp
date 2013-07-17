#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;

int n, m, cor[1111][1111], vis[1111][1111];

int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

void bfs(vector<pii> v, int dmax, int cini) {
	queue<pair<pii, int> > q;
	memset(vis, 0, sizeof(vis));
	for(int i=0;i<v.size();i++) {
		q.push(make_pair(v[i], 0));
		vis[v[i].first][v[i].second] = 1;
	}
	while(!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int d = q.front().second;
		q.pop();
		cor[a][b] = d%2?cini:1-cini;
		if(d==dmax) continue;
		for(int i=0;i<8;i++) {
			int na = a+dx[i];
			int nb = b+dy[i];
			if(na<=0 || na>n || nb<0 || nb>m) continue;
			if(!vis[na][nb]) {
				vis[na][nb]=1;
				q.push(make_pair(pii(na, nb), d+1));
			}
		}
	}
}

int v[1000][1000], total[1001];

int main() {
	int i, j, k=0, s=0, t;
	cin>>n>>m;
	for(k=1;;k++) {
		s += k;
		total[k] = k;
		if(s > n*m) break;
	}
	s -= k;
	k--;
	total[k] = k+m*n-s;
	cout<<k<<endl;
	if(m==1) {
		for(int i=1;i<=k;i++) while(total[i]--) printf("%c\n", 'A'+i%2);
		return 0;
	}
	{ vector<pii> v; v.push_back(pii(1, 1)); bfs(v, m-1, 0); }
	int dir=1, x=m+1, y=1, c=(m+1)%2;
	int ind=2*m+1;
	while(1) {
		cor[x][y] = c;
		total[ind]--;
		if(total[ind]==0) {
			ind++;
			c = 1-c;
			if(ind==k+1) break;
		}
		y+=dir;
		if(y==0) {
			dir=1;
			y=1;
			x++;
		}
		else if(y==m+1) {
			y=m;
			x++;
			dir=-1;
		}
	}
	{ vector<pii> v; v.push_back(pii(n, m)); v.push_back(pii(n-1, m)); bfs(v, m-1, (m+c)%2); }
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) printf("%c", 'A'+cor[i][j]);
		cout<<endl;
	}
	return 0;
}
