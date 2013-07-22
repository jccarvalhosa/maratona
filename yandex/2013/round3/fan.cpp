#include <iostream>
#include <algorithm>
#define MOD 1000200013
using namespace std;
typedef long long ll;

int c[2222][2222];

int main() {
	int n, k, h[10], p[10], x[10], cont[10];
	cin>>n>>k;
	for(int i=0;i<k;i++) cin>>h[i];
	for(int i=0;i<k;i++) p[i]=i;
	for(int i=0;i<=2*n;i++) {
		c[0][i]=1;
		for(int j=1;j<=i;j++) c[j][i] = (c[j][i-1] + c[j-1][i-1])%MOD;
	}
	int ans=0;
	do {
		int s=0;
		for(int i=0;i<k;i++) cont[i]=1;
		for(int i=1;i<k;i++) s += 1+max(0, h[p[i]] - h[p[i-1]]);
		if(s<=n-1) ans = (ans + c[k][n-s+k-1])%MOD;
	} while(next_permutation(p, p+k));
	cout<<ans<<endl;
	return 0;
}
