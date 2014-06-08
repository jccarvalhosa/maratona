#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int k, n, t[10000];
const ll M = 1e9+7;

int main() {
	cin>>k>>n;
	for(int i=0;i<n;i++) cin >> t[i];
	if (k < n) {
		nth_element(t, t + k, t + n);
		cout << t[k] << endl;
		return 0;
	}
	k -= n - 1;
	ll a = 1;
	ll b = 0;
	for(int i=0;i<k;i++) {
		a += b;
		b = a - b;
		if (a > 1e9) break;
	}
	pair<ll, ll> best(0, 0);
	for(int i=0;i<n-1;i++) {
		ll x = max(t[i], t[i+1]);
		ll y = min(t[i], t[i+1]);
		if(a * x + b * y > a * best.first + b * best.second) best = make_pair(x, y);
	}
	ll x = best.first;
	ll y = best.second;
	for(int i=0;i<k;i++) {
		x += y;
		y = x - y;
		x %= M;
	}
	cout << x << endl;
}
