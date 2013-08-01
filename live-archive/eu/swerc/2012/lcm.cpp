#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll extgcd(ll a, ll b, ll &x, ll &y) {
	ll g = a;
	x = 1; y = 0;
	if (b) {
		g = extgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
	return g;
}

ll invMod(ll a, ll p) {
	ll x, y;
	if (extgcd(a,p,x,y) == 1) return (x+p)%p;
	return 0;
}

int p[15];
int a[15];
int C;
const int mod = 1000000007;
ll ans;
ll prod[15][52];
ll sum[15][52];

void solve(int now, ll x, ll xn, ll y, ll yn) {
	if (now == C) {
		ans += x * yn % mod + y * xn % mod;
		return;
	}
	solve(now+1,
			x * prod[now][a[now]] % mod,
			xn,
			y * sum[now][a[now]] % mod,
			yn * (a[now]+1) % mod);
	solve(now+1,
			x * sum[now][a[now]-1] % mod,
			xn * a[now] % mod,
			y * prod[now][a[now]] % mod,
			yn);
}

int main() {
	int T;
	cin >> T;
	for(int t=1;t<=T;t++) {
		cin >> C;
		ll n = 1;
		for(int i=0;i<C;i++) {
			cin >> p[i] >> a[i];
			prod[i][0] = 1;
			sum[i][0] = 1;
			for(int j=0;j<a[i];j++) {
				prod[i][j+1] = prod[i][j] * p[i] % mod;
				sum[i][j+1] = (sum[i][j] + prod[i][j+1]) % mod;
			}
			n = n * prod[i][a[i]] % mod;
		}
		ans = 0;
		solve(0,1,1,1,1);
		ans = (ans + n*2) % mod;
		ans = ans * invMod(2,mod) % mod;
		printf("Case %d: %lld\n", t, ans);
	}
}
