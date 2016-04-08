#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
	map<vector<int>, int> m;
	int T;
	cin>>T;
	while(T--) {
		m.clear();
		string s;
		cin>>s;
		int n = s.size();
		for (int i=0; i < n; i++) for(int j=i; j < n; j++) {
			vector<int> v(26, 0);
			for (int k=i; k <= j; k++)
				v[s[k]-'a']++;
			m[v]++;
		}
		long long ans = 0;
		for (map<vector<int>, int>::iterator it = m.begin(); it != m.end(); it++) {
			ans += (it -> second) * ((it -> second) - 1) / 2; 
		}
		cout << ans << endl;
	}
	return 0;
}

