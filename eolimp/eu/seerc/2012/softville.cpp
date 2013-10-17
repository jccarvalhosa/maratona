#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ull;
#define INF 1ull<<63

int overflow;

ull lcm(ull a, ull b) {
	ull v = a/__gcd(a, b);
	if(v*b/b!=v) overflow=1;
	return v*b;
}

ull solve() {
	int n;
	cin>>n;
	vector<ull> v(n);
	ull m=1;
	for(int i=0;i<n;i++) {
		cin>>v[i];
		m = lcm(m, v[i] % 2 ? v[i] : v[i]/2);
		if(overflow) return 0;
	}
	for(int i=0;i<n;i++) if(v[i]%2==0 && (m%v[i]) == 0) return 0;
	ull vmin=0;
	int flag=0;
	for(int i=0;i<n;i++) {
		if(v[i]%2) {
			ull p = (v[i]+1)/2*v[i];
			if(p/v[i] != (v[i]+1)/2) return 0;
			vmin = max(vmin, p);
		} else {
			flag=1;
			ull p = v[i]/2*(v[i]+1);
			if(p/(v[i]+1) != v[i]/2) return 0;
			vmin = max(vmin, p);
		}
	}
	ull N = vmin/m*m;
	if(N < vmin) N += m;
	if(N >= INF) return 0;
	if(!flag) return N;
	if(N/m % 2) return N;
	N += m;
	if(N >= INF) return 0;
	return N;
}

int main() {
	cout << solve() << endl;
	return 0;
}
