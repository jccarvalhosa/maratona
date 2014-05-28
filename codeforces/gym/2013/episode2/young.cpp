#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MAX = 1e18;

struct dlong {
	ll a, b;

	dlong(ll a=0, ll b=0) : a(a), b(b) {}

	void operator+= (dlong x) {
		a += x.a;
		b += x.b;
		if(a >= MAX) {
			a -= MAX;
			b++;
		}
	}
};

const int N = 1e3+1;

int v[N], m[N][N];
dlong dp[N][N];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++) {
		if(v[i] >= v[n-1]) m[i][n-1] = n;
		else m[i][n-1] = n-1;
		if(v[n-1] >= v[i]) m[n-1][i] = i+1;
		else m[n-1][i] = i;
	}
	for(int i=n-2;i>=0;i--) for(int j=n-2;j>=0;j--) {
		m[i][j] = j;
		if(v[i] >= v[j]) {
			if(v[i] > v[i+1]) m[i][j] = j+1;
			else m[i][j] = m[i+1][j+1];
		}
	}

	dp[n-1][n-1] = 1;
	for(int i=n-2;i>=0;i--) for(int j=i;j<n;j++) {
		dp[i][j] = 0;
		if(j>i) dp[i][j] = dp[i][j-1];
		if(j == n-1) {
			if(m[i][i] == n) dp[i][j] += 1;
		}
		else {
			int d = min(m[j+1][i]-i-1, j-i);
			if(d>=0) dp[i][j] += dp[j+1][j+1+d];
		}
	}
	dlong ans = dp[0][m[0][0]-1];
	if(ans.b == 0) cout << ans.a << endl;
	else printf("%I64d%018I64d\n", ans.b, ans.a);
	return 0;
}
