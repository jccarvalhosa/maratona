#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string s[100000];

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i=0;i<n;i++) cin>>s[i];
		sort(s, s+n);
		int ans=0;
		for(int i=1;i<n;i++) for(int j=0;j<s[i].size() && s[i][j]==s[i-1][j];j++) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
