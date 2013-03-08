#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 500001

int orig[MAX], v[MAX], f[MAX];

int upper_bound(int *p, int i, int f, int key) {
	int m, N = f;
	while(1) {
		m = (i+f)/2;
		if(p[m] <= key) {
			i = m+1;
			if(i==N || p[i] > key) return i;
		}
		else {
			f=m;
			if(i==f) return i;
		}
	}
}

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
				up = upper_bound(f, 0, k, a-k-1);
				printf("%d\n", v[up-1] + a-k-f[up-1]);
			}
		}
	}
	return 0;
}
