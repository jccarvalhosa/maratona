#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define M 1000000007
typedef long long ll;

int cont[10];
ll dp[111][11], c[111][111];

int go(int l, int p) {
	if(p==10) return l==0;
	if(dp[l][p] != -1) return dp[l][p];
	dp[l][p] =0;
	for(int i=0;i<=cont[p];i++) {
		dp[l][p] += c[i][l] * go(l-i, p+1); 
		dp[l][p] %= M;
	}
	return dp[l][p];
}

int main() {
	for(int i=0;i<=81;i++) {
		c[0][i]=1;
		for(int j=1;j<=i;j++) c[j][i] = (c[j][i-1] + c[j-1][i-1])%M;
	}
	int T;
	cin>>T;
	while(T--) {
		for(int i=1;i<=9;i++) cin>>cont[i];
		ll ans=0;
		for(int i=1;i<=9;i++) if(cont[i]) {
			cont[i]--;
			memset(dp, -1, sizeof(dp));
			ll sum=0, pot=1;
			for(int l=0;l<=80;l++) {
				sum = (sum+pot)%M;
				pot = (pot*10)%M;
				ans += sum * i * go(l, 1);
				ans %= M;
			}
			cont[i]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
