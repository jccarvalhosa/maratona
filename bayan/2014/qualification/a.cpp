#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		reverse(s.begin(), s.end());
		while(s.size() > 0 && s[0]=='0') s=s.substr(1);
		cout << s << endl;
	}
	return 0;
}
