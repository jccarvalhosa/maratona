#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int a[5000], vis[1000001], f[1000001];

int mod(int a) { return a > 0 ? a : -a; }

int main() {
	int n, k, i, j, v, m=0, penal;
	cin>>n>>k;
	for(i=0;i<n;i++) cin>>a[i];
	memset(f, 0, sizeof(f));
	for(i=0;i<n;i++) for(j=i+1;j<n;j++) {
		v = mod(a[i]-a[j]);
		for(int k=1;k<=5;k++) if(v % k == 0) f[v/k]++;
	}
	for(m=1;;m++) {
		if(f[m] > k*(k+1)/2) continue;
		penal=0;
		for(i=0;i<m;i++) vis[i]=0;
		for(i=0;i<n;i++) {
			v = a[i]%m;
			if(!vis[v]) vis[v]=1;
			else {
				penal++;
				if(penal>k) break;
			}
		}
		if(penal<=k) break;
	}
	cout << m << endl;
	return 0;
}
