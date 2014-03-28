#include <cstdio>
#include <cstring>

int M=1e9+7;

const int N=1e6+10;
char s[N];
int dp[N][3];

int equal(int p, char c) { return s[p] == c || s[p]=='?'; }

int main() {
	scanf("%s", s);
	int n = strlen(s);
	if(equal(0, '0')) dp[0][0]=1;
	if(equal(0, '1')) dp[0][1]=1;
	if(equal(0, '*')) dp[0][2]=1;
	for(int i=1;i<n;i++) {
		if(equal(i, '0')) {
			dp[i][0] = (dp[i][0] + dp[i-1][0])%M;
		}
		if(equal(i, '1')) {
			dp[i][1] = (dp[i][1] + dp[i-1][0])%M;
			dp[i][0] = (dp[i][0] + dp[i-1][2])%M;
		}
		if(equal(i, '2')) {
			dp[i][1] = (dp[i][1] + dp[i-1][2])%M;
		}
		if(equal(i, '*')) {
			dp[i][2] = (dp[i-1][1] + dp[i-1][2])%M;
		}
	}
	printf("%d\n", (dp[n-1][0] + dp[n-1][2])%M);
	return 0;
}
