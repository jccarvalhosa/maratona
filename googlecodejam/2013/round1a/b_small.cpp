#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int e, r, n, v[10], ans;

void go(int p, int en, int t) {
	ans = max(ans, t);
	if(p == n) return;
	for(int i=0;i<=en;i++) go(p+1, min(en-i+r, e), t + v[p]*i);
}

int main() {
	int i, T, t;
	cin>>T;
	for(t=1;t<=T;t++) {
		cin>>e>>r>>n;
		for(i=0;i<n;i++) cin>>v[i];
		ans=0;
		go(0, e, 0);
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
