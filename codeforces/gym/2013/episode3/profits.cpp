#include <cstdio>

int main() {
	int max, ans, s, n, a, i;
	while(scanf("%d", &n) && n) {
		max=-1000000;
		s=ans=0;
		for(i=0; i<n; i++) {
			scanf("%d", &a);
			s+=a;
			if(s>ans) ans=s;
			if(s<0) s=0;
			if(a>max) max=a;
		}
		if(max<0) printf("%d\n", max);
		else printf("%d\n", ans);
	}
	return 0;
}
