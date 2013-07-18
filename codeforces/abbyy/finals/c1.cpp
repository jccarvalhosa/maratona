#include <iostream>
#include <algorithm>
#define M 1000001
using namespace std;

int dp[M];
int pot[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int main() {
	int n, i, j;
	for(i=1;i<M;i++) {
		dp[i] = i;
		for(j=0;j<7;j++) {
			int x = (i/pot[j]) % 10;
			dp[i] = min(dp[i], 1+dp[i-x]); 
		}
	}
	cin>>n;
	cout<<dp[n]<<endl;
	return 0;
}
