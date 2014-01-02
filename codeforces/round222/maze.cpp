#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

char tab[555][555];
int vis[555][555];
vector<pii> v[555*555];

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>tab[i][j];
	if(k>0) {
		int ii, jj;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(tab[i][j]=='.') ii=i, jj=j;
		queue<pp> q;
		vis[ii][jj]=1;
		v[0].push_back(pii(ii, jj));
		q.push(pp(0, pii(ii, jj)));
		while(!q.empty()) {
			int d = q.front().first;
			ii = q.front().second.first;
			jj = q.front().second.second;
			q.pop();
			int dx[] = {1, -1, 0, 0};
			int dy[] = {0, 0, 1, -1};
			for(int i=0;i<4;i++) {
				int ni = ii + dx[i];
				int nj = jj + dy[i];
				if(ni<0 || ni>=n || nj<0 || nj>=m || tab[ni][nj]=='#' || vis[ni][nj]) continue;
				vis[ni][nj]=1;
				v[d+1].push_back(pii(ni, nj));
				q.push(pp(d+1, pii(ni, nj)));
			}
		}
		for(int i=555*555-1;i>=0;i--) {
			for(int j=0;j<v[i].size();j++) {
				if(k==0) break;
				ii = v[i][j].first;
				jj = v[i][j].second;
				tab[ii][jj] = 'X';
				k--;
			}
			if(k==0) break;
		}
	}
	for(int i=0;i<n;i++) { for(int j=0;j<m;j++) cout<<tab[i][j]; cout<<endl; }
	return 0;
}
