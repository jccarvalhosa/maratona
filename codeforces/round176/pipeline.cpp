#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

ll n, k;

ll sum(ll x) { return 1 + (2*k-x+1)*x/2; }

ll lower_bound(ll i, ll f, ll key) {
	while(1) {
		ll m = (i+f)/2;
		if(sum(m) >= key) {
			if(sum(m-1) < key) return m;
			f = m-1;
		}
		else {
			if(sum(m+1) >= key) return m+1;
			i = m+1;
		}
	}
}

int main() {
	ll s, a;
	cin>>n>>k;
	k--;
	s = sum(k);
	if(n > s) cout<<-1<<endl;
	else if(n==s) cout<<k<<endl;
	else cout<<lower_bound(1, k, n)<<endl;
	return 0;
}
