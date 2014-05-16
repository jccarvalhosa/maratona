#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) != EOF) {
		a = a*b;
		c = c-b;
		int g = __gcd(a,c);
		printf("%d/%d\n", a/g, c/g);
	}
}
