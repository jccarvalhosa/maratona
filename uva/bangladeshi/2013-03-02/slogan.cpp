#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> m;

int main() {
	int n, q, i;
	string s1, s2;
	scanf("%d ", &n);
	for(i=0;i<n;i++) {
		getline(cin, s1);
		getline(cin, s2);
		m[s1] = s2;
	}
	scanf("%d ", &q);
	for(i=0;i<q;i++) {
		getline(cin, s1);
		cout << m[s1] << endl;
	}
	return 0;
}
