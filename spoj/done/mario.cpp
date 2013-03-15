#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, v[100000];

int main() {
	int i, j, best, cont;
	while(scanf("%d%d", &m, &n) && n) {
		for(i=0;i<n;i++) scanf("%d", &v[i]);
		best=i=j=0;
		while(j < n) {
			while(v[j]-v[i]+1 <= m && j < n) j++;
			best = max(best, j-i);
			i++;
		}
		printf("%d\n", m-best);
	}
	return 0;
}
