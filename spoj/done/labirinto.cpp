#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

int N, M, h[50][50], vis[50][50][10];
int dx[] = {0, 1, 0, 0, -1};
int dy[] = {0, 0, 1, -1, 0};

int bfs() {
	int na, nb, a, b, d, delta, i, j;
	queue<pair<pii, pii> > q;
	q.push(mp(mp(0, 0), mp(0, 0)));
	while(!q.empty()) {
		a = q.front().first.first;
		b = q.front().first.second;
		d = q.front().second.first;
		delta = q.front().second.second;
		if(a == N-1 && b == M-1) return d;
		q.pop();
		if(vis[a][b][delta]) continue;
		vis[a][b][delta] = 1;
		for(i=0;i<5;i++) {
			na = a+dx[i];
			nb = b+dy[i];
			if(na < 0 || nb < 0 || na >= N || nb >= M || (h[na][nb]+delta)%10 > (h[a][b]+delta)%10 + 1) continue;
			q.push(mp(mp(na, nb), mp(d+1, (delta+1)%10)));
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;i++) for(int j=0;j<M;j++) scanf("%d", &h[i][j]);
	memset(vis, 0, sizeof(vis));
	printf("%d", bfs());
	return 0;
}
