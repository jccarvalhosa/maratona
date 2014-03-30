#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string s[222];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		getchar();
		for(int i=0;i<n;i++) getline(cin, s[i]);
		int ans=0;
		for(int i=0;i<n;i++) {
			int good=1;
			for(int j=0;j<i;j++) if(s[j] > s[i]) {
				good=0;
				break;
			}
			if(!good) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
