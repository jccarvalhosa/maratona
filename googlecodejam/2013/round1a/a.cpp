#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef unsigned long long ll;

ll r, p;

ll R(ll n) { return r + 2*n; }
ll S(ll n) { return 2*R(n) + 1; }
ll sum(ll n) {
	ll v1 = S(n) + S(0);
	ll v2 = n+1;
	ll x = v1*v2;
	if(x/v1 != v2) return 0;
	return x/2;
}

ll upper_bound(ll i, ll f, ll key) {
	while(1) {
		ll m = (i+f)/2;
		ll x = sum(m);
		if(x == 0 || x > key) {
			ll y = sum(m-1);
			if(y != 0 && y <= key) return m;
			f = m-1;
		}
		else {
			ll y = sum(m+1);
			if(y == 0 || y > key) return m+1;
			i = m+1;
		}
	}
}

int main() {
	int T, t;
	cin>>T;
	for(t=1;t<=T;t++) {
		cin >> r >> p;
		printf("Case #%d: ", t);
		cout << upper_bound(0, p/r+1, p) << endl;
	}
	return 0;
}
