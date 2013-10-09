#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vv;
typedef vector<vv> vvv;

int main() {
	ll P = 9705276;
	ll Q = 12805858;
	map<ll, pii> m;
	for(int i=0;i<=400;i++) for(int j=0;i+j<=400;j++) m[P*i + Q*j] = pii(i, j);
	int n;
	while(scanf("%d", &n) != EOF) {
		ll xmax=0;
		int p, q;
		vector<pii> v;
		for(int i=0;i<n;i++) {
			ll a, b;
			scanf("%lld.%lld", &a, &b);
			ll x = a*100000 + b;
			if(m.count(x)) {
				v.push_back(m[x]);
				if(xmax < x) {
					xmax=x;
					p = v.back().first;
					q = v.back().second;
				}
			}
		}
		n = p+q;
		int m = n/2;
		vector<vi> c(n+1, vi(n+1, 0));
		for(int i=0;i<v.size();i++) {
			int a = v[i].first;
			int b = v[i].second;
			if(a > p || b > q || a+b==n) continue;
			if(a+b > m) {
				a = p-a;
				b = q-b;
			}
			c[a][b]++;
		}
		vvv dp(m+1), previ(m+1), prevj(m+1);
		for(int t=0;t<=m;t++) dp[t] = previ[t] = prevj[t] = vv(t+1, vi(t+1, 0));
		dp[0][0][0]=1;
		for(int t=0;t<m;t++) for(int i=0;i<=t;i++) for(int j=0;j<=t;j++) for(int ii=i;ii<=i+1;ii++) for(int jj=j;jj<=j+1;jj++) {
			int pts = dp[t][i][j];
			pts += c[ii][t+1-ii];
			if(ii != jj) pts += c[jj][t+1-jj];
			if(pts > dp[t+1][ii][jj]) {
				dp[t+1][ii][jj] = pts;
				previ[t+1][ii][jj]=i;
				prevj[t+1][ii][jj]=j;
			}
		}
		int besti, bestj, best=-1;
		for(int i=0;i<=m;i++) for(int x=0;x<=n%2;x++) {
			int j = p-i-x;
			if(j<0 || j>m) continue;
			if(dp[m][i][j] > best) {
				best = dp[m][i][j];
				besti=i; 
				bestj=j;
			}
		}
		int i = besti;
		int j = bestj;
		string s="";
		if(n%2==1) s = (i+j==p) ? "Q" : "P";
		for(int k=m;k>=1;k--) {
			int ii = previ[k][i][j];
			int jj = prevj[k][i][j];
			s = (i == ii ? "Q" : "P") + s + (j == jj ? "Q" : "P");
			i = ii;
			j = jj;
		}
		cout << s << endl;
	}
	return 0;
}
