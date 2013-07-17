#include <iostream>
using namespace std;

int s[3];

int main() {
	int n, l, t, d, i;
	cin>>n>>l;
	for(i=0;i<n;i++) {
		cin>>t>>d;
		if(d==-1) s[t]++;
		else if(d<l) s[t]+=2;
		else s[t]+=3;
	}
	cout<<s[1]<<":"<<s[2]<<endl;
	return 0;
}
