#include <cstdio>

int mod(int a) { return (a>0) ? a : -a; }

int main()
{
	int xa, ya, xs, ys, xb, yb;
	scanf("%d %d %d %d %d %d", &xa, &ya, &xs, &ys, &xb, &yb);
	printf("%s\n", mod(xa-xb)+mod(ya-yb)+mod(xb-xs)+mod(yb-ys)==mod(xa-xs)+mod(ya-ys) ? "Yes" : "No");
	return 0;
}
