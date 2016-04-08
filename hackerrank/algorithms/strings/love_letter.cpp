#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int T;
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		int n = s.size();
		int ans = 0;
		for (int i=0; i < n/2; i++) {
			ans += max(s[i], s[n-i-1]) - min(s[i], s[n-i-1]);
		}
		cout << ans << endl;
	}
	return 0;
}
