#include <cstdio>
using namespace std;

int n, k, mat[801][801], best;

int main() {
	freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &mat[i+j][n-i+j-1]);
	n*=2,k*=2;
	for (int i=0;;i++) {
		int sum=0;
		for(int a=i;a<n && a<=i+k;a++) for(int b=0;b<n && b<=k;b++)	sum+=mat[a][b];
		if (best<sum) best=sum;
		if (i+k>=n) break;
		for (int j=1; j+k<n; j++) {
			for (int a=i; a<n && a<=i+k; a++) sum += mat[a][j+k]-mat[a][j-1];
			if (best<sum) best=sum;
		}
	}
	printf("%d\n", best);
}
