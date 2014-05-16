#include <bits/stdc++.h>
using namespace std;

const int N=7;
int k, n, dp[10][200], l[10], c[10];

int v1[10], v2[10];

int valid(int m1, int m2) {
	int n1=0, n2=0;
	for(int i=0;i<n;i++) if(m1 & (1<<i)) v1[n1++] = i;
	for(int i=0;i<n;i++) if(m2 & (1<<i)) v2[n2++] = i;
	for(int i=0;i<n1;i++) if(v1[i] < v2[i]) return 0;
	return 1;
}

int main() {
	while(cin>>k && !cin.eof()) {
		for(int i=0;i<k;i++) cin>>l[i];
		cin>>n;
		for(int j=0;j<N;j++) {
			c[j]=0;
			for(int i=0;i<k;i++) if(l[i] > j) c[j]++;
		}
		for(int i=0;i<1<<n;i++) dp[N-1][i] = __builtin_popcount(i) == c[N-1];
		for(int j=N-2;j>=0;j--) for(int i=0;i<1<<n;i++) {
			dp[j][i]=0;
			if(__builtin_popcount(i) == c[j]) {
				for(int ii=0;ii<1<<n;ii++) if(dp[j+1][ii] && valid(ii, i)) dp[j][i] += dp[j+1][ii];
			}
		}
		int ans=0;
		for(int i=0;i<1<<n;i++) ans += dp[0][i];
		cout << ans << endl;
	}
	return 0;
}
