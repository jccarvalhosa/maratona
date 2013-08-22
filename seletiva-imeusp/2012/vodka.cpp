#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int c[2222], v[2222], dp[2222][2222];

int main() {
	int n, ini, m, p;
	while(scanf("%d %d %d %d", &n, &ini, &m, &p) != EOF) {
		for(int i=0;i<m;i++) cin>>c[i];
		for(int i=1;i<=m;i++) cin>>v[i];
		for(int i=0;i<=m;i++) dp[n+1][i] = 0;
		for(int i=n;i>=1;i--) {
			for(int j=1;j<m;j++) dp[i][j] = min(c[j] + dp[i+1][j+1], c[0] + p - v[j] + dp[i+1][1]);
			dp[i][m] = c[0] + p - v[m] + dp[i+1][1];
		}
		printf("%d\n", dp[1][ini]);
		int age = ini;
		vector<int> sol;
		for(int i=1;i<=n;i++) {
			if(age == m || c[0] + p - v[age] + dp[i+1][1] <= c[age] + dp[i+1][age+1]) {
				sol.push_back(i);
				age = 1;
			}
			else age++;
		}
		if(sol.empty()) printf("0\n");
		else {
			printf("%d", sol[0]);
			for(int i=1;i<sol.size();i++) printf(" %d", sol[i]);
			printf("\n");
		}
	}
	return 0;
}
