#include <iostream>
#include <string>
using namespace std;

int main() {
	int ans=0;
	int k, n;
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		int c[11] = {0};
		for(int j=0;j<s.size();j++) c[s[j]-'0']++;
		int j;
		for(j=0;j<=k;j++) if(!c[j]) break;
		if(j>k) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
