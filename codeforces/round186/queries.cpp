#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int dp[100001];

int main() {
	int n, i, l, r;
	string s;
	cin>>s;
	n = s.size();
	for(i=1;i<=n;i++) {
		dp[i] = dp[i-1];
		if(s[i]==s[i-1]) dp[i]++;
	}
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>l>>r;
		cout<<dp[r-1]-dp[l-1]<<endl;
	}
	return 0;
}
