#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int dp[1111][30][30][2];

int main() {
	string s;
	int n, p;
	cin>>n>>p>>s;
	for(int a=0;a<=p;a++) for(int b=0;b<=p;b++) dp[n][a][b][0] = 1;
	for(int i=n-1;i>=0;i--) {
		for(int a=0;a<=p;a++) for(int b=0;b<=p;b++) {
			for(int c=0;c<p;c++) if(c != a && c != b) {
				if(c > s[i]-'a') {
					if(dp[i+1][b][c][0]) {
						dp[i][a][b][1] = 1; 
						dp[i][a][b][0] = 1; 
					}
				}
				else {
					if(c == s[i]-'a' && dp[i+1][b][c][1]) dp[i][a][b][1] = 1; 
					if(dp[i+1][b][c][0]) dp[i][a][b][0] = 1; 
				}
			}
		}
	}
	if(!dp[0][p][p][1]) cout << "NO" << endl;
	else {
		int a = p, b = p, inc=1;
		for(int i=0;i<n;i++) {
			int v = 0;
			if(inc) {
				v = s[i] - 'a';
				if(v != a && v != b && dp[i+1][b][v][1]) {
					printf("%c", 'a'+v);
					a = b;
					b = v;
					continue;
				}
				v++;
				inc = 0;
			}
			for(; v < p; v++) {
				if(v != a && v != b && dp[i+1][b][v][0]) {
					printf("%c", 'a'+v);
					a = b;
					b = v;
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
