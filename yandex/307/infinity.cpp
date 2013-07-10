#include <iostream>
using namespace std;
typedef long long ll;

ll mod(ll x) { return x>0?x:-x;}
ll mdc(ll a, ll b) { return b?mdc(b, a%b):a;}

struct frac {
	ll n, d;
	frac(ll x=0, ll y=1) {
		if(x==0) { n=0; d=1; }
		else {
			int sign=1;
			if(x/mod(x) != y/mod(y)) sign=-1;
			x = mod(x); y = mod(y);
			ll m = mdc(x, y);
			n = sign*x/m;
			d = y/m;
		}
	}
	frac operator+(frac f) { return frac(n*f.d+f.n*d, d*f.d); }
	frac operator-(frac f) { return frac(n*f.d-f.n*d, d*f.d); }
	frac operator*(frac f) { return frac(n*f.n, d*f.d); }
	frac operator/(frac f) { return frac(n*f.d, d*f.n); }
};
	
ll c[11][11];

int main() {
	int a, b, i, j;
	frac dp[11];
	cin>>a>>b;
	if(b==1) {
		cout<<"infinity"<<endl;
		return 0;
	}
	for(i=0;i<=10;i++) {
		c[0][i]=1;
		for(j=1;j<=i;j++) c[j][i] = c[j][i-1]+c[j-1][i-1];
	}
	dp[0] = frac(1, b-1);
	for(i=1;i<=a;i++) {
		for(j=0;j<i;j++) dp[i] = dp[i] + dp[j]*c[j][i];
		dp[i] = (dp[i]+1)/(b-1);
	}
	cout<<dp[a].n<<"/"<<dp[a].d<<endl;
	return 0;
}
