#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=1e5+10;
const int M=7477777;
		
ll c[6][N], dp[N][6];

int main() {
	for(int i=0;i<N;i++) {
		c[0][i]=1;
		for(int j=1;j<=min(5, i);j++) c[j][i] = (c[j-1][i-1] + c[j][i-1])%M;
	}
	for(ll i=1;i<N;i++) dp[i][1] = i*i%M;
	for(int j=2;j<=5;j++) {
		dp[j][j] = j;
		for(int i=j+1;i<N;i++) {
			for(int n1=0;n1<j;n1++) {
				int jj = j-n1;
				int ii = i-j;
				dp[i][j] += c[n1][j] * (n1*c[jj-1][ii-1] + dp[ii][jj] + 2*ii*c[jj-1][ii-1] + jj*c[jj-1][ii-1]) % M;
			}
			dp[i][j] %= M;
		}
	}
	int T, n;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		cout<<"Case "<<t<<": "<<dp[n][5]<<endl;
	}
	return 0;
}
