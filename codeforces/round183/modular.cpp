#include <cstdio>
#include <iostream>
using namespace std;
#define M 1000000

int mod(int a) {return a>0?a:-a;}

int a[5000], p[M+1], vis[M+1];

int main() {
	int n, k, i, j, m, t;
	cin>>n>>k;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) for(j=i+1;j<n;j++) p[mod(a[i]-a[j])]++;
	for(m=1;m<=M;m++) {
		for(i=2;m*i<=M;i++) p[m] += p[m*i];
		if(p[m] > k*(k+1)/2) continue;
		t=0;
		for(i=0;i<n;i++) {
			if(vis[(a[i])%m]==m) t++; 
			vis[(a[i])%m]=m;
		}
		if(t<=k) break;
	}
	cout<<m<<endl;
	return 0;
}
