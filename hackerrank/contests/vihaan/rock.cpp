#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=1e5+10;
int v[N];
ll dp[N];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		for(int i=0;i<n;i++) scanf("%d", &v[i]);
		reverse(v, v+n);
		dp[1] = v[0];
		dp[2] = v[0] + v[1];
		dp[3] = v[0] + v[1] + v[2];
		for(int i=4;i<=n;i++) {
			dp[i]=0;
			dp[i] = max(dp[i], v[i-1] + dp[max(0, i-2)]);
			dp[i] = max(dp[i], v[i-1] + v[i-2] + dp[max(0, i-4)]);
			dp[i] = max(dp[i], v[i-1] + v[i-2] + v[i-3] + dp[max(0, i-6)]);
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
