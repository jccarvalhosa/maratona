#include <cstdio>
#define MOD 1000000007
typedef long long ll;

ll ans, fat[17];
int n;
int val[] = { 0, 1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};

void dfs(int bpos, int bmask, int cmask) {
	if(bpos==n) ans = (ans+1)%MOD;
	for(int i=0;i<n;i++) {
		if(bmask & (1<<i)) continue;
		if(cmask & (1<<((i+bpos)%n))) continue;
		dfs(bpos+1, bmask + (1<<i), cmask + (1<<((i+bpos)%n)));
	}
}

int main() {
	int i, j;
	scanf("%d", &n);
	/*
	fat[0]=1;
	for(i=1;i<=n;i++) fat[i] = (fat[i-1]*i) % MOD;
	ans=0;
	dfs(0, 0, 0);
	ans = (fat[n] * ans) % MOD;
	printf("%lld\n", ans);
	*/
	printf("%d\n", val[n]);
	return 0;
}
