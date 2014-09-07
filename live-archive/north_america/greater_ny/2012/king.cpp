#include <bits/stdc++.h>
using namespace std;

const int N=20;
//long long dp[(1<<N)+1][N][2];
long long ans[N+10]={1, 2, 4, 10, 32, 122, 544, 2770, 15872, 101042, 707584, 5405530, 44736512, 398721962, 3807514624, 38783024290, 419730685952, 4809759350882, 58177770225664, 740742376475050};

int main() {
	int t;
	scanf("%d", &t);
	/*for(int n=2; n<=N; n++) {
	  memset(dp, 0, sizeof(dp));
	  for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(i!=j) {
	  int flag=(i<j) ? 1 : 0;
	  dp[(1<<i)+(1<<j)][j][flag]=1;
	  }
	  for(int i=1; i<(1<<n); i++) {
	  for(int j=0; j<n; j++) if(i&(1<<j)) {
	  for(int k=0; k<n; k++) if(k!=j && (i&(1<<k))) {
	  if(j>k) dp[i][j][1]+=dp[i-(1<<j)][k][0];
	  else dp[i][j][0]+=dp[i-(1<<j)][k][1];
	  }
	  }
	  }
	  for(int i=0; i<n; i++) ans[n]+=dp[(1<<n)-1][i][0]+dp[(1<<n)-1][i][1];
	  }*/
	while(t--) {
		int T, n;
		scanf("%d %d", &T, &n);
		printf("%d %lld\n", T, ans[n-1]);
	}
	return 0;
}
