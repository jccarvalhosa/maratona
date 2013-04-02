#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, k, t, i;
	cin>>n>>k;
	if((n!=1 && k==1) || k>n) cout<<-1<<endl;
	else if(n==1) cout<<"a"<<endl;
	else {
		for(i=0;i<n;i++) {
			if(i%2==0) cout<<'a';
			else cout<<'b';
			if(n-i-1 == k-2) break;
		}
		for(t=i+1;t<n;t++) cout<<char('c'+(t-i-1));
		cout<<endl;
	}
	return 0;
}
