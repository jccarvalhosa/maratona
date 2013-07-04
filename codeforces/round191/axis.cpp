#include <iostream>
#define M 1000000007
using namespace std;

int a[2], sum[1<<24], dp[1<<24], v[1<<24];

int main() {
	int n, k, i, j;
	cin>>n;
	for(i=0;i<n;i++) cin>>v[1<<i];
	cin>>k;
	for(i=0;i<k;i++) cin>>a[i];
	dp[0]=1;
	for(i=1;i<1<<n;i++) {
		sum[i] = sum[i-(i&-i)] + v[i&-i];
		if(sum[i]>M) sum[i]=M;
		if(sum[i]==a[0] || sum[i]==a[1]) continue; 
		for(j=i;j;j-=j&-j) {
			dp[i] += dp[i-(j&-j)];
			if(dp[i] > M) dp[i]-=M;
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}
