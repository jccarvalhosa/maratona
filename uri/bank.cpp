#include <iostream>
using namespace std;
typedef long long ll;

const int M=1000000009;

int main() {
	ll n;
	while(cin>>n && n) {
		ll ans = n*(n-1)*(n-2)/6%M;
		for(int i=0;i<n-3;i++) ans = ans*(n-3-i)%M;
		cout<<ans<<endl;
	}
	return 0;
}
