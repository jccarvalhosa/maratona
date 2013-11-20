#include <iostream>
#include <algorithm>
using namespace std;

int a[111111], dp[111111];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n<=2) cout<<n<<endl;
	else {
		dp[n-1]=1;
		dp[n-2]=2;
		for(int i=n-3;i>=0;i--) {
			dp[i] = 2;
			if(a[i]+a[i+1] == a[i+2]) dp[i] = 1 + dp[i+1];
		}
		cout << *max_element(dp, dp+n)<<endl;
	}
	return 0;
}
