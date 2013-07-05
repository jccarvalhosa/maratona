#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int n, f, r, t;
	cin>>t;
	getchar();
	while(t--) {
		getline(cin, s);
		f=r=0;
		n=s.size();
		if(n>=5) {
			if(s.substr(0, 5) == "miao.") r=1;
			if(s.substr(n-5, 5) == "lala.") f=1;
			if(r==1 && f==0) cout <<"Rainbow's"<< endl;
			else if(f==1 && r==0) cout <<"Freda's"<< endl;
			else cout<<"OMG>.< I don't know!"<<endl;
		}
		else cout<<"OMG>.< I don't know!"<<endl;
	}
	return 0;
}
