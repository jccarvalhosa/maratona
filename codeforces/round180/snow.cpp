#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, ini=-1, fim=-1, i;
	string s;
	cin>>n>>s;
	for(i=0;i<n;i++) if(s[i]=='L') break;
	if(i==n) {
		for(i=0;i<n;i++) {
			if(s[i]=='R' && ini==-1) ini=i;
			if(s[i] == '.' && ini != -1 && fim == -1) fim=i;
		}
		cout << ini+1 << ' ' << fim+1 << endl;
		return 0;
	}
	for(i=0;i<n;i++) if(s[i]=='R') break;
	if(i==n) {
		for(i=0;i<n;i++) {
			if(s[i]=='L' && fim == -1) fim=i-1;
			if(s[i] == 'L') ini=i;
		}
		cout << ini+1 << ' ' << fim+1 << endl;
		return 0;
	}
	for(i=0;i<n;i++) {
		if(s[i]=='R' && ini==-1) ini=i;
		if(s[i]=='L' && ini!=-1 && fim==-1) fim=i-1;
	}
	cout << ini+1 << ' ' << fim+1 << endl;
	return 0;
}
