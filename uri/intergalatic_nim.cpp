#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll solve(ll n) {
	ll x=0;
	for(int i=0;1ll<<i<=n;i++) {
		ll div = n>>(i+1);
		ll rem = n - (div<<(i+1));
		ll cnt = div<<i;
		if(rem >= (1ll<<i)) cnt += rem-(1ll<<i)+1;
		if(cnt&1) x += 1ll<<i;
	}
	return x;
}

ll solve(ll a, ll b) { return solve(b) ^ solve(a-1); }

int main() {
	ll n;
	int q;
	while(scanf("%lld%d", &n, &q) != EOF) {
		while(q--) {
			ll a, b, k;
			scanf("%lld%lld%lld", &a, &b, &k);
			ll x = solve(1, n) ^ solve(a, b) ^ solve(a+k, b+k); 
			if(x == 0) printf("HAN\n");
			else printf("JABBA\n");
		}
	}
	return 0;
}
