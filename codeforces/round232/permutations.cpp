#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int M=1e9+7;
const int N=1e6+10;
int p[N];

int t[N];
void add(int x, int v) { for(;x<N;x+=x&-x) t[x] += v; }
ll sum(int x) { ll ret=0; for(;x;x-=x&-x) ret += t[x]; return ret; }

ll fat[N], cont[N], total[N];

ll exp(ll a, ll e) {
	if(!e) return 1;
	if(e&1) return a*exp(a, e-1)%M;
	return exp(a*a%M, e/2);
}

ll inv(ll a) { return exp(a, M-2); }

int main() {
	ll n;
	cin>>n;
	fat[0]=1;
	for(int i=1;i<n;i++) fat[i] = fat[i-1]*i%M;
	ll i4 = inv(4);
	for(ll k=1;k<n;k++) total[k] = k*(k-1)%M*fat[k]%M*i4%M;
	for(int i=0;i<n;i++) scanf("%d", &p[i]);
	ll ans=0;
	cont[n] = 1;
	for(int i=n-1;i>=0;i--) {
		ll x = sum(p[i]);
		add(p[i], 1);
		cont[i] = (x*fat[n-i-1] + cont[i+1])%M;
	}
	for(int i=0;i<n-1;i++) {
		add(p[i], -1);
		ll x = sum(p[i]);
		ans = (ans + x*(x-1)/2%M*fat[n-i-1] + x*total[n-i-1] + x*cont[i+1])%M;
	}
	cout<<ans<<endl;
	return 0;
}
