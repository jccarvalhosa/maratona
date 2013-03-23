#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

int main() {
	int t, T, c1, c2;
	string s;
	cin >> T;
	for(t=1;t<=T;t++) {
		cin >> s;
		c1 = (s[0]-'A')*26*26 + (s[1]-'A')*26 + (s[2]-'A');
		c2 = (s[4]-'0')*1000 + (s[5]-'0')*100 + (s[6]-'0')*10 + (s[7]-'0');
		if(mod(c1-c2) <= 100) printf("nice\n");
		else printf("not nice\n");
	}
	return 0;
}
