#include <cstdio>
#define MAX 6100000

long long a[MAX], s[MAX];

int main() {
	int i, k, n, x;
	for(i=2; i<MAX; i+=2) a[i]=2;
	for(i=3; i<MAX; i+=2) if(!a[i]) for(int j=i; j<MAX; j+=i) if(!a[j]) a[j]=i;
	for(i=1; i<MAX; i++) s[i]=s[i-1]+a[i];
	scanf("%d", &k);
	for(i=0; i<k; i++) {
		scanf("%d %d", &n, &x);
		printf("%lld\n", s[x+n-1]-s[x-1]);
	}
	return 0;
}
