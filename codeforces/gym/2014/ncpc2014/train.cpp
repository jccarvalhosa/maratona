#include <bits/stdc++.h>
using namespace std;

int main() {
	int c, n, x, y, z, ok=1, cur=0;
	scanf("%d %d", &c, &n);
	for(int i=0; i<n; i++) {
		scanf("%d %d %d", &x, &y, &z);
		cur-=x;
		if(cur<0) ok=0;
		cur+=y;
		if(cur>c) ok=0;
		if(cur!=c && z) ok=0;
	}
	if(cur) ok=0;
	printf("%s\n", ok ? "possible" : "impossible");
	return 0;
}
