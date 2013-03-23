#include <iostream>
using namespace std;
typedef long long ll;

ll p10[16], num[16];
int alg[17];

ll sum_digits(ll x) {
	ll ans=0, n=0;
	int p, d, i;
	for(p=0;x;p++) {
		d = x % 10;	x /= 10;
        ans += p10[p]*d*p;
		for(i=0;i<d;i++) ans += p10[p];
		ans += n+1;
		n += p10[p]*d;
	}
	for(i=0;i<p;i++) ans -= (p-i) * num[i];
	return ans;
}

ll sum(ll x) { return x%4 + 3*(x/4) + sum_digits(x); }

ll lower_bound(ll i, ll f, ll key) {
	while(1) {
		ll m = (i+f)/2;
		if(sum(m) >= key) {
			if(sum(m-1) < key) return m;
			f = m-1;
		} else {
			if(sum(m+1) >= key) return m+1;
			i = m+1;
		}
	}
}

int main() {
	int i, t=0;
	ll k, n;
	p10[0]=num[0]=1;
	for(i=1;i<=15;i++) p10[i] = 10*p10[i-1];
	for(i=1;i<=15;i++) num[i] = 9*p10[i-1];
	while(cin>>k && k) {
		t=0;
		n = lower_bound(0, p10[15], k);
		k = sum(n) - k;
		if(n % 4 == 2) alg[t++] = 0;
		if(n % 2 == 1) alg[t++] = 2;
		for(;n;n/=10) alg[t++] = n%10;
		cout << alg[k] << endl;
	}
	return 0;
}
