#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string ans;
	while(cin>>n && n) {
		int t=1e9;
		string s;
		int a, b;
		for(int i=0;i<n;i++) {
			cin>>s>>a>>b;
			if(a-b<t) {
				t=a-b;
				ans=s;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
