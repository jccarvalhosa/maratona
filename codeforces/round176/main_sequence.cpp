#include <iostream>
using namespace std;

int p[1000001], s[1000001], v[1000001];

int main() {
	int n, t, i, top;
	cin>>n;
	for(i=1;i<=n;i++) {
		cin>>v[i];
		s[i]=1;
	}
	cin>>t;
	while(t--) {
		cin>>i;
		s[i]=-1;
	}
	top=0;
	for(i=n;i>0;i--) {
		if(s[i] == -1 || top==0 || p[top] != v[i]) {
			p[++top] = v[i];
			s[i] = -1;
		}
		else top--;
	}
	if(top) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		for(i=1;i<=n;i++) cout<<v[i]*s[i]<<" ";
		cout << endl;
	}
	return 0;
}
