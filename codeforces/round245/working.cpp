#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int n;
const int N=1e3+10;
int a[N][N];
ll dlt[N][N][2], drb[N][N][2], dlb[N][N][2], drt[N][N][2];

int main() {
	int n, m;
	cin>>n>>m;

	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d", &a[i][j]);
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		dlt[i][j][0] = a[i][j] + max(dlt[i-1][j][0], dlt[i-1][j][1]);
		dlt[i][j][1] = a[i][j] + max(dlt[i][j-1][0], dlt[i][j-1][1]);
	}
	
	for(int i=n;i>=1;i--) for(int j=1;j<=m;j++) {
		dlb[i][j][0] = a[i][j] + max(dlb[i+1][j][0], dlb[i+1][j][1]);
		dlb[i][j][1] = a[i][j] + max(dlb[i][j-1][0], dlb[i][j-1][1]);
	}
	
	for(int i=1;i<=n;i++) for(int j=m;j>=1;j--) {
		drt[i][j][0] = a[i][j] + max(drt[i-1][j][0], drt[i-1][j][1]);
		drt[i][j][1] = a[i][j] + max(drt[i][j+1][0], drt[i][j+1][1]);
	}
	
	for(int i=n;i>=1;i--) for(int j=m;j>=1;j--) {
		drb[i][j][0] = a[i][j] + max(drb[i+1][j][0], drb[i+1][j][1]);
		drb[i][j][1] = a[i][j] + max(drb[i][j+1][0], drb[i][j+1][1]);
	}
	
	ll ans=0;
	for(int i=2;i<n;i++) for(int j=2;j<m;j++) {
		ans = max(ans, dlt[i][j][0] + drb[i][j][0] + drt[i][j][1] + dlb[i][j][1] - 4*a[i][j]);
		ans = max(ans, dlt[i][j][1] + drb[i][j][1] + drt[i][j][0] + dlb[i][j][0] - 4*a[i][j]);
	}
	cout << ans << endl;

	return 0;
}
