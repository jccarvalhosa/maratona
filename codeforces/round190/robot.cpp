#include <iostream>
#include <cstdio>
#define INF 1000000009
using namespace std;
	
int dp[102][2][2], m[102][2];
int abs(int a) { return a>0?a:-a; }

int main() {
	int n, a, b, x, y, i, j, modx, mody, deltax, deltay, kx, ky;
	string s;
	cin>>a>>b;
	cin>>s;
	n = s.size();
	if(a==0&&b==0) {
		cout << "Yes"<<endl;
		return 0;
	}
	for(i=1;i<=n;i++) {
		m[i][0]=m[i][1]=0;
		if(s[i-1]=='U') m[i][1]=1;
		if(s[i-1]=='D') m[i][1]=-1;
		if(s[i-1]=='L') m[i][0]=-1;
		if(s[i-1]=='R') m[i][0]=1;
	}
	for(i=1;i<=n;i++) {
		dp[i][0][0] = dp[i-1][0][0] + m[i][0];
		dp[i][1][0] = dp[i-1][1][0] + m[i][1];
	}
	for(i=n;i>=1;i--) {
		dp[i][0][1] = dp[i+1][0][1] + m[i][0];
		dp[i][1][1] = dp[i+1][1][1] + m[i][1];
	}
	for(i=1;i<=n;i++) {
		x = dp[i][0][0];
		y = dp[i][1][0];
		modx = dp[i+1][0][1] + dp[i][0][0];
		mody = dp[i+1][1][1] + dp[i][1][0];
		deltax = a-x;
		deltay = b-y;
		if(1ll*modx*deltax<0) continue;
		if(1ll*mody*deltay<0) continue;
		modx = abs(modx);
		mody = abs(mody);
		deltax = abs(deltax);
		deltay = abs(deltay);
		kx = modx==0?INF:deltax/modx;
		ky = mody==0?INF:deltay/mody;
		if(kx*modx != deltax) continue;
		if(ky*mody != deltay) continue;
		if(kx==INF || ky==INF || kx==ky) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
