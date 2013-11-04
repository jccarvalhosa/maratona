#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int i, j, t, n, d, x, f[22], ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(f, 0, sizeof(f));
		for(i=0; i<n; i++) f[i]|=(1<<i);
		for(i=0; i<n; i++) {
			scanf("%d", &d);
			for(j=0; j<d; j++) {
				scanf("%d", &x);
				f[i]|=(1<<(--x));
			}
		}
		ans=n;
		for(i=1; i<(1<<n); i++) if(__builtin_popcount(i)<ans) {
			int cont=0;
			for(j=0; j<n; j++) if(i&(1<<j)) cont|=f[j];
			if(cont==(1<<n)-1) ans=__builtin_popcount(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
