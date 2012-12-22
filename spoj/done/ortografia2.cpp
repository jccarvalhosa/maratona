#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char d[1000][30], t[100][30];
int n, m, A[30][30], nd[1000], nt[100];

bool align(char *a, char *b) {
	int i, j;
	for(i=0;i<=n;i++) A[i][0] = i;
	for(i=0;i<=m;i++) A[0][i] = i;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) A[i][j] = min(A[i-1][j-1] + (a[i-1] != b[j-1]), min(A[i-1][j], A[i][j-1]) + 1);
	return A[n][m] <= 2;
}

int main() {
	int N, M, i, j, k;
	scanf("%d%d", &N, &M);
	for(i=0;i<N;i++) {
		scanf("%s", d[i]);
		nd[i] = strlen(d[i]);
	}
	for(i=0;i<M;i++) {
		scanf("%s", t[i]);
		nt[i] = strlen(t[i]);
	}
	for(i=0;i<M;i++) {
		int flag=0;
		for(j=0;j<N;j++) {
			n = nt[i]; m = nd[j];
			if(align(t[i], d[j])) {
				if(flag) printf(" ");
				else flag=1;
				printf("%s", d[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
