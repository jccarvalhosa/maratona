#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5;
const int M = 1e3;
double dp[2][N+1];

int main() {
	int n, k;
	cin>>n>>k;
	for(int i=0;i<=n;i++) dp[M&1][i] = M * i / 2 / k;
	for(int i=M-1;i>=1;i--) {
		dp[i&1][0] = 0;
		for(int j=1;j<=n;j++) {
			dp[i&1][j] = dp[i&1][j-1] * (k-1)/k + 1.0/k * ((dp[(i+1)&1][j-1] + i)/(i+1) + (dp[i&1][j-1] + (i+1)/2.0) * i / (i+1));
		}
	}
	printf("%.12lf\n", k * dp[1][n]);
	return 0;
}
