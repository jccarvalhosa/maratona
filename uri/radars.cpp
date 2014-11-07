#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1e6+1;
int dp[N], pos[N], v[N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, k, j=0;
		scanf("%d%d", &n, &k);
		for(int i=1;i<=n;i++) scanf("%d", &pos[i]);
		for(int i=1;i<=n;i++) scanf("%d", &v[i]);
		for(int i=1;i<=n;i++) {
			while(pos[i]-pos[j+1] >= k) j++;
			dp[i] = max(dp[i-1], v[i]+dp[j]);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
