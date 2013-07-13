#include <iostream>
#include <string>
using namespace std;

int dp[100];

int main() {
	int b, d, n, m, i, j, t=0;
	string a, c;
	cin>>b>>d>>a>>c;
	n = a.size();
	m = c.size();
	for(i=0;i<m;i++) for(j=0;j<n;j++) if(a[j]==c[(i+dp[i])%m]) dp[i]++; 
	for(i=0;i<b;i++) t += dp[t%m];
	cout<<t/d/m<<endl;
	return 0; 
}
