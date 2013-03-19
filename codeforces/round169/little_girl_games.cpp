#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

string s;
int c[26];

int main() {
	int i, n;
	cin >> s;
	memset(c, 0, sizeof(c));
	for(i=0;i<s.size();i++) c[s[i]-'a']++;
	n=0;
	for(i=0;i<26;i++) if(c[i] % 2 == 1) n++;
	if(n <= 1 || s.size() % 2 == 1) printf("First\n");
	else printf("Second\n");
	return 0;
}
