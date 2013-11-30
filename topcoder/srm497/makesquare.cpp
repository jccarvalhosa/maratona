#include <string>
#include <algorithm>
using namespace std;

int dp[55][55];

struct MakeSquare {
	int minChanges(string s) {
		int n = s.size();
		int ans=1<<30;
		for(int ii=0;ii<=n;ii++) {
			string a = s.substr(0, ii);
			string b = s.substr(ii);
			for(int i=0;i<=b.size();i++) dp[0][i]=i;
			for(int i=0;i<=a.size();i++) dp[i][0]=i;
			for(int i=1;i<=a.size();i++) for(int j=1;j<=b.size();j++) dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1] + (int)(a[i-1]!=b[j-1])));
			ans = min(ans, dp[a.size()][b.size()]);
		}
		return ans;
	}
};
