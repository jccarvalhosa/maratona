#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int M = 1e9+7;
const int N=2222;

int dp[N][N];

int main() {
	int n, k;
	cin>>n>>k;
	vector<int> d[N];
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) if(i % j == 0) d[i].push_back(j);
	for(int i=1;i<=n;i++) dp[i][1] = 1;
	for(int i=2;i<=k;i++) for(int j=1;j<=n;j++) {
		for(int jj=0;jj<d[j].size();jj++) dp[j][i] = (dp[j][i] + dp[d[j][jj]][i-1]) % M;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans = (ans + dp[i][k])%M;
	cout << ans << endl;
	return 0;
}
