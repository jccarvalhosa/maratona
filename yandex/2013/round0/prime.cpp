#include <iostream>
using namespace std;

const int M = 40010;

int prime[M], vis[M];

int main() {
	int n, i, j;
	cin>>n;
	for(i=2;i<M;i++) {
		if(!vis[i]) {
			prime[i]=1;
			for(j=2*i;j<M;j+=i) vis[j]=1;
		}
	}
	for(i=2;i<=n;i++) if(prime[i+1] && prime[i-1]) cout<<i<<endl;
	return 0;
}
