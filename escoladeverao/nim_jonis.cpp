#include <cstdio>
typedef long long ll;

ll sum(ll a) {
	ll ret = 0;
	for(int i=0;;i++) {
		ll pot = (1ll<<i);
		if(pot > a) break;
		ll d = a / (2*pot);
		ll r = a % (2*pot);
		ll cont = d*pot + (r>pot-1 ? r-pot+1 : 0);
		if(cont & 1) ret += pot;
	}
	return ret;
}

ll sum(ll a, ll b) { return b >= a ? sum(b) ^ sum(a-1) : 0; }

int main() {
	int q;
	ll n;
	scanf("%lld %d", &n, &q);
	while(q--) {
		ll a, b, k;
		scanf("%lld %lld %lld", &a, &b, &k);
		ll grundy = sum(1, a-1) ^ sum(a+k, b+k) ^ sum(b+1, n);
		printf("%s\n", grundy ? "ALICE" : "BOB");
	}
	return 0;
}
