#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

string s;
int a;

int len(int e) { return 1 + e*log(a)/log(10) + 1e-12; }

int valid(int e) {
	if(len(e) != s.size()) return 0;
	int x = a%10;
	for(int i=0;i<e-1;i++) x = (x*a)%10;
	if(s[s.size()-1]-'0' != x) return 0;
	return 1;
}

int solve() {
	int i=0, f=(int)1e9;
	while(1) {
		int mid = (i+f)/2;
		int x = len(mid);
		if(x<s.size()) i=mid;
		else if(x>s.size()) f=mid;
		else {
			for(int i=max(1, mid-5);i<=mid+5;i++) if(valid(i)) return i;
		}
	}
	return 0;
}

int main() {
	cin>>a;
	cin>>s;
	if(s == "1") cout << 0 << endl;
	else cout << solve() << endl;
	return 0;
}
