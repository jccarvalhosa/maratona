#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=333;
ll dp[N][N];
int l[N][N];

int main() {
	int T;
	cin>>T;
	while(T--) {
		string a, b;
		cin>>a>>b;
		int A = a.size();
		int B = b.size();
		for(int i=0;i<=A;i++) dp[i][0]=1;
		for(int j=1;j<=B;j++) dp[0][j]=0;
		for(int i=0;i<=A;i++) l[i][0]=i;
		for(int i=1;i<=A;i++) for(int j=1;j<=B;j++) {
			dp[i][j]=dp[i-1][j];
			l[i][j]=l[i-1][j];
			if(a[i-1] == b[j-1]) {
				dp[i][j] += dp[i-1][j-1];
				l[i][j] = max(l[i][j], l[i-1][j-1]);
			}
		}
		cout << dp[A][B];
		if(dp[A][B] == 0) cout<<" -1"<<endl;
		else {
			int win=1e9;
			for(int i=1;i<=A;i++) if(dp[i][B] && a[i-1]==b[B-1]) win = min(win, i-l[i][B]);
			cout<<" "<<win<<endl;
		}
	}
	return 0;
}

