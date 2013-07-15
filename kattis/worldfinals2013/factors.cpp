#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;
typedef long long ll;

ll best, prime[30];

void go(ll n, ll i, ll m, ll k, ll s) {
	ll d=1;
	if(n==1) best = min(best, k);
	else for(int j=1;j<=m;j++) {
		if(k*prime[i]/prime[i] != k) break;
		k *= prime[i];
		d = d*(s+j)/j;
		if(n%d==0) go(n/d, i+1, j, k, s+j);
	}
}

int main() {
	ll n=1;
	int i, j;
	for(i=2;;i++) {
		for(j=2;j<i;j++) if(i%j==0) break;
		if(j==i) prime[n++]=i;
		if(n==30) break;
	}
	while(scanf("%lld", &n) != EOF) {
		if(n==1) cout<<"1 2"<<endl;
		else {
			best = LLONG_MAX;
			go(n, 1, n, 1, 0);
			cout<<n<<" "<<best<<endl;
		}
	}
}
