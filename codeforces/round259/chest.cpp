#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int a[111], nprimes, vis[60], mask[60], dp[101][200000];

int mod(int x) { return x > 0 ? x : -x; }

int main() {
	for(int i=2;i<60;i++) {
		if(!vis[i]) {
			for(int j=i;j<60;j+=i) {
				vis[j]=1;
				mask[j] += 1<<nprimes;
			}
			nprimes++;
		}
	}
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++) for(int j=0;j<1<<nprimes;j++) dp[i][j]=1e9;
	for(int j=0;j<1<<nprimes;j++) dp[n][j]=0;
	for(int i=n-1;i>=0;i--) 
		for(int v=1;v<2*a[i];v++) 
			for(int avail=0;avail<1<<nprimes;avail++) 
				if((mask[v] & avail) == mask[v]) 
					dp[i][avail] = min(dp[i][avail], mod(v - a[i]) + dp[i+1][avail - mask[v]]);

	int avail = (1<<nprimes)-1;
	
	for(int i=0;i<n;i++) {
		int v;
		for(v=1;v<60;v++) {
			if((avail & mask[v]) != mask[v]) continue;
			if(dp[i][avail] == mod(v - a[i]) + dp[i+1][avail - mask[v]]) break;
		}
		cout << v << " ";
		avail -= mask[v];
	}
	cout << endl;
	return 0;
}
