#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int n;
		cin>>n;
		string s;
		cin>>s;
		s += s;
		ll dp[100][100] = {0};
		for(int tam=3;tam<=n;tam+=3) for(int i=0;i<n;i++) {
			int f = i+tam-1;
			for(int ii=i+1;ii<=f;ii++) for(int jj=ii+1;jj<=f;jj++) {
				int c=0;
				if(s[i]=='R') c++;
				if(s[ii]=='R') c++;
				if(s[jj]=='R') c++;
				if(c>1) continue;
				ll v1 = (ii == i+1 ? 1 : dp[i+1][ii-1]);
				ll v2 = (jj == ii+1 ? 1 : dp[ii+1][jj-1]);
				ll v3 = (f == jj ? 1 : dp[jj+1][f]);
				dp[i][f] += v1 * v2 * v3;
			}
		}
		cout << "Case "<<t<<": "<<dp[0][n-1]<<endl;
	}
	return 0;
}
