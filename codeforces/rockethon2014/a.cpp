#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	cin>>s;
	int i, j, ans=0;
	for(i=0;i<s.size();) {
		for(j=i;j<s.size();j++) if(s[j]!=s[i]) break;
		if((j-i)%2==0) ans++;
		i=j;
	}
	cout<<ans<<endl;
	return 0;
}
