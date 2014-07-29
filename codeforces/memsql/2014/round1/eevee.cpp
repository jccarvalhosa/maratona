#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string evol[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<8;i++) {
		if(evol[i].size() != n) continue;
		int good=1;
		for(int j=0;j<n;j++) if(s[j] != '.' && s[j] != evol[i][j]) good=0;
		if(good) {
			cout << evol[i] << endl;
			return 0;
		}
	}
}
