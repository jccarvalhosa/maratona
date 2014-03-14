#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<vi> vv;

map<ll, int> vis;
vv dest(4), ini(4);

char moves[] = "LRDU";
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

char ans[55];

int mod(int x) { return x>0?x:-x; }

int heur() {
	int ret=0;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(ini[i][j]) {
		int v = ini[i][j]-1;
		int d = mod(v/4 - i) + mod(v%4 - j);
		ret += d;
	}
	return ret;
}

ll conv() {
	ll ret=0;
	for(int i=0;i<16;i++) ret += ini[i/4][i%4]*(1ull<<4*i);
	return ret;
}

int go(int px, int py, int step) {
	if(ini == dest) {
		ans[step] = '\0';
		return 1;
	}
	if(step + heur() > 50) return 0;
	ll id = conv();
	if(vis.count(id) && vis[id] <= step) return 0;
	vis[id] = step;
	for(int i=0;i<4;i++) {
		int nx = px + dx[i];
		int ny = py + dy[i];
		if(nx<0||nx>=4||ny<0||ny>=4) continue;
		swap(ini[px][py], ini[nx][ny]);
		if(go(nx, ny, step+1)) {
			ans[step] = moves[i];
			return 1;
		}
		swap(ini[px][py], ini[nx][ny]);
	}
	return 0;
}

int is_solvable() {
	int ibr, nr_inversions = 0;
	for (int i = 0; i < 16; i++) {
		if (!ini[i/4][i%4])
			ibr = i / 4;
		else {
			for (int j = i + 1; j < 16; j++)
				if (ini[j/4][j%4] && ini[i/4][i%4] > ini[j/4][j%4])
					nr_inversions++;
		}
	}
	return (ibr & 1) ? !(nr_inversions & 1) : (nr_inversions & 1);
}

int main() {
	for(int i=0;i<16;i++) dest[i/4].push_back((i+1)%16);
	for(int i=0;i<4;i++) ini[i].resize(4);
	int T;
	scanf("%d", &T);
	while(T--) {
		int px, py;
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				scanf("%d", &ini[i][j]);
				if(ini[i][j]==0) px=i, py=j;
			}
		}
		vis.clear();
		if(is_solvable() && go(px, py, 0)) printf("%s\n", ans);
		else printf("This puzzle is not solvable.\n");
	}
	return 0;
}
