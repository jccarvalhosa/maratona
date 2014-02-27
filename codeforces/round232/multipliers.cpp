#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

const int N=1e5;
const int M=1e9+7;
ll primes[N], nprimes, vis[N];
ll fat[N];

ll exp(ll x, int e) {
	if(!e) return 1;
	if(e&1) return (x*exp(x, e-1))%M;
	return exp((x*x)%M, e/2);
}
ll inv(ll x) { return exp(x, M-2); }
ll comb(int j, int i) { return (fat[i] * inv((fat[j] * fat[i-j])%M))%M; }

map<int, int> pot;

int main() {
	for(int i=2;i<N;i++) if(!vis[i]) {
		primes[nprimes++]=i;
		for(int j=i;j<N;j+=i) vis[j]=1;
	}
	fat[0]=1;
	for(int i=1;i<N;i++) fat[i] = (fat[i-1]*i)%M;
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int a;
		cin>>a;
		for(int i=0;primes[i]*primes[i]<=a;i++) {
			while(a % primes[i] == 0) {
				a /= primes[i];
				pot[primes[i]]++;
			}
		}
		if(a != 1) pot[a]++;
	}
	ll ans=1;
	for(map<int, int>::iterator it=pot.begin();it!=pot.end();it++) {
		int x = (*it).second;
		ans = (ans * comb(x, x+n-1))%M;
	}
	cout<<ans<<endl;
	return 0;
}
