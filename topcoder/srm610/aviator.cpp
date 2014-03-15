#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

int dp[55][5555];

struct AlbertoTheAviator {
	int MaximumFlights(int F, vector<int> d, vector<int> r) {
		int n = d.size();
		vector<pii> v(n);
		for(int i=0;i<n;i++) v[i] = pii(r[i], d[i]);
		sort(v.begin(), v.end());
		for(int i=1;i<=n;i++) for(int f=0;f<=F;f++) {
			dp[i][f]=dp[i-1][f];
			if(v[i-1].second <= f) {
				dp[i][f] = max(dp[i][f], 1 + dp[i-1][f - v[i-1].second + v[i-1].first]);
			}
		}
		return dp[n][F];
	}
};
