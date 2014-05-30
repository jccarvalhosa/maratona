#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int open=0;
	vector<int> v;
	for(int i=1;i<s.size();i++) {
		if(s[i]==')') {
			if(!isalpha(s[i-1]) && !isdigit(s[i-1]) && s[i-1] != ' ' && s[i-1] != '(' && s[i-1] != ')') {
				v.push_back(i-1);
				v.push_back(i);
			}
			else {
				if(isalpha(s[i-1])) {
					for(int j=i-2;j>=0;j--) {
						if(isupper(s[j]) || islower(s[j])) continue;
						if(s[j] == '(') {
							v.push_back(j);
							v.push_back(i);
						}
						break;
					}
				}
			}
		}
	}
	int j=0;
	for(int i=0;i<s.size();i++) {
		if(j != v.size() && v[j]==i) {
			if(j&1) cout << s[i]<<"</S>";
			else cout << "<S>"<<s[i];
			j++;
		}
		else cout << s[i];
	}
	cout << endl;
	return 0;
}
