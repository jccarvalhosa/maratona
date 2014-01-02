#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int k, vis[101][101][1001];
double dp[101][101][1001];
double ps, pr, pi, pu, pw, pd, pl;
int t, PI, PU, PD;

double go(int a, int b, int psun) {
	if(a==k) return 1;
	if(b==k) return 0;
	if(vis[a][b][psun] == t) return dp[a][b][psun];
	
	double ans=0, p = psun/1000.0;

	ans += p * ps * pw * go(a+1, b, min(1000, psun + PU));
	ans += p * ps * (1-pw) * go(a+1, b, psun);
	ans += p * (1-ps) * pl * go(a, b+1, max(0, psun - PD));
	ans += p * (1-ps) * (1-pl) * go(a, b+1, psun);
	
	ans += (1-p) * pr * pw * go(a+1, b, min(1000, psun + PU));
	ans += (1-p) * pr * (1-pw) * go(a+1, b, psun);
	ans += (1-p) * (1-pr) * pl * go(a, b+1, max(0, psun - PD));
	ans += (1-p) * (1-pr) * (1-pl) * go(a, b+1, psun);

	vis[a][b][psun] = t;
	return dp[a][b][psun] = ans;
}

int main() {
	int T;
	cin>>T;
	for(t=1;t<=T;t++) {
		cin>>k>>ps>>pr>>pi>>pu>>pw>>pd>>pl;
		PI = pi*1000 + 1e-9;
		PU = pu*1000 + 1e-9;
		PD = pd*1000 + 1e-9;
		printf("Case #%d: %.6lf\n", t, 1e-12+go(0, 0, PI));
	}
	return 0;
}
