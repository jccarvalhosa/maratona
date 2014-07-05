#include <algorithm>
#include <iostream>
using namespace std;

int dp[401][401][401];

int main() { 
	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<=n;i++) for(int a=0;a<=n;a++) for(int b=0;b<=n;b++) dp[i][a][b] = 1e9;
	for(int i=n-1;i>=0;i--) for(int a=0;a<n;a++) for(int b=a;b<n;b++) {
		int aa=a, bb=b;
		if(s[i] == s[a]) aa++;
		if(s[i] == s[b]) bb--;
		if(aa > bb) dp[i][a][b] = 1;
		else dp[i][a][b] = 1 + dp[i+1][aa][bb];
		dp[i][a][b] = min(dp[i][a][b], dp[i+1][a][b]);
	}
	cout << dp[0][0][n-1] << endl;
	return 0;
}
