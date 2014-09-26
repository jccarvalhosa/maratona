#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll solve(ll n) {
	int cnt=0;
	for(ll h=1;;h++) {
		ll m = 2*h + 3*h*(h-1)/2;
		if(m > n) break;
		if((n - m) % 3 == 0) cnt++;
	}
	return cnt;
}

int main() {
	ll n;
	cin>>n;
	cout << solve(n) << endl;
	return 0;
}
