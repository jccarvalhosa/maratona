#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int M = 1000000007;

ll exp(ll x, int e) {
	if(!e) return 1;
	if(e&1) return (x*exp(x, e-1))%M;
	return exp((x*x)%M, e/2);
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int k, n=0;
		cin>>k;
		ll ans=1, p=1;
		for(int i=0;i<k;i++) {
			int x;
			cin>>x;
			n += x;
			p = (p*x)%M;
			if(x>2) ans = (ans*exp(x, x-2))%M;
		}
		if(k>1) {
			ans = (ans*p)%M;
			ans = (ans*exp(n, k-2))%M;
		}
		cout<<ans<<endl;
	}
	return 0;
}
