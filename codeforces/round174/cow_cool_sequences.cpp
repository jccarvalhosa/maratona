#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll a[5000];
int dp[5000];

bool valid(ll x, ll y, int dist, int ord) {
	ll k = x >> ord;
	if(dist > ord) return y % k == 0;
	k = x >> dist;
	return y % (2*k) == k;
}

int main() {
	int n, i, j, best=0;
	cin >> n;
	for(i=0;i<n;i++) cin >> a[i]; 
	for(i=0;i<n;i++) {
		dp[i]=1;
		ll aux=a[i], ord=0;
		while(aux % 2 == 0) {
			aux /= 2;
			ord++;
		}
		for(j=0;j<i;j++) if(valid(a[i], a[j], i-j, ord)) dp[i] = max(dp[i], 1+dp[j]);
		best = max(best, dp[i]);
	}
	cout << n - best << endl;
	return 0;
}
