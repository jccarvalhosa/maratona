#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool go(string s) {
	if(s.size() == 1 || s.find('1') == string::npos) return 0;
	if(s.size() % 2 == 0) return 1;
	string v, u;
	for(int i=1;i<s.size();i+=2) {
		v += s[i];
		u += (s[i-1] != s[i+1] ? '1' : '0'); 
	}
	return go(v) || go(u);
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		cout << (go(s) ? "LIVES" : "DIES") << endl;
	}
	return 0;
}
