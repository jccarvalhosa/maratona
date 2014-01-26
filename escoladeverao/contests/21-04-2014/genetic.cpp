#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N=(int)1e6+10;

vector<int> pos[N];
int g[N], dp[N][2], p[N], DP[N], ppos[N];

int main() {
	int n, k;
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>g[i];
		ppos[i] = pos[g[i]].size();
		pos[g[i]].push_back(i);
	}
	for(int i=0;i<N;i++) p[i] = pos[i].size();
	for(int i=n-1;i>=0;i--) {
		p[g[i]]--;
		int np = p[g[i]] + k-1;
		if(p[g[i]] >= 0 && np < pos[g[i]].size()) {
			int pi = pos[g[i]][np]+1;
			dp[i][1] = max(dp[pi][0], dp[pi][1]) + k;
		}
		dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
	}
	for(int i=0;i<n;i++) {
		DP[i] = max(dp[i][0], dp[i][1]);
	}
	cout << DP[0] << endl;
	vector<int> ans;
	for(int i=0; i<n; ) {
		if(DP[i] == 0) break;
		int j, m = N, pm;
		for(j=i; DP[j]==DP[i]; j++) if(dp[j][1] == DP[j]) {
			if(g[j] < m) {
				m = g[j];
				pm = j;
			}
		}
		ans.push_back(m);
		i = pos[m][ppos[pm] + k-1]+1;
	}
	for(int i=0;i<ans.size();i++) for(int j=0;j<k;j++) {
		if(i==0 && j==0) cout<<ans[i];
		else cout << " " << ans[i];
	}
	cout<<endl;
	return 0;
}
