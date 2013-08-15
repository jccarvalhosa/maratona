#include <cstdio>
#include <algorithm>
#include <queue>
#define N 1002
using namespace std;

struct rect { int x, X, y, Y; };

int dist_rect_rect(rect p, rect q) { return max(0, max(p.x-q.X, q.x-p.X)) + max(0, max(p.y-q.Y, q.y-p.Y)); }

int n, adj[N][N], d[N];

void dijkstra(int v) {
	int vis[N], i;
	priority_queue<pair<int, int> > q;
	for(i=0;i<n;i++) vis[i]=0, d[i]=1<<20;
	d[v]=0;
	q.push(make_pair(0, v));
	while(!q.empty()) {
		v=q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(i=0;i<n;i++) if(d[i] > d[v]+adj[v][i]) {
			d[i]=d[v]+adj[v][i];
			q.push(make_pair(-d[i], i));
		}
	}
}

int main() {
	int i, j, x1, y1, x2, y2;
	rect R[N];
	scanf("%d%d%d%d", &R[0].x, &R[0].y, &R[1].x, &R[1].y);
	scanf("%d", &n); n+=2;
	for(i=0;i<=1;i++) R[i].X=R[i].x, R[i].Y=R[i].y;
	for(i=2;i<n;i++) {
		scanf("%d%d%d%d", &R[i].x, &R[i].y, &R[i].X, &R[i].Y);
		if(R[i].x > R[i].X) swap(R[i].x, R[i].X);
		if(R[i].y > R[i].Y) swap(R[i].y, R[i].Y);
	}
	for(i=0;i<n;i++) adj[i][i]=0;
	for(i=0;i<n;i++) for(j=i+1;j<n;j++) adj[i][j] = adj[j][i] = dist_rect_rect(R[i], R[j]);
	dijkstra(0);
	printf("%d\n", d[1]);
	return 0;
}
