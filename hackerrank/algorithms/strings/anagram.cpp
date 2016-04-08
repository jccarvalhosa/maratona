#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	int T;
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		int n = s.size();
		if (n&1) {
			cout << -1 << endl;
			continue;
		}
		vector<int> c1(26, 0), c2(26, 0);
		for (int i=0; i < n/2; i++)
			c1[s[i]-'a']++;
		for (int i=n/2; i < n; i++)
			c2[s[i]-'a']++;
		int ans = 0;
		for (int i=0; i < 26; i++)
			ans += abs(c1[i] - c2[i]);

		cout << ans / 2 << endl;
	}
	return 0;
}
