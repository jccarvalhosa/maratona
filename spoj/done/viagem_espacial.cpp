#include <cstdio>

int main() {
	int n, a, b, c, i, xc, yc, xi, yi, xf, yf, r, cont=0;
	scanf("%d%d%d%d", &n, &xc, &yc, &r);
	for(i=0;i<n;i++) {
		scanf("%d%d%d%d", &xi, &yi, &xf, &yf);
		a=xf-xi;
		b=yi-yf;
		c=-(yi*a+xi*b);
		if((long long)(a*yc+b*xc+c)*(a*yc+b*xc+c) <= (long long)(a*a + b*b)*r*r) cont++;
	}
	printf("%d", cont);
	return 0;
}
