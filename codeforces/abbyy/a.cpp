#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int vis[10] = {0};

int main() {
	int c=0, n=0, i, flag=0;
	long long ans=1;
	string s;
	cin>>s;
	for(i=0;i<s.size();i++) {
		if(s[i]=='?') {
			if(i==0) flag=1;
			c++;
		}
		if(s[i]>='A' && s[i]<='J') {
			if(i==0) flag=1;
			vis[s[i]-'A']=1;
		}
	}
	for(i=0;i<10;i++) if(vis[i]) n++;
	for(i=0;i<n;i++) ans *= 10-i;
	if(flag) {
		ans *= 9;
		if(ans % 10 == 0) {
			ans /= 10;
			flag=0;
		}
	}
	cout << ans;
	for(i=flag;i<c;i++) cout<<0;
	cout<<endl;
	return 0;
}
