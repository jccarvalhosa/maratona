#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, v[1111];
int b;

ll count(ll t) {
	ll x=b;
	for(int i=0;i<b;i++) x += t/v[i];
	return x;
}

int valid(ll t) {
	return count(t) >= n;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>b>>n;
		for(int i=0;i<b;i++) cin>>v[i];
		if(n <= b) {
			cout << "Case #"<<t<<": "<<n<<endl; 
			continue;
		}
		ll i=0, f=1e15;
		while(i<f-1) {
			ll m = (i+f)/2;
			if(valid(m)) f=m;
			else i=m;
		}
		int pos = n - count(f-1);
		for(int i=0;i<b;i++) if(f % v[i] == 0) {
			if(pos == 1) {
				cout << "Case #"<<t<<": "<<i+1<<endl; 
				break;
			}
			else {
				pos--;
			}
		}
	}
	return 0;
}
