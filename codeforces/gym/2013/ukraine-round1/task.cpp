#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define M 1000000007

ll mod(ll a) { return (a%M + M)%M; }
ll mdc(ll a, ll b) { return !b?a:mdc(b, a%b); }
ll mmc(ll a, ll b) { return a*(b/mdc(a, b)); }

ll sum(ll a, ll n) { 
    ll m = n/a;
    if(n%a == 0) m--;
	if(m%2 == 0) return mod(mod(mod(a) * mod(m/2)) * mod(m+1));
	return mod(mod(mod(a) * mod(m)) * mod((m+1)/2));
}

int main() {
    ll n, a, b, s1, s2;
    cin>>n>>a>>b;
    s1=mod(sum(a, n) + sum(b, n));
    ll gcd=mdc(a, b);
    if((double)b/gcd > (double)n/a) s2=0;
    else s2=sum(mmc(a, b), n);
    cout << mod(s1 - s2) << endl;
    return 0;
}
