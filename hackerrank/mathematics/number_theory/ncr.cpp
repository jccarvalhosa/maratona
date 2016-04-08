#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int n, r;
const int M=142857;

ll exp(ll a, int e) {
	if(!e) return 1;
	if(e&1) return (a*exp(a,e-1))%M;
	return exp((a*a)%M, e/2);
}

ll inv(int x, int m) {	
	if(m==27) for(int i=1;i<27;i++) if((x*i)%m==1) return i;
	return exp(x, m-2)%m; 
}
ll coef(int v) { return inv(M/v, v) * (M/v); }

ll cont(int n, int p) {
	ll ans=0;
	while(n>=p) {
		ans += n/p;
		n/=p;
	}
	return ans;
}
ll cont(int n, int r, int x) { return cont(n, x) - cont(r, x) - cont(n-r, x); }

ll fat[40];
ll _mod(int n, int p) {
	if(n==0) return 1;
	return (((exp(fat[p-1], n/p) * fat[n%p])%p) * _mod(n/(p!=27?p:3), p))%p;
}
ll mod(int n, int p) {
	fat[0]=1;
	for(int i=1;i<p;i++) {
		if(p==27) {
			int j=i;
			if(j%3==0) j=1;
			fat[i] = (fat[i-1]*j)%p;
		}
		else fat[i] = (fat[i-1]*i)%p;
	}
	return _mod(n, p);
}

ll _mod(int n, int r, int x) { return (mod(n, x) * inv(mod(r, x), x) * inv(mod(n-r, x), x))%x; }
ll mod(int x) {
	int e=1;
	if(x==27) {
		int c = cont(n, r, 3);
		if(c>=3) return 0;
		return (exp(3, c)*_mod(n, r, x))%x;
	}
	if(cont(n, r, x) >= 1) return 0;
	return _mod(n, r, x);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &r);
		int v[] = {27, 11, 13, 37};
		ll ans=0;
		for(int i=0;i<4;i++) ans += (mod(v[i])*coef(v[i]))%M;
		printf("%lld\n", ans%M);
	}
	return 0;
}
