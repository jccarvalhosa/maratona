#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin>>s;
    s="00"+s;
    int i, ans=0;
    for(i=s.size()-1;i>=1;i--) if(s[i]=='1') {
		ans++;
		if(s[i-1] == '1') {
			while(s[i]=='1') s[i--]='0';
			s[i++]='1';
		}
    }
    cout<<ans<<endl;
    return 0;
}
