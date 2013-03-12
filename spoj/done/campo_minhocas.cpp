#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 1000
#define INF 1000000000

int v[MAX][MAX], up[MAX][MAX], left[MAX][MAX], right[MAX][MAX];

int main() {
	int L, C, i, j, t;
	for(t=1; scanf("%d%d", &L, &C) && L; t++) {
		printf("Teste %d\n", t);
		for(i=0;i<L;i++) for(j=0;j<C;j++) scanf("%d", &v[i][j]);
		up[0][0] = v[0][0];
		left[0][0] = right[0][0] = -INF;
		for(j=1;j<C;j++) {
			up[0][j] = right[0][j] = -INF;
			left[0][j] = max(left[0][j-1], up[0][j-1]) + v[0][j];
		}
		for(i=1;i<L;i++) {
			for(j=0;j<C;j++) up[i][j] = max(up[i-1][j], max(left[i-1][j], right[i-1][j])) + v[i][j];
			left[i][0] = -INF;
			for(j=1;j<C;j++) left[i][j] = max(left[i][j-1], up[i][j-1]) + v[i][j];
			right[i][C-1] = -INF;
			for(j=C-2;j>=0;j--) right[i][j] = max(right[i][j+1], up[i][j+1]) + v[i][j];
		}
		printf("%d\n", max(up[L-1][C-1], left[L-1][C-1]));
	}
	return 0;
}
