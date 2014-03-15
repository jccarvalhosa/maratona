#include <iostream>
#include <algorithm>
using namespace std;
	
int n, b;
const int N=1e5+10;
const int INF=1e9;

int v[N], sum[N], dp[N];

int main() {
	freopen("mooomoo.in", "r", stdin);
	freopen("mooomoo.out", "w", stdout);
	cin>>n>>b;
	for(int i=0;i<b;i++) cin>>v[i];
	for(int i=1;i<N;i++) dp[i]=INF;
	for(int i=0;i<b;i++) for(int j=v[i];j<N;j++) dp[j] = min(dp[j], dp[j-v[i]]+1);
	for(int i=0;i<n;i++) cin>>sum[i];
	for(int i=n-1;i>0;i--) sum[i] -= max(0, sum[i-1]-1);
	int i=0, ans=0;
	for(i=0;i<n;i++) {
		if(dp[sum[i]] == INF) break;
		ans += dp[sum[i]];
	}
	if(i!=n) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
