#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1111][255];

int main() {
	string s;
	cin>>s;
	for(int i=s.size()-1;i>=0;i--) {
		for(int j=0;;j++) {
			if(i+2*j+1 > s.size()) break;
			dp[i][s[i]] = max(dp[i][s[i]], 1+dp[i+2*j+1][s[i]]);
		}
	}
	int ans=0;
	for(int i=0;i<s.size();i++) for(char c='A';c<='Z';c++) ans = max(ans, dp[i][c]);
	cout<<ans<<endl;
	return 0;
}
