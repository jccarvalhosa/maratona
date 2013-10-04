#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int M = 1000000007;

ll dp[1111], c[1111][1111];

ll exp(ll a, ll e) {
	if(e==0) return 1;
	if(e%2) return (a*exp(a, e-1))%M;
	return exp((a*a)%M, e/2);
}

ll inv(ll a) { return exp(a, M-2); }

struct SumOfPowers {
	int value(int n, int k) {
		for(int i=0;i<=k+1;i++) {
			c[0][i]=1;
			for(int j=1;j<=i;j++) c[j][i] = (c[j][i-1] + c[j-1][i-1])%M;
		}
		dp[0] = n;
		for(int i=1;i<=k;i++) {
			dp[i] = (exp(n+1, i+1) - 1 + M) % M;
			for(int j=2;i-j+1>=0;j++) {
				dp[i] -= c[j][i+1]*dp[i-j+1];
				dp[i] %= M;
				dp[i] += M;
				dp[i] %= M;
			}
			dp[i] *= inv(c[1][i+1]);
			dp[i] %= M;
		}
		return dp[k];
	}
};

int main() {
	int n, k;
	cin>>n>>k;
	cout<<SumOfPowers().value(n, k)<<endl;
	return 0;
}
