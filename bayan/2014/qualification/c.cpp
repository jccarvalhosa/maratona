#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


//Front Up Down Left Right Back
string s[6];

int main() {
	int T;
	cin>>T;
	while(T--) {
		for(int i=0;i<6;i++) cin>>s[i];
		int n;
		cin>>n;
		while(n--) {
			char c;
			int m;
			cin>>c>>m;
			m %= 4;
			while(m--) {
				if(c=='X') {
					string aux = s[0];
					s[0] = s[2];
					s[2] = s[5];
					s[5] = s[1];
					s[1] = aux;
				}
				if(c=='Y') {
					string aux = s[4];
					s[4] = s[1];
					s[1] = s[3];
					s[3] = s[2];
					s[2] = aux;
				}
				if(c=='Z') {
					string aux = s[0];
					s[0] = s[3];
					s[3] = s[5];
					s[5] = s[4];
					s[4] = aux;
				}
			}
		}
		cout << s[0];
		for(int i=1;i<6;i++) cout << " " << s[i]; cout << endl;
	}
	return 0;
}
