#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define M 1000000007

ll fat[1001], c[1001][1001], good[1001], f[1001], dp[1001][1001][4];

void add(ll &a, ll b) {
	a += b;
	if(a>M) a-=M;
	if(a<0) a+=M;
}

int main() {
	int N, K, i, j, k;
	cin>>N>>K;
	fat[0]=1;
	for(i=1;i<=N;i++) fat[i] = (fat[i-1]*i)%M;
	for(i=0;i<=N;i++) {
		c[0][i] = 1;
		for(j=1;j<=i;j++) c[j][i] = (c[j][i-1] + c[j-1][i-1])%M;
	}
	dp[0][0][0] = 1;
	for(i=1;i<=N;i++) for(j=0;j<=i;j++) {
		//acrescento nada
		add(dp[j][i][0], dp[j][i-1][0]);
		add(dp[j][i][0], dp[j][i-1][1]);
		add(dp[j][i][1], dp[j][i-1][2]);
		add(dp[j][i][1], dp[j][i-1][3]);
		//acrescento i-1
		if(i!=1 && j) {
			add(dp[j][i][0], dp[j-1][i-1][0]);
			add(dp[j][i][1], dp[j-1][i-1][2]);
		}
		//acrescento i+1
		if(i!=N && j) {
			add(dp[j][i][2], dp[j-1][i-1][0]);
			add(dp[j][i][2], dp[j-1][i-1][1]);
			add(dp[j][i][3], dp[j-1][i-1][2]);
			add(dp[j][i][3], dp[j-1][i-1][3]);
		}
	}
	for(i=0;i<=N;i++) {
		for(j=0;j<4;j++) add(f[i], dp[i][N][j]);
		f[i] = (f[i] * fat[N-i])%M;
	}
	for(i=N;i>=0;i--) {
		good[i] = f[i];
		for(j=i+1;j<=N;j++) add(good[i], -(c[i][j]*good[j])%M);
	}
	cout<<good[K]<<endl;
	return 0;
}
