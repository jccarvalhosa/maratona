#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, x, k, e, total, dp[100000], a[100000];

int valid(ll t) {
	if(t>=e+n) return 1;
	ll g = min(t, e)*x;
	ll d = min(n, t-e)-1;
	if(d>=0) g += dp[d];
	return g + t*k >= total;
}

ll lower_bound(ll i, ll f) {
	while(1) {
		ll m = (i+f)/2;
		if(valid(m)) {
			if(!valid(m-1)) return m;
			f = m-1;
		}
		else {
			if(valid(m+1)) return m+1;
			i = m+1;
		}
	}
}

int main() {
	int i;
	cin>>n>>x>>k;
	for(i=0;i<n;i++) {
		cin>>a[i];
		total += a[i];
	}
	if(!x) {
		cout<<(total+k-1)/k<<endl;
		return 0;
	}
	for(i=0;i<n;i++) {
		e += a[i]/x;
		a[i]%=x;
	}
	sort(a, a+n, greater<int>());
	dp[0] = a[0];
	for(i=1;i<n;i++) dp[i] = dp[i-1] + a[i];
	cout<<lower_bound(0, total)<<endl;
	return 0;
}
