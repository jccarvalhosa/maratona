#include <bits/stdc++.h>
using namespace std;

long long dp[32][2][2][2];

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		int a, b, k;
		cin>>a>>b>>k;
		memset(dp, 0, sizeof(dp));
		dp[31][0][0][0]=1;
		for(int i=30;i>=0;i--) {
			for(int mask=0;mask<8;mask++) for(int va=0;va<=1;va++) for(int vb=0;vb<=1;vb++) {
				int ma = (mask & 1) != 0;
				int mb = (mask & 2) != 0;
				int mk = (mask & 4) != 0;
				int na = (a & (1<<i)) != 0;
				int nb = (b & (1<<i)) != 0;
				int nk = (k & (1<<i)) != 0;
				int vk = va & vb;
				if(!ma && (va > na)) continue;
				if(!mb && (vb > nb)) continue;
				if(!mk && (vk > nk)) continue;
				int newma = ma || (va < na);
				int newmb = mb || (vb < nb);
				int newmk = mk || (vk < nk);
				dp[i][newma][newmb][newmk] += dp[i+1][ma][mb][mk];
			}
		}
		printf("%lld\n", dp[0][1][1][1]);
	}
	return 0;
}
