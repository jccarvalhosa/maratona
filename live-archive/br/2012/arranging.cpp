#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 1000000000000LL

//pd[n][k][0-1] -> first n elements, k heaps, 1 if the first is used, 0 if its not used
//penal[i][j] -> penalty for dragging all the heaps from i to j
ll pd[1001][1001][2], penal[1001][1001], x[1001], w[1001];

int main() {
	int n, k, i, j, aux;
	while(scanf("%d%d", &n, &k)!=EOF) {
		for(i=n;i;i--) scanf("%lld%lld", &x[i], &w[i]);
		for(i=0;i<=n;i++) for(j=0;j<=n;j++) pd[i][j][0] = pd[i][j][1] = INF;
		penal[1][1]=0;
		for(i=2;i<=n;i++) {
			penal[i][i]=0;
			ll sum=w[i];
			for(j=i-1;j>0;j--) {
				penal[i][j] = penal[i][j+1] + sum*(x[j]-x[j+1]);
				sum += w[j];
			}
		}
		pd[1][1][1]=0;
		for(i=2;i<=n;i++) for(j=1;j<=i;j++) {
			pd[i][j][1] = min(pd[i-1][j-1][0], pd[i-1][j-1][1]);
			for(aux=i-1;aux>=j && penal[i][aux] < pd[i][j][0];aux--) pd[i][j][0] = min(pd[i][j][0], penal[i][aux] + pd[aux][j][1]);
		}
		printf("%lld\n", min(pd[n][k][0], pd[n][k][1]));
	}
	return 0;
}
