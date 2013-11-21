#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, k, v[2222], dp[2222];
int mod(int a) { return a>0?a:-a; }

int valid(ll d) {
	dp[1] = 0;
	for(int i=2;i<=n;i++) {
		dp[i] = i-1;
		for(int j=i-1;j>=1;j--) if(mod(v[i]-v[j]) <= (i-j)*d) dp[i] = min(dp[i], i-j-1 + dp[j]);
		if(dp[i] + n-i <= k) return 1;
	}
	return 0;
}

int search() {
	if(valid(0)) return 0;
	if(k >= n-1) return 0;
	ll i=0, f=(ll)3e9;
	while(i<f-1) {
		ll m=(i+f)/2;
		if(valid(m)) f=m;
		else i=m;
	}
	return f;
}

int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>v[i];
	cout<<search()<<endl;
	return 0;
}
