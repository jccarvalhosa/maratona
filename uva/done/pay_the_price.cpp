#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
typedef long long ll;

ll dp[1111][1111];

int main() {
	dp[0][0] = 1;
	for(int i=1;i<=300;i++) {
		dp[i][1] = 1;
		for(int j=2;j<=i;j++) dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
	}
	string s;
	while(getline(cin, s) && !cin.eof()) {
		vector<int> v;
		stringstream ss(s);
		int x;
		while(ss >> x) v.push_back(x);
		int n=v[0], a=0, b=n;
		if(v.size() == 2) b=v[1];
		if(v.size() == 3) a=v[1], b=v[2];
		ll sum=0;
		for(int i=a;i<=b;i++) sum += dp[n][i];
		cout << sum << endl;
	}
	return 0;
}
