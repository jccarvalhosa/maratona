#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 500001

int orig[MAX], v[MAX], f[MAX];

int main() {
	int T, t, q, n, i, j, k, a, up;
	scanf("%d", &T);
	for(t=1;t<=T;t++) {
		printf("Case %d:\n", t);
		scanf("%d%d%d", &n, &k, &q);
		for(i=0;i<k;i++) {
			scanf("%d", &orig[i]);
			v[i] = orig[i];
		}
		sort(v, v+k);
		f[0] = v[0]-1;
		for(i=1;i<k;i++) f[i] = f[i-1] + v[i] - v[i-1] - 1;
		for(i=0;i<q;i++) {
			scanf("%d", &a);
			if(a <= k) printf("%d\n", orig[a-1]);
			else if(v[k-1] < a) printf("%d\n", a);
			else {
				up = upper_bound(f, f+k, a-k-1) - f;
				printf("%d\n", v[up-1] + a-k-f[up-1]);
			}
		}
	}
	return 0;
}
