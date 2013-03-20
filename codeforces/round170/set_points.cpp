#include <cstdio>

int main() {
	int n, m, i;
	scanf("%d%d", &n, &m);
	if(m==3) {
		if(n==3) printf("0 0\n0 1\n1 0\n");
		else if(n==4) printf("0 0\n0 10\n10 0\n1 1\n");
		else printf("-1\n");
	} else {
		for(i=m;i>=1;i--) printf("%d %d\n", m-i+1, i*i);
		for(i=n-m;i>=1;i--) printf("%d %d\n", -(n-m-i+1), -i*i);
	}
	return 0;
}
