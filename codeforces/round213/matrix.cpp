#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll sum[4444][4444], cont[111111];

int main() {
	string s;
	int a;
	cin>>a>>s;
	int n = s.size();
	for(int t=1;t<=n;t++) for(int i=0;i<n;i++) {
		int j = i+t-1;
		if(j>=n) break;
		if(i==j) sum[i][j] = s[i]-'0';
		else sum[i][j] = sum[i][j-1] + s[j]-'0';
	}
	for(int i=0;i<n;i++) for(int j=i;j<n;j++) cont[sum[i][j]]++;
	ll ans=0;
	if(a==0) ans += cont[0]*cont[0];
	for(ll i=1;i<=100000;i++) {
		if(a != 0 && i*i>a) break;
		if(a%i==0) {
			ll j = a/i;
			if(j>=100000) continue;
			ans += cont[i]*cont[j];
			if(i != j) ans += cont[i]*cont[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
