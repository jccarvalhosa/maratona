#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int dp[51][51][2];

int main() {
	int n[2], k[2];
	cin>>n[0]>>n[1]>>k[0]>>k[1];
	dp[0][0][0] = dp[0][0][1] = 0;
	for(int i=1;i<=50;i++) {
		dp[0][i][0] = 0;
		dp[i][0][0] = 1;
		dp[0][i][1] = 1;
		dp[i][0][1] = 0;
	}
	for(int i=1;i<=50;i++) for(int j=i;j<=50;j++) {
		dp[i][j][0] = 0;
		for(int t=1;t<=min(k[0], i);t++) if(dp[i-t][j][1] == 0) dp[i][j][0] = 1;
		dp[j][i][0] = 0;
		for(int t=1;t<=min(k[0], j);t++) if(dp[j-t][i][1] == 0) dp[j][i][0] = 1;

		dp[i][j][1] = 0;
		for(int t=1;t<=min(k[1], j);t++) if(dp[i][j-t][0] == 0) dp[i][j][1] = 1;
		dp[j][i][1] = 0;
		for(int t=1;t<=min(k[1], i);t++) if(dp[j][i-t][0] == 0) dp[j][i][1] = 1;
	}
	if(dp[n[0]][n[1]][0] == 1) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
