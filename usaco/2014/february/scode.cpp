#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
using namespace std;
const int M=2014;

map<string, int> vis;

int go(string s) {
	if(vis.count(s)) return vis[s];
	int ans=1, n=s.size();
	for(int tp=1;tp<(n+1)/2;tp++) {
		int i, good=0;
		for(i=0;i<tp;i++) if(s[i] != s[tp+i]) break;
		if(i==tp) {
			ans += go(s.substr(tp));
		}
		for(i=0;i<tp;i++) if(s[tp-i-1] != s[n-i-1]) break;
		if(i==tp) {
			ans += go(s.substr(tp));
		}
	}
	for(int ts=1;ts<(n+1)/2;ts++) {
		int i, good=0;
		for(i=0;i<ts;i++) if(s[n-ts+i] != s[i]) break;
		if(i==ts) {
			ans += go(s.substr(0, n-ts));
		}
		for(i=0;i<ts;i++) if(s[n-i-1] != s[n-ts-i-1]) break;
		if(i==ts) {
			ans += go(s.substr(0, n-ts));
		}
	}
	return vis[s] = ans%M;
}

int main() {
	freopen("scode.in", "r", stdin);
	freopen("scode.out", "w", stdout);
	string s;
	cin>>s;
	cout << (go(s) + M - 1)%M << endl;
	return 0;
}
