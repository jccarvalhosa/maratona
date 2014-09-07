#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int p;
	cin>>p;
	while(p--) {
		int n, t;
		scanf("%d%d", &t, &n);
		int m = n;
		while(n > 1) {
			m = max(m, n);
			if(n & 1) n = 3*n + 1;
			else n >>= 1;
		}
		printf("%d %d\n", t, m);
	}
	return 0;
}
