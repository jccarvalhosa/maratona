#include <cstdio>
#include <iostream>
#include <algorithm>
#define M 1000000007
using namespace std;

int v[1010];
long long fat[1010], ans;

int exp(long long b, int e) {
	if(e==0) return 1;
	if(e%2==0) return exp((b*b)%M, e/2);
	return (b*exp(b, e-1))%M;
}

int inv(int a) { return exp(a, M-2); }

int main() {
	int t=0, n, m, i;
	fat[0]=1;
	cin>>n>>m;
	for(i=1;i<=n;i++) fat[i]=(fat[i-1]*i)%M;
	for(i=0;i<m;i++) cin>>v[i];
	sort(v, v+m);
	t=v[0]-1 + n-v[m-1];
	for(i=1;i<m;i++) t += v[i]-v[i-1]-1;
	ans=fat[t];
	ans = (ans * inv(fat[v[0]-1]))%M;
	ans = (ans * inv(fat[n-v[m-1]]))%M;
	for(i=1;i<m;i++) ans = (ans * inv(fat[v[i]-v[i-1]-1]))%M;
	for(i=1;i<m;i++) if(v[i]-v[i-1]>2) ans = (ans * exp(2, v[i]-v[i-1]-2))%M;
	cout<<ans<<endl;
	return 0;
}
