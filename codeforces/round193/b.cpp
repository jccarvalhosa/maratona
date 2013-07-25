#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;

ll v[444444];
ll sum[444444], dp[444444];

int main() {
	int n, k, a, b;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>v[i];
	sum[0] = v[0];
	for(int i=1;i<k;i++) sum[0] += v[i];
	for(int i=1;i<n;i++) sum[i] = sum[i-1] + v[i+k-1] - v[i-1];
	dp[n-1] = sum[n-1];
	for(int i=n-2;i>=0;i--) dp[i] = max(dp[i+1], sum[i]);
	ll best=-INF;
	for(int i=0;i<n;i++) if(best < sum[i] + dp[i+k]) {
		best = sum[i] + dp[i+k];
		a=i;
	}
	for(int i=a+k;i<n;i++) if(best==sum[a] + sum[i]) {
		b = i;
		break;
	}
	cout<<a+1<<" "<<b+1<<endl;
	return 0;
}
