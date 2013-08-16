#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int sa[1111111], sb[1111111], ea[1111111], eb[1111111];
ll fibo[55];
int T, t, a, b, p, n;

pii fib(int n, int mod) {
	if(n==0) return pii(0, 1);
	pii p = fib(n/2, mod);
	ll a = p.first;
	ll b = p.second;
	int c = (((2*a*b - a*a) % mod) + mod)%mod;
	int d = (a*a + b*b) % mod;
	if(n%2 == 0) return pii(c, d);
	return pii(d, (c+d)%mod);
}

int solve() {
	if(n==1) return a;
	if(n==2) return b;
	if(a==0 || b==0) return 0;
	// ans = a**fib(n-2) * b**fib(n-1) % p
	ll xa = 1;
	int oa;
	for(int i=0;i<p;i++) sa[i] = sb[i] = -1;
	sa[1] = sb[1] = 0;
	for(oa=1;;oa++) {
		xa *= a;
		xa %= p;
		if(sa[xa] != -1) break;
		sa[xa] = oa;
		ea[oa] = xa;
	}
	ll xb = 1;
	int ob;
	for(ob=1;;ob++) {
		xb *= b;
		xb %= p;
		if(sb[xb] != -1) break;
		sb[xb] = ob;
		eb[ob] = xb;
	}
	ll va, vb;
	if(n<50 && fibo[n-2] < sa[xa]) va = ea[fibo[n-2]];
	else {
		int mod = oa - sa[xa];
		ll fa = (fib(n-2, mod).first - (sa[xa]%mod) + mod) % mod;
		va = ea[sa[xa] + fa];
	}
	if(n<50 && fibo[n-1] < sb[xb]) vb = eb[fibo[n-1]];
	else {
		int mod = ob - sb[xb];
		ll fb = (fib(n-1, mod).first - (sb[xb]%mod) + mod)%mod;
		vb = eb[sb[xb] + fb];
	}
	return ((va*vb)%p);
}

int main() {
	cin>>T;
	ea[0] = eb[0] = 1;
	fibo[0] = 0;
	fibo[1] = 1;
	for(int i=2;i<50;i++) fibo[i] = fibo[i-1] + fibo[i-2];
	for(t=1;t<=T;t++) {
		cin>>a>>b>>p>>n;
		a %= p;
		b %= p;
		printf("Case #%d: ", t);
		cout<<solve()<<endl;
	}
	return 0;
}
