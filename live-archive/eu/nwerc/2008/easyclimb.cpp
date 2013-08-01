#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;
#define INF 1000000000000000ll
typedef long long ll;
ll mod(ll a) { return a>0?a:-a; }

ll n,d;
ll h[111];
ll dp[111][22222];
ll pos[22222];

int main () {
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>h[i];
		if(mod(h[0]-h[n-1]) > (n-1)*d) {
			cout<<"impossible"<<endl;
			continue;
		}
		int m=0;
		for(int i=0;i<n;i++) for(int j=-n+1;j<=n-1;j++) pos[m++] = h[i] + d*j;
		sort(pos, pos+m);
		m = unique(pos, pos+m) - pos;
		for(int i=0;i<m;i++) dp[0][i] = pos[i]==h[0]?0:INF;
		for(int i=1;i<n;i++) {
			int p=0;
			for(int j=0;j<m;j++) {
				while(p<m && pos[p]<pos[j]-d) p++;
				while(p+1<m && pos[p+1]<=pos[j]+d && dp[i-1][p+1]<=dp[i-1][p]) p++;
				dp[i][j] = min(dp[i-1][p] + mod(pos[j]-h[i]), INF);
			}
		}
		for(int i=0;i<m;i++) if(pos[i]==h[n-1]) cout<<dp[n-1][i]<<endl;
	}
	return 0;   
}
