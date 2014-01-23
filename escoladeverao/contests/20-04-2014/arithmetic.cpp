#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=3333;
int a[N], sum[N][N], dp[N], cont[N][N], best[N][N];
int mod(int a) { return a>0 ? a : -a; }

int main() {
	int n, c, p;
	cin>>n>>c>>p;
	for(int i=0;i<n;i++) {cin>>a[i]; a[i]+=1000;}
	for(int j=0;j<=2000;j++) {
		if(a[0]==j) sum[0][j]=1;
		for(int i=1;i<n;i++) sum[i][j] = sum[i-1][j] + (a[i]==j);
	}
	for(int t=3;t<=n;t++) for(int i=0;i+t-1<n;i++) {
		int j = i+t-1;
		cont[i][j] = j-i-1;
		if(a[i] == a[j]) { cont[i][j] -= sum[j-1][a[j]] - sum[i][a[j]]; }
		else {
			int g = __gcd(j-i, mod(a[j]-a[i]));
			int d = (j-i)/g;
			for(int c=1;c<g;c++) {
				int k = i+c*d;
				if((a[i] + ((k-i)*(a[j]-a[i]))/(j-i)) == a[k]) {
					cont[i][j] = cont[i][k] + cont[k][j];
					break;
				}
			}
		}
	}
	for(int t=3;t<=n;t++) for(int i=0;i+t-1<n;i++) {
		int j = i+t-1;
		best[i][j] = min(cont[i][j]*c, min(best[i+1][j], best[i][j-1])+c); 
	}
	for(int i=n-1;i>=0;i--) {
		dp[i] = 1<<30;
		for(int j=i;j<n;j++) dp[i] = min(dp[i], best[i][j] + p + dp[j+1]);
	}
	cout << dp[0] << endl;
	return 0;
}
