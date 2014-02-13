#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;

const ll M = 4294967143;
ll val[66][11][11];
unsigned int dp[66][11][11];

int main() {
	int T;
	cin>>T;
	for(int i=0;i<=10;i++) for(int j=0;j<=10;j++) val[0][i][j]=0;
	for(int i=0;i<=10;i++) val[0][i][i]=1;
	for(int i=1;i<64;i++) for(int a=0;a<=5;a++) for(int b=a;b<=10-a;b++) {
		ll ret=0;
		for(int m=0;m<10;m++) {
			ret += (val[i-1][a][m] * val[i-1][m+1][b])%M;
			ret += (val[i-1][a][m+1] * val[i-1][m][b])%M;
		}
		val[i][a][b] = val[i][b][a] = val[i][10-a][10-b] = val[i][10-b][10-a] = ret%M;
	}
	for(int t=1;t<=T;t++) {
		ll n, ans=0;
		scanf("%llu", &n);
		int old=-1;
		for(int i=0;i<64;i++) if(n & (1ull<<i)) {
			for(int a=0;a<=5;a++) for(int b=a;b<=10-a;b++) {
				if(old==-1) {
					dp[i][a][b] = dp[i][b][a] = dp[i][10-a][10-b] = dp[i][10-b][10-a] = val[i][a][b];
				}
				else {
					ll ret=0;
					for(int m=0;m<10;m++) {
						ret += (val[i][a][m] * dp[old][m+1][b])%M;
						ret += (val[i][a][m+1] * dp[old][m][b])%M;
					}
					dp[i][a][b] = dp[i][b][a] = dp[i][10-a][10-b] = dp[i][10-b][10-a] = ret%M;
				}
			}
			old=i;
		}
		for(int a=1;a<10;a++) ans += 2ull*dp[old][a][a+1];
		ans += dp[old][0][1];
		printf("%llu\n", ans%M);
	}
	return 0;
}
