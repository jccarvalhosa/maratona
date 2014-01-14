#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
const int M = (int)1e9+7;

ll solve(vector<int> v, int x) {
	int t=1;
	sort(v.begin(),v.end());
	while(2*t <= v[n-1]+1) t *= 2;
	if(x >= 2*t) return 0;
	ll ans=0, dp[111][2]={0};
	dp[0][0] = 1;
	for(int i=0;i<n-1;i++) for(int j=0;j<2;j++)	{
		dp[i+1][j] += dp[i][j]*min(v[i]+1,t);
		dp[i+1][j] %= M;
		dp[i+1][j^1] += dp[i][j]*max(v[i]-t+1,0);
		dp[i+1][j^1] %= M;
	}
	if(x >= 0 && x < t) ans = dp[n-1][0];
	else ans = dp[n-1][1];
	if(v[n-1] >= t) {
		v[n-1] -= t;
		ans += solve(v,x^t);
		ans %= M;
	}
	return ans;
}

int main() {
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	ll ans = solve(v,0);
	for(int i=0;i<n;i++) v[i]--;
	cout<<(ans + M - solve(v,0))%M<<endl;
	return 0;
}
