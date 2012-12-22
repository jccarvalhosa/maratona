#include <cstdio>

char c[1000000];
int main() {
	int n, i, cont=0;
	scanf("%d", &n);
	scanf("%s", c);
	for(i=0;i<n;i++) {
		if(c[i] == 'P' || c[i] == 'C') cont += 2;
		else if(c[i] == 'A') cont++;
	}
	printf("%d\n", cont);
	return 0;
}
