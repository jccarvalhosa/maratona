#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

const int N=4100;
int dp[N];
pii back[N];
vector<int> match[N];

int main() {
	freopen("lz.in", "r", stdin);
	freopen("lz.out", "w", stdout);
	string s;
	cin>>s;
	int n = s.size();
	for(int i=0;i<n;i++) match[i].resize(n-i);
	for(int j=n-1;j>=0;j--) for(int i=j-1;i>=0;i--) {
		if(s[i] != s[j]) match[i][j-i]=0;
		else if(j==n-1) match[i][j-i]=1;
		else match[i][j-i] = 1 + match[i+1][j-i];
	}
	dp[0] = 9;
	for(int i=1;i<n;i++) dp[i]=1e9;
	for(int i=0;i<n-1;i++) {
		if(dp[i+1] > dp[i]+9) {
			dp[i+1] = dp[i]+9;
			back[i+1] = pii(i+1, -1);
		}
		for(int j=0;j<=i;j++) {
			int m = match[j][i-j+1];
			if(dp[i+m] > dp[i]+25) {
				dp[i+m] = dp[i]+25;
				back[i+m] = pii(i+1-j, m);
			}
		}
	}
	cout << dp[n-1] << endl;
	stack<pii> ans;
	int pos = n-1;
	while(pos > 0) {
		pii p = back[pos];
		ans.push(p);
		if(p.second == -1) pos--;
		else pos -= p.second;
	}
	cout << s[0];
	while(!ans.empty()) {
		pii p = ans.top();
		ans.pop();
		if(p.second == -1) cout << s[p.first];
		else cout << "(" << p.first << ","<<p.second<<")";
	}
	cout << endl;
	return 0;
}
