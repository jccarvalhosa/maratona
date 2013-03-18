#include <string>
#include <iostream>
using namespace std;

string s;

int main() {
	int n, sa=0, sf=0, si=0, ans=0, i;
	cin >> n;
	cin >> s;
	for(i=0;i<s.size();i++) {
		if(s[i] == 'A') sa++;
		if(s[i] == 'F') sf++;
		if(s[i] == 'I') si++;
	}
	ans = 0;
	for(i=0;i<s.size();i++) {
		if(s[i] == 'F') continue;
		if(s[i] == 'I' && si == 1) ans++;
		if(s[i] == 'A' && si == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}

