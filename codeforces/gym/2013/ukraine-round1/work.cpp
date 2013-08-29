#include <iostream>
#include <string>
using namespace std;

int prime[33333], dp[33333];
int ly[33333], ry[33333], ln[33333], rn[33333];

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=2;i<=n;i++) prime[i]=1;
	for(int i=2;i<=n;i++) if(prime[i]) for(int j=2*i;j<=n;j+=i) prime[j]=0;
	string s;
	cin>>s;
	ry[n] = rn[n] = n+1;
	for(int i=n-1;i>=1;i--) {
		if(prime[i+1]) {
			ry[i] = i+1;
			rn[i] = rn[i+1];
		}
		else {
			ry[i] = ry[i+1];
			rn[i] = i+1;
		}
	}
	ly[1] = ln[1] = 0;
	for(int i=2;i<=n;i++) {
		if(prime[i-1]) {
			ly[i] = i-1;
			ln[i] = ln[i-1];
		}
		else {
			ly[i] = ly[i-1];
			ln[i] = i-1;
		}
	}
	if(s[m-1]=='Y') {
		if(prime[n]==1) dp[m-1] = n;
		else dp[m-1] = ly[n];
	}
	if(s[m-1]=='N') {
		if(prime[n]==0) dp[m-1] = n;
		else dp[m-1] = ln[n];
	}
	for(int i=m-2;i>=0;i--) {
		if(s[i]=='Y') dp[i] = ly[dp[i+1]];
		else dp[i] = ln[dp[i+1]];
	}
	int pos, ans=0;
	if(s[0]=='Y') pos=2;
	else pos=1;
	for(int i=0;i<m-1;i++) {
		if(s[i]=='Y' && dp[i+1] <= ry[pos]) ans++;
		if(s[i]=='N' && dp[i+1] <= rn[pos]) ans++;
		if(s[i+1]=='Y') pos = ry[pos];
		else pos = rn[pos];
	}
	if(s[m-1]=='Y' && ry[pos]==n+1) ans++;
	if(s[m-1]=='N' && rn[pos]==n+1) ans++;
	cout<<ans<<endl;
	return 0;
}
