#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int i, c=0, n;
	cin>>s;
	n = s.size();
	if(s[0] != '1') {
		cout<<"NO"<<endl;
		return 0;
	}
	for(i=n-1;i>=0;i--) {
		if(s[i] == '1') {
			c=0;
		}
		else if(s[i] == '4') {
			c++;
			if(c>2) {
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
