#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

// Crivo otimizado
const int MAXN = 10000001, SIZE = MAXN/16+1;
const int MAX_PRIMES = 685000; 
char mark[SIZE]; 
char is_prime[MAXN];
int primes[MAX_PRIMES], cnt_primes;
void sieve(int N=MAXN) {
	int i, j;
	for(i=3;i*i<=N;i+=2) if((mark[i>>4] & (1<<((i>>1)&7))) == 0) for(j=i*i;j<=N;j+=i<<1) mark[j>>4] |= (1<<((j>>1)&7));
	primes[0] = 2;
	cnt_primes = 1;
	for(i=3;i<=N;i+=2) if((mark[i>>4]&(1<<((i>>1)&7))) == 0) primes[cnt_primes++] = i;
	for(i=0;i<cnt_primes;i++) is_prime[primes[i]] = 1;
}

int main() {
	ll q;
	sieve();
	while(cin>>q && q) {
		ll ans = 2;
		int c=0;
		while(q % 2 == 0) {
			c++;
			q /= 2;
		}
		for(int i=1;i<cnt_primes;i++) {
			ll p = primes[i];
			if(p*p > q) break;
			if(q%p != 0) continue;
			int c=0;
			while(q % p == 0) {
				c++;
				q /= p;
			}
			ans *= (2*c+1);
		}
		if(q != 1) ans *= 3;
		cout<<ans<<endl;
	}
	return 0;
}
