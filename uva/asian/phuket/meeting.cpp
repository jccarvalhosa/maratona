#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int a, b;
		vector<pii> v;
		while(cin>>a>>b && (a||b)) v.push_back(pii(a, b));
		int dp[15] = {0};
		for(int i=10;i>=0;i--) {
			dp[i] = dp[i+1];
			int f=11;
			for(int j=0;j<v.size();j++) if(v[j].first == i) f = min(f, v[j].second);
			if(f != 11) dp[i] = max(dp[i], 1 + dp[f]);
		}
		cout<<dp[0]<<endl;
	}
	return 0;
}
