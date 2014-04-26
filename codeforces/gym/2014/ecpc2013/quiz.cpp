#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

const int M=1e9+7;
int dp[1111][1111];

int main() {
	int T;
	freopen("rooks.in", "r", stdin);
	cin>>T;
	for(int t=1;t<=T;t++) {
		set<int> rows, cols;
		int n, m, k;
		cin>>n>>m>>k;
		for(int i=0;i<k;i++) {
			int x, y;
			cin>>x>>y;
			rows.insert(x);
			cols.insert(y);
		}
		int a = rows.size();
		int b = cols.size();
		int nn = m;
		if(a < b) {
			swap(a, b);
			nn = n;
		}
		for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) dp[i][j]=0;
		dp[a][b] = 1;
		for(int i=a;i>=1;i--) for(int j=b;j>=0;j--) {
			if(j) dp[i-1][j-1] = (dp[i-1][j-1] + 1ll * j * dp[i][j]) % M;
			dp[i-1][j] = (dp[i-1][j] + 1ll * (nn-j) * dp[i][j]) % M;
		}
		cout << "Case "<<t<<": "<<a<<" "<<dp[0][0]<<endl;
	}
	return 0;
}
