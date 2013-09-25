#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

map<pll, ll> vis;

ll go(ll n, ll i) {
	if(n==0) return (i==0);
	if(i==0) return 1;
	pll state(n, i);
	if(vis.count(state)) return vis[state];
	int pos = 63 - __builtin_clzll(n);
	ll a = 1ll<<pos;
	ll b = n - a;
	return vis[state] = go(b, i-1) + go(a-1, i);
}

int dp[66];

int main() {
	dp[1] = 0;
	for(int i=2;i<66;i++) dp[i] = 1 + dp[__builtin_popcount(i)];
	while(1) {
		ll a, b;
		int x;
		cin>>a>>b>>x;
		if(a==0 && b==0 && x==0) break;
		if(x == 0) {
			if(a <= 1 && 1 <= b) cout<<1<<endl;
			else cout<<0<<endl;
		}
		else {
			ll ans=0;
			for(int i=1;i<=64;i++) if(dp[i] == x-1) {
				ans += go(b, i) - go(a-1, i);
				if(i==1 && a <= 1 && 1 <= b) ans--;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
