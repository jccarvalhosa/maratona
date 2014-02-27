#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=1e5;
const int M=1e9+7;
ll primes[N], nprimes, vis[N];

int isprime(ll a) {
	if(a == 1) return 0;
	for(int i=0;primes[i]*primes[i]<=a;i++) if(a % primes[i] == 0) return 0;
	return 1;
}

int main() {
	for(int i=2;i<N;i++) if(!vis[i]) {
		primes[nprimes++]=i;
		for(int j=i;j<N;j+=i) vis[j]=1;
	}
	int T;
	cin>>T;
	while(T--) {
		ll n;
		cin>>n;
		ll p1, p2;
		for(p1=n;;p1--) if(isprime(p1)) break;
		for(p2=p1+1;;p2++) if(isprime(p2)) break;
		ll den = 2*p1*p2;
		ll num = p1*p2 - 2*p2;
		num += 2*(n-p1+1);
		ll g = __gcd(num, den);
		cout << num/g << "/" << den/g << endl;
	}
	return 0;
}
