#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while(cin>>s && s != "0") {
		vector<int> v(s.size(), 0);
		vector<int> ans;
		for(int i=1;i<s.size();i++) {
			if(s[i]-'0' != v[i]) {
				ans.push_back(i);
				for(int j=i;j<s.size();j+=i) v[j]^=1;
			}
		}
		cout << ans[0]; for(int i=1;i<ans.size();i++) cout << " " << ans[i]; cout << endl;
	}
	return 0;
}
