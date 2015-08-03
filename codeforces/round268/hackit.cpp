#include <iostream>
#include <map>
using namespace std;
typedef unsigned long long ll;

ll a;
map<ll, ll> ans;

ll count(ll x) {
	if(ans.count(x)) return ans[x];
	ll pot=1;
	while(pot <= x) pot *= 10;
	pot /= 10;
	ll ret=0;
	ll aux = x;
	for(int i=0;i<10;i++) {
		if(aux >= pot) {
			ret += pot * i + count(pot-1);
			aux -= pot;
			if(ret > 5*a) break;
		}
		else {
			ret += (aux+1)*i + count(aux);
			break;
		}
	}
	ret = min(ret, 5*a);
	return ans[x] = ret;
}

ll search(ll sum) {
	ll i=1, f=5*a;
	while(i<f-1) {
		ll m = (i+f)/2;
		if(count(m) > sum) f=m;
		else i=m;
	}
	return i;
}

int main() {
	cin>>a;
	ans[0]=0;
	for(ll i=1;;i++) {
		ll f = search(a+count(i-1));
		if(count(f) - count(i-1) == a) {
			cout << i << " " << f << endl;
			return 0;
		}
	}
}
