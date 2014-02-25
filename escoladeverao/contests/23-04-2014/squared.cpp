#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string s;
const int N=1e3+10;
int n, dp[N][N];

int lcs(string a, string b) {
	int A = a.size(), B=b.size();
	for(int i=1;i<=A;i++) for(int j=1;j<=B;j++) {
		if(a[i-1]==b[j-1]) dp[i][j] = 1+dp[i-1][j-1];
		else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	}
	return dp[A][B];
}

int best(int i) {
	string a = s.substr(0, i);
	string b = s.substr(i);
	return lcs(a, b);
}

int solve() {
	if(n==1) return 1;
	if(n==2) return s[0]==s[1] ? 0 : 2;
	int i=0, f=s.size();
	while(i<f-2) {
		int m1 = i+(f-i)/3;
		int m2 = i+2*(f-i)/3;
		if(best(m1) < best(m2)) i=m1;
		else f=m2;
	}
	return n - 2*max(max(best(i), best(i+1)), best(i+2));
}

int main() {
	cin>>n;
	cin>>s;
	cout << solve() << endl;
	return 0;
}
