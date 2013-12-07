#include <iostream>
using namespace std;
typedef long long ll;

const ll M = 10000000000007ll;

ll c[11111];

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int l;
		cin>>l;
		int n=l*l;
		c[1]=n;
		for(int i=2;i<=n;i++) c[i] = (c[i-1]*(n-i+1))%M;
		int a, b;
		cin>>a>>b;
		ll ans=0;
		for(int i=a;i<=b;i++) ans = (ans+c[i])%M;
		cout<<"Case "<<t<<": "<<ans<<endl;
	}
	return 0;
}
