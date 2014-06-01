#include <bits/stdc++.h>
using namespace std;
	
int n, t=1;
const int N=3e5;
char s[111];
int dp[N][20], vis[N][20];

int mod(int x) { return x > 0 ? x : -x; }

int cost(char a, char b) {
	int c = a-b;
	if(c < 0) c += 26;
	return 1 + min(c, 26-c);
}

int go(int mask, int pp, int pos, int sz) {
	if(sz == n) return 0;
	if(vis[mask][pos] == t) return dp[mask][pos];
	vis[mask][pos]=t;
	dp[mask][pos] = 1e9;
	int npos=0;
	for(int i=0;i<n;i++) {
		if(mask & (1<<i)) {
			npos++;
		}
		else {
			dp[mask][pos] = min(dp[mask][pos], go(mask|(1<<i), i, npos+1, sz+1) + mod(pos-npos) + cost(s[pp], s[i]));
		}
	}
	return dp[mask][pos];
}

int main() {
	string aux;
	while(scanf("%s", s) && s[0] != '0') {
		n = strlen(s);
		int ans=1e9;
		for(int i=0;i<n;i++) ans = min(ans, cost('A', s[i]) + go(1<<i, i, 1, 1));
		cout << ans << endl;
		t++;
	}
	return 0;
}
