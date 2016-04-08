#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
map<string, map<string, string> > conv;

const int N=100;
int vis[N][N];
int dir, px, py, destx, desty, ans[N][N], ok[N][N];
char maze[N][N];
int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0, 1};
string name[] = {"LEFT", "DOWN", "UP", "RIGHT"};

void preproc() {
	conv["UP"]["UP"] = "UP";
	conv["UP"]["LEFT"] = "LEFT";
	conv["UP"]["RIGHT"] = "RIGHT";
	conv["UP"]["DOWN"] = "DOWN";
	conv["DOWN"]["UP"] = "DOWN";
	conv["DOWN"]["LEFT"] = "RIGHT";
	conv["DOWN"]["RIGHT"] = "LEFT";
	conv["DOWN"]["DOWN"] = "UP";
	conv["LEFT"]["UP"] = "RIGHT";
	conv["LEFT"]["LEFT"] = "UP";
	conv["LEFT"]["RIGHT"] = "DOWN";
	conv["LEFT"]["DOWN"] = "LEFT";
	conv["RIGHT"]["UP"] = "LEFT";
	conv["RIGHT"]["LEFT"] = "DOWN";
	conv["RIGHT"]["RIGHT"] = "UP";
	conv["RIGHT"]["DOWN"] = "RIGHT";
}

bool empty(ifstream& pFile) {
	return pFile.peek() == fstream::traits_type::eof();
}

void add(queue<pii>&q, int x, int y, int dir) {
	ok[x][y] = 0;
	int i=2;
	int nx = x+dx[i];
	int ny = y+dy[i];
	if(nx >= 0 && nx < N && ny >= 0 && ny < N && maze[nx][ny] == '#') {
		ok[x][y]=1;
	}
	if(nx >= 0 && nx < N && ny >= 0 && ny < N && !vis[nx][ny] && maze[nx][ny] != '#') {
		vis[nx][ny] = 1;
		ans[nx][ny] = dir == -1 ? i : dir;
		q.push(pii(nx, ny));
	}

	for(i=3;i>=0;i--) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx >= 0 && nx < N && ny >= 0 && ny < N && maze[nx][ny] == '#') {
			ok[x][y]=1;
		}
		if(nx >= 0 && nx < N && ny >= 0 && ny < N && !vis[nx][ny] && maze[nx][ny] != '#') {
			vis[nx][ny] = 1;
			ans[nx][ny] = dir == -1 ? i : dir;
			q.push(pii(nx, ny));
		}
	}
}

void solve() {
	int nx=-1, ny, nd=1e9;
	queue<pii> q;
	vis[px][py]=1;
	add(q, px, py, -1);
	int newdest = destx == px && desty == py;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int d = abs(x-px) + abs(y-py);
		q.pop();
		if(maze[x][y] == 'e') {
			dir = ans[x][y];
			return;
		}
		if(maze[x][y] == '?') {
			if(nx == -1 || (ok[x][y] && !ok[nx][ny]) || (ok[x][y] == ok[nx][ny] && d < nd)) nx = x, ny = y, nd = d;
		}
		else add(q, x, y, ans[x][y]);
	}
	if(newdest) {
		destx=nx, desty=ny;
	}
	dir = ans[destx][desty];
}

int main() {
	string id;
	cin>>id;
	string file = "maze" + id + ".txt";

	preproc();
	ifstream reader;
	reader.open (file);
	if(empty(reader)) {
		px = py = N/2;
		destx = px;
		desty = py;
		dir = 0;
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) maze[i][j] = '?';
	}
	else {
		reader >> px >> py >> dir >> destx >> desty;
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) reader >> maze[i][j];
	}
	reader.close();

	if(name[dir] == "LEFT") {
		for(int j=-1;j<=1;j++) for(int i=1;i>=-1;i--) cin>>maze[px+i][py+j]; 
	}
	if(name[dir] == "DOWN") {
		for(int i=1;i>=-1;i--) for(int j=1;j>=-1;j--) cin>>maze[px+i][py+j];
	}
	if(name[dir] == "UP") {
		for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) cin>>maze[px+i][py+j];
	}
	if(name[dir] == "RIGHT") {
		for(int j=1;j>=-1;j--) for(int i=-1;i<=1;i++) cin>>maze[px+i][py+j];
	}

	if(maze[destx][desty] != '?') destx=px, desty=py;

	int old = dir;
	solve();
	cout << conv[name[old]][name[dir]] << endl;

	px += dx[dir];
	py += dy[dir];

	ofstream writer;
	writer.open (file);
	writer << px << " " << py << " " << dir << " " << destx << " " << desty << endl;
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) writer << maze[i][j];
	writer.close();

	return 0;
}

