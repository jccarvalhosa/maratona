#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

vector<pii> ans;
vector<pii> path;

int n, m, px, py, swaped, s[33][33], t[33][33], vis[33][33], aux[33][33], cnts[999], cntt[999];

int dx[] = {1, 1, -1, -1, 0, 1, 0, -1};
int dy[] = {1, -1, 1, -1, 1, 0, -1, 0};

void change() {
	if(m >= n) return;
	swaped ^= 1;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) aux[j][i] = s[i][j];
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) s[i][j] = aux[i][j];
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) aux[j][i] = t[i][j];
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) t[i][j] = aux[i][j];
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) aux[j][i] = vis[i][j];
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) vis[i][j] = aux[i][j];
	swap(n, m);
	swap(px, py);
}

int mod(int x) { return x > 0 ? x : -x; }

void add(int x, int y) {
	if(swaped) ans.push_back(pii(y, x));
	else ans.push_back(pii(x, y));
}

pii get(int c) {
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!vis[i][j] && s[i][j]==c) return pii(i, j);
}

int dir(int sx, int sy, int x, int y) {
	int mi, d=1e9;
	for(int i=0;i<8;i++) {
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
		int nd = mod(x-nx) + mod(y-ny);
		if(nd < d) d = nd, mi = i;
	}
	return mi;
}

void move(int x, int y) {
	while(x != px || y != py) {
		int mi = dir(px, py, x, y);
		int nx = px + dx[mi];
		int ny = py + dy[mi];
		add(nx, ny);
		swap(s[px][py], s[nx][ny]);
		swap(vis[px][py], vis[nx][ny]);
		px = nx; py = ny;
	}
}

void correct(int x, int y) {
	pii p = get(t[x][y]);
	int sx = p.first;
	int sy = p.second;
	path.clear();
	path.push_back(pii(sx, sy));
	vis[px][py]=0;
	while(sx != x || sy != y) {
		int mi = dir(sx, sy, x, y);
		sx = sx + dx[mi];
		sy = sy + dy[mi];
		path.push_back(pii(sx, sy));
	}
	vis[px][py]=1;
	vis[p.first][p.second] = 1;
	for(int i=0;i<path.size()-1;i++) {
		move(path[i+1].first, path[i+1].second);
		add(path[i].first, path[i].second);
		swap(s[px][py], s[path[i].first][path[i].second]);
		px = path[i].first;
		py = path[i].second;
	}
}

int solve() {
	for(int i=0;i<999;i++) if(cnts[i]!=cntt[i]) return 0;
	change();
	if(n==1) {
		for(int i=0;i<m;i++) for(int j=0;j<m;j++) {
			px=0, py=i;
			ans.clear();
			add(0, i);
			move(0, j);
			int k;
			for(k=0;k<m;k++) if(s[0][k] != t[0][k]) break;
			if(k==m) return 1;
			move(0, i);
		}
		return 0;
	}
	pii p = get(t[0][0]);
	px = p.first;
	py = p.second;
	vis[px][py] = 1;
	add(px, py);
	while(m > 2) {
		for(int i=0;i<n;i++) correct(i, m-1);
		m--;
		change();
	}
	move(1, 1);
	p = get(t[1][1]);
	move(p.first, p.second);
	vis[1][1]=1;
	move(1, 0);
	p = get(t[1][0]);
	move(p.first, p.second);
	move(0, 0);
	return 1;
}

int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		cin>>s[i][j];
		cnts[s[i][j]]++;
	}
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		cin>>t[i][j];
		cntt[t[i][j]]++;
	}
	if(solve()) {
		cout << ans.size()-1 << endl;
		for(int i=0;i<ans.size();i++) cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
	} else {
		cout << -1 << endl;
		return 0;
	}
	return 0;
}
