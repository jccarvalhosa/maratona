#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

const int M = (int)1e9+7;
int v[11], n;
ll dp[11][111][1111], fat[222], finv[222];

ll exp(ll x, int e) {
	if(!e) return 1;
	if(e&1) return (x*exp(x, e-1))%M;
	return exp((x*x)%M, e/2);
}
ll inv(ll x) { return exp(x, M-2); }

int solve() {
	for(int i=0;i<10;i++) for(int j=0;j<=n;j++) for(int k=0;k<=sum;k++) dp[i][j][k]=0;
	int sum=0;
	for(int i=0;i<10;i++) sum += v[i]*i;
	dp[9][0][0]=1;
	for(int i=0;i<=v[9];i++) {
		ll val=fat[n-v[i]];
		for(int j=0;j<10;j++) if(j!=i) val = (val*finv[v[j]])%M;
		dp[9][i][9*i]=val;
	}
	for(int i=8;i>=0;i--) for(int j=0;j<=v[i];j++) {

	}
	int ans=0;
	for(int sp=sum%11;sp<=sum;sp+=11) ans = (ans+dp[0][n/2][sp])%M;
	return ans;
}

int main() {
	string s;
	fat[0]=finv[0]=1;
	for(int i=1;i<200;i++) {
		fat[i]=(fat[i-1]*i)%M;
		finv[i] = inv(fat[i]);
	}
	while(cin>>s && !cin.eof()) {
		for(int i=0;i<10;i++) v[i]=0;
		n = s.size();
		for(int i=0;i<n;i++) v[s[i]-'0']++;
		int ans=solve();
		if(v[0]) {
			v[0]--;	n--;
			ans += M-solve();
			ans%=M;
		}
		cout<<ans<<endl;
	}
	return 0;
}
