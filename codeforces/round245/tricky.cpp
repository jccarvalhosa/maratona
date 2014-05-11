#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
const int N=1e5+10;
int v[N], ac[N];

ll sq(ll x) { return x*x; }

int main() {
	cin>>n;
	int nn = sqrt(n);
	for(int i=0;i<n;i++) scanf("%d", &v[i]);
	ac[0] = v[0];
	for(int i=1;i<n;i++) ac[i] = ac[i-1] + v[i];
	map<ll, int> m;
	m[ac[0]] = 0;
	ll ans = 1e18 + 1e17;
	for(int i=1;i<n;i++) {
		for(int j=i-1;j>=0 && j>=i-nn;j--) ans = min(ans, sq(ac[i]-ac[j]) + sq(i-j));
		for(map<ll, int>::iterator it = m.lower_bound(ac[i]); it != m.end(); it++) {
			ll diff = sq((*it).first - ac[i]);
			if(diff >= ans) break;
			ans = min(ans, diff + sq((*it).second - i));
		}
		for(map<ll, int>::iterator it = m.lower_bound(ac[i]); ; it--) {
			if(it == m.begin()) break;
			it--;
			ll diff = sq((*it).first - ac[i]);
			if(diff >= ans) break;
			ans = min(ans, diff + sq((*it).second - i));
		}
		m[ac[i]] = i; 
	}
	cout << ans << endl;
	return 0;
}
