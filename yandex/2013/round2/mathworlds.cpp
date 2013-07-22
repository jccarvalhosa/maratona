#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	char last;
	cin>>a>>b>>c;
	int t=0;
	if(a+b==c) {
		t++;
		last='+';
	}
	if(a-b==c) {
		t++;
		last='-';
	}
	if(a*b==c) {
		t++;
		last='*';
	}
	if(b != 0 && a % b == 0 && a/b==c) {
		t++;
		last='/';
	}
	if(t==1) cout<<last<<endl;
	else cout<<"Invalid"<<endl;
	return 0;
}
