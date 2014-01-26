#include <iostream>
using namespace std;
typedef long long ll;

ll cont(ll i, ll f) {
	ll n = f-i+1;
	return (i+f)*n/2 - n*i;
}

ll solve(ll n) {
	ll ret=0;
	for(ll i=0;;i++) {
		ll ini = 1ll<<i;
		ll fim = 1ll<<(i+1);
		if(ini >= n) break;
		if(fim > n) {
			ret += cont(ini, n);
			break;
		}
		else {
			ret += cont(ini, fim-1);
		}
	}
	return ret;
}

int main() {
	int n;
	cin>>n;
	cout << solve(n) << endl;
	return 0;
}
