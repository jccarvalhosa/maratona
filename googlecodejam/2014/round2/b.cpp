#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N=1111;
int n, dp[N][N], bit[N];
pii v[N];

void add(int p, int v) { for(;p<=n;p+=p&-p) bit[p]+=v; }
int query(int p) { int ret=0; for(;p;p-=p&-p) ret+=bit[p]; return ret;}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>v[i].first;
			v[i].second=i;
		}
		sort(v+1, v+n+1);
		dp[0][0]=0;
		for(int i=1;i<=n;i++) bit[i]=0;
		for(int i=1;i<=n;i++) add(i, 1);
		for(int sum=1;sum<=n;sum++) {
			for(int i=0;i<=sum;i++) {
				int j = sum-i;
				dp[i][j]=1e9;
				if(i) dp[i][j] = min(dp[i][j], dp[i-1][j] + query(v[sum].second-1));
				if(j) dp[i][j] = min(dp[i][j], dp[i][j-1] + n-sum+1 - query(v[sum].second));
			}
			add(v[sum].second, -1);
		}
		int ans=1e9;
		for(int i=0;i<=n;i++) ans = min(ans, dp[i][n-i]);
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
