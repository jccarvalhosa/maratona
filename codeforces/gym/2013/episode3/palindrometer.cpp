#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int is_pal(string s) {
	for(int i=0;i<s.size()/2;i++) if(s[i] != s[s.size()-i-1]) return 0;
	return 1;
}

int main() {
	string s;
	while(1) {
		cin >> s;
		if(s == "0") break;
		for(int i=0;;i++) {
			if(is_pal(s)) {
				cout<<i<<endl;
				break;
			}
			for(int i=s.size()-1;i>=0;i--) {
				if(s[i] != '9') {
					s[i] = s[i] + 1;
					break;
				}
				else s[i]= '0';
			}
		}
	}
	return 0;
}
