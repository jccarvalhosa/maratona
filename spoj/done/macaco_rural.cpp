#include <cstdio>
#include <algorithm>
using namespace std;

int p[2000000];

int main() {
	int N, i, sol;
	while(scanf("%d", &N) && N) {
		for(i=0;i<N;i++) scanf("%d", &p[i]);
		sort(p, p+N);
		sol=p[0]+p[N-1];
		for(i=1;2*i != N;i++) sol = max(sol, p[i]+p[N-i-1]);
		printf("%d\n", sol);
	}
	return 0;
}
