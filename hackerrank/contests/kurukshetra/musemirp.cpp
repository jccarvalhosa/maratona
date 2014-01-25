#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=1e6;
int primes[N], vis[N], nprimes=0;

int main() {
	primes[0]=2;
	nprimes=1;
	for(int i=4;i<N;i+=2) vis[i]=1;
	for(int i=3;i<N;i+=2) {
		if(!vis[i]) {
			primes[nprimes++]=i;
			for(int j=3*i;j<N;j+=i) vis[j]=1;
		}
	}
	int T;
	cin>>T;
	while(T--) {
		int x;
		cin>>x;
		int sum=0;
		for(int i=0;i<31;i++) {
			if(x & (1<<i)) sum+=primes[i];
		}
		cout<<sum<<endl;
	}

	return 0;
}
