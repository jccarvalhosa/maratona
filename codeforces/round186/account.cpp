#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int n, i;
	cin>>s;
	if(s[0]!='-') cout<<s<<endl;
	else {
		n = s.size();
		s[n-2] = min(s[n-1], s[n-2]);
		if(n==2 || n==3 && s[1]=='0') cout<<0<<endl;
		else {
			for(i=0;i<n-1;i++) cout<<s[i];
			cout<<endl;
		}
	}
	return 0;
}
