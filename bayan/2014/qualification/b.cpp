#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		int cnt=0;
		for(int i=0;i<s.size();i++) if(string("aeiou").find(s[i]) != -1) cnt++;
		if(cnt&1) cout << "PESAR" << endl;
		else cout << "DOKHTAR" << endl;
	}
	return 0;
}
