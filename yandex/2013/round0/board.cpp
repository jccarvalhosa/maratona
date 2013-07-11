#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll cont(ll n, ll e) {
	ll sum = (n/e)*e/2;
	sum += max(n%e-e/2+1, 0ll);
	return sum % 2;
}

ll calc(ll n) {
	ll ans=0;
	for(int i=0;i<31;i++) if(cont(n, 1ll<<(i+1))) ans += 1ll<<i;
	return ans;
}

ll total(ll n, ll x) {
	if(!x) return 0;
	int lx = 63 - __builtin_clzll(x);
	ll a = 1 + n / (1ll<<(lx+1));
	ll b = 1 + min(n - (1ll<<lx), (1ll<<lx)-1);
	return a*b;
}

int main() {
	ll n;
	cin>>n;
	cout<<(n*(n+1)/2)<<" "<<total(n, calc(n))<<endl;
	return 0;
}
