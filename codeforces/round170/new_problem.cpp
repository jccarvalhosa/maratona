#include <string>
#include <set>
#include <iostream>
using namespace std;

set<string> vis;
string s;

string val(int n) {
	string ret="";
	while(n) {
		ret.insert(0, "a");
		ret[0] = 'a' + (n-1)%26;
		n = (n-1)/26;
	}
	return ret;
}

int main() {
	int n, i, j, k;
	cin >> n;
	while(n--) {
		cin >> s;
		for(i=0;i<s.size();i++) for(j=i;j<s.size();j++) {
			string aux="";
			for(k=i;k<=j;k++) aux += s[k];
			vis.insert(aux);
		}
	}
	for(i=1;vis.count(val(i));i++) ;
	cout << val(i) << endl;
	return 0;
}
