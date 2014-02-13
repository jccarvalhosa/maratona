#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll fib[55];
const int N=2e7;
int prime[N], nprimes=0;
char vis[N];

int main() {
	prime[++nprimes] = 2;
	for(int i=2;i<N;i+=2) vis[i]=1;
	for(int i=3;i<N;i+=2) if(!vis[i]) {
		prime[++nprimes] = i;
		for(int j=i;j<N;j+=2*i) vis[j]=1;
	}
	fib[1]=0;
	fib[2]=1;
	for(int i=3;i<=50;i++) fib[i] = fib[i-1] + fib[i-2];
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		ll n, k, s, ans;
		cin>>n>>k>>s;
		ll x = fib[n] - k;
		ll y = prime[x] - s;
		if(y <= 0) ans=-1;
		else {
			ans=y;
			for(int i=1;;i++) {
				int p = prime[i];
				if(p*p > y) break;
				if(y%p==0) ans = ans/p*(p-1);
				while(y%p==0) y/=p;
			}
			if(y>1) ans = ans/y*(y-1); 
		}
		cout<<"CASE "<<t<<" : "<<ans<<endl;
	}
	return 0;
}

