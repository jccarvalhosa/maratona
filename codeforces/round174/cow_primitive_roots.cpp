#include <cstdio>

int main() {
	int p, x, exp, pot, ans;
	scanf("%d", &p);
	ans=0;
	for(x=1;x<p;x++) {
		pot = 1;
		for(exp=1;exp<p;exp++) {
			pot = (x * pot) % p;
			if((pot - 1 + p) % p == 0) break; 
		}
		if(exp == p-1) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
