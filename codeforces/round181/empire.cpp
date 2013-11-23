#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAXN 10000001
#define MAXK 1000001

int lp[MAXN], p[MAXN], a[MAXK], s;
ll c[MAXN], m[MAXN];

void sieve(int n) {
    int i, j;
	s=0;
	for(i=2;i<=n;i++) lp[i] = 1;
	for(i=2;i<=n;i++) if(lp[i] == 1) {
		p[s++] = lp[i] = i;
		for(j=i+i;j<=n;j+=i) lp[j] = i;
	}
}

void count(int n, int k) {
	int i;
	for(i=2;i<=n;i++) c[i] = m[i] = 0;
	for(i=0;i<k;i++) c[a[i]]++;
	for(i=n-1;i>=2;i--) c[i] += c[i+1];
	for(i=n;i>=2;i--) {
		m[lp[i]] += c[i];
		if(lp[i] != i) c[i/lp[i]] += c[i];
	}
}

ll sum(ll p, ll n) { return n==0 ? 0 : n%p + sum(p, n/p); }

ll mult(ll p, ll n) { return (n - sum(p, n))/(p-1); }

int valid(ll n) {
	if(n<=0) return 0;
	for(int i=0;i<s;i++) if(mult(p[i], n) < m[p[i]]) return 0;
	return 1;
}

ll lower_bound(ll i, ll f) {
	while(1) {
		ll m = (i+f)/2;
		if(valid(m)) {
			if(!valid(m-1)) return m;
			f = m-1;
		} else {
			if(valid(m+1)) return m+1;
			i = m+1;
		}
	}
}

int main() {
	int n=0, k, i;
	ll sum=0;
	cin>>k;
	for(i=0;i<k;i++) {
		cin>>a[i];
		sum += a[i];
		n = max(n, a[i]);
	}
    sieve(n);
	count(n, k);
	cout << lower_bound(1, sum) << endl;
    return 0;
}
