#include <iostream>
#include <algorithm>
using namespace std;

const int N=1e5;
int nprimes, prime[N], vis[N], bad[N];
int n, m, a[N], e[N], p[N], g[N];

int val(int v) {
	int ans=0;
	int pos=0;
	for(int j=0;j<nprimes && prime[j]*prime[j] <= v;j++) {
		while(pos != m && bad[pos] < prime[j]) pos++;
		while(v % prime[j] == 0) {
			v /= prime[j];
			if(pos == m || bad[pos] != prime[j]) ans++;
			else ans--;
		}
	}
	if(v != 1) {
		while(pos != m && bad[pos] < v) pos++;
		if(pos == m || bad[pos] != v) ans++;
		else ans--;
	}
	return ans;
}

int main() {
	prime[0]=2;
	nprimes=1;
	for(int i=2;i<N;i+=2) vis[i] = 1;
	for(int i=3;i<N;i+=2) if(!vis[i]) {
		prime[nprimes++] = i;
		for(int j=i;j<N;j+=2*i) vis[j]=1;
	}
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>bad[i];
	sort(bad, bad+m);
	g[0] = a[0];
	for(int i=1;i<n;i++) g[i] = __gcd(g[i-1], a[i]);
	int delta=0;
	for(int i=n-1;i>=0;i--) {
		int v = (i+1)*val(g[i]);
		if(v < 0) {
			delta += v;
			for(int j=i-1;j>=0;j--) g[j] /= g[i];
		}
	}
	int ans=0;
	for(int i=0;i<n;i++) ans += val(a[i]);
	cout<<ans-delta<<endl;
	return 0;
}
