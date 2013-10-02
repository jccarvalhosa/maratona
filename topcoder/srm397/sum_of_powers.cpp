#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int M = 1000000007;

map<pii, int> vis;
int c[51][51];

int solve(int n, int k) {
	if(n==0) return 0;
	if(k==0) return n;
	pii state(n, k);
	if(vis.count(state)) return vis[state];
	ll ans=0;
	ll coef = (1ll<<k)%M;
	ans += coef * solve(n/2, k);
	ans %= M;
	for(int i=0;i<=k;i++) {
		coef = (1ll<<i)%M;
		coef = (coef*c[i][k])%M;
		ans += coef*solve((n-1)/2, i);
		ans %= M;
	}
	ans++; ans%=M;
	return vis[state] = ans;
}

struct SumOfPowers {
	int value(int n, int k) {
		for(int i=0;i<=k;i++) {
			c[0][i]=1;
			for(int j=1;j<=i;j++) c[j][i] = (c[j][i-1] + c[j-1][i-1])%M;
		}
		vis.clear();
		return solve(n, k);
	}
};

int main() {
	int n, k;
	cin>>n>>k;
	cout<<SumOfPowers().value(n, k)<<endl;
	return 0;
}
