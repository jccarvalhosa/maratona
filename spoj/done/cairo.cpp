#include <cstdio>
#include <cstring>
#include <algorithm>
#define X 1000
#define Y 1000
using namespace std;

int tree[X+1][Y+1];

void update(int x, int y, int v) {
	int y1;
	for(; x <= X; x += x&-x) for(y1=y; y1<=Y; y1 += y1&-y1) tree[x][y1] = max(tree[x][y1], v);
}

int query(int x, int y) {
	int y1, ret=0;
	for(; x ; x -= x&-x) for(y1=y; y1 ; y1 -= y1&-y1) ret = max(ret, tree[x][y1]);
	return ret;
}

int main() {
	int T, N, x, y, v, ans;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		ans=0;
		memset(tree, 0, sizeof(tree));
		while(N--) {
			scanf("%d%d", &x, &y);
			v = query(x, y)+1;
			ans = max(ans, v);
			update(x, y, v);
		}
		printf("%d\n", ans);
	}
	return 0;
}
