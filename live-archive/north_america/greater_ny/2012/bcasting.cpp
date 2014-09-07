#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int t, b;
		string s;
		cin>>t>>b>>s;
		reverse(s.begin(), s.end());
		int pot=1, ans=0;
		for(int i=0;i<s.size();i++) {
			ans = (ans + (s[i] - '0') * pot) % (b-1);
			pot = (pot * b) % (b-1);
		}
		printf("%d %d\n", t, ans);
	}
	return 0;
}
