#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, i, sol, aux, sum[100001], best[100001], v[100000];
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d", &v[i]);
	sum[0] = best[0] = 0;
	for(i=0;i<N;i++) {
		sum[i+1] = sum[i] + v[i];
		best[i+1] = max(best[i], sum[i+1]);
	}
	for(i=sol=0;i<=N;i++) sol = max(sol, best[i] + (sum[N] - sum[i]));
	for(i=aux=0;i<N;i++) {
		aux = max(0, aux + v[i]);
		sol = max(sol, aux);
	}
	printf("%d", sol);
	return 0;
}
