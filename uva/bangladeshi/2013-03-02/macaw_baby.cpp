#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

ull pd[62][61];

int main() {
	int i, j, k;
	for(i=1;i<=61;i++) for(j=1;j<=60;j++) {
		pd[i][j] = 0;
		for(k=1;k<=i;k++) pd[i][j] += (1ull << max(0, k-2)) * max(((1ull << j) - k), 0ull);
	}
	while(scanf("%d %d", &i, &j) && i) printf("%llu\n", pd[i+1][j]);
	return 0;
}
