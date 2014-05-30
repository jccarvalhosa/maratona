#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int N=1e6;
int v[N];
ll ac[N];
ll mod(ll x) { return x>0 ? x : -x; }

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		scanf("%d", &v[i]);
		if(i&1) v[i] *= -1;
		if(!i) ac[i] = v[i];
		else ac[i] = ac[i-1] + v[i];
	}
	ll ans = 0, m=0, M=0;
	for(int i=0;i<n;i++) {
		ans = max(ans, mod(ac[i] - m));
		m = min(m, ac[i]);
		ans = max(ans, mod(ac[i] - M));
		M = max(M, ac[i]);
	}
	cout << ans << endl;
	return 0;
}
