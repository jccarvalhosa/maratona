#include <iostream>
#include <string>
using namespace std;
		
int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		string s, p;
		int n, valid=0;
		cin>>n>>s;
		p = "";
		for(int i=0;i<=10 && i<n;i++) {
			string pr = "";
			for(int i=p.size()-1;i>=0;i--) pr += p[i]=='R'?"L":"R";
			p = p + "L" + pr;
		}
		cout<<"Case "<<t<<": "<<(p.find(s) != string::npos?"Yes":"No")<<endl;
	}
	return 0;
}
