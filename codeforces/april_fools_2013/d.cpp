#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int i, n;
	cin>>s>>n;
	for(i=0;i<s.size();i++) {
		int d;
		if(s[i] >= 'a' && s[i] <= 'z') d = s[i]-'a';
		else d = s[i]-'A';
		if(d<n) s[i] = 'A'+d;
		else s[i] = 'a'+d;
	}
	cout<<s<<endl;
	return 0;
}
