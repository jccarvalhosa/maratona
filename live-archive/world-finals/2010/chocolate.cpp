#include <bits/stdc++.h>
using namespace std;
	
int T=1, n, v[40000], vis[40000][101], dp[40000][101];

int go(int mask, int x, int sum) {
	if(x==1) return 1;
	if(sum%x != 0) return 0;
	if(vis[mask][x] == T) return dp[mask][x];
	int y = sum/x;
	if(vis[mask][y] == T) return dp[mask][y];
	int cnt = __builtin_popcount(mask);
	if(cnt==1) return 1;
	for(int i=1;i<(1<<cnt)-1;i++) {
		int aux = mask;
		int nsum=0, nmask=0, pos=0;
		for(int aux=mask;aux;aux-=aux&-aux) {
			int j = aux&-aux;
			if((1<<pos) & i) {
				nsum += v[j];
				nmask += j;
			}
			pos++;
		}
		if(go(nmask, x, nsum) && go(mask - nmask, x, sum - nsum)) {
			vis[mask][x]=T;
			return dp[mask][x]=1;
		}
		if(go(nmask, y, nsum) && go(mask - nmask, y, sum - nsum)) {
			vis[mask][x]=T;
			return dp[mask][x]=1;
		}
	}
	vis[mask][x]=T;
	return dp[mask][x]=0;
}

int main() {
	while(cin>>n && n) {
		int x, y;
		cin>>x>>y;
		int sum=0;
		for(int i=0;i<n;i++) {
			cin>>v[1<<i];
			sum += v[1<<i];
		}
		printf("Case %d: %s\n", T++, sum==x*y && go((1<<n)-1, x, sum) ? "Yes" : "No");
	}
	return 0;
}
