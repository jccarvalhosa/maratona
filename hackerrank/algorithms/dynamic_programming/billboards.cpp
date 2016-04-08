#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

const int N=(int)1e5+10;
ll sum[N], dp[N];

int main() {
	int n, k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>sum[i];
	for(int i=1;i<=n;i++) sum[i] += sum[i-1];
	multiset<ll> s;
	for(int i=1;i<=k;i++) {
		dp[i] = sum[i];
		s.insert(sum[i] - dp[i-1]);
	}
	for(int i=k+1;i<=n;i++) {    
		dp[i] = sum[i] - *s.begin();
		s.insert(sum[i] - dp[i-1]);
		s.erase(s.find(sum[i-k] - dp[i-k-1]));
	}
	cout << *max_element(dp, dp+n+1) << endl;
	return 0;
}
