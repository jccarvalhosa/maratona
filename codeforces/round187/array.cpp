#include <iostream>
using namespace std;

int a[100001], v[100001];

int main() {
	int t, i, x, n, m, sum=0;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	while(m--) {
		cin>>t;
		if(t==1) {
			cin>>i>>x;
			a[i] = x-sum;
		}
		if(t==2) {
			cin>>x;
			sum += x;
		}
		if(t==3) {
			cin>>i;
			cout<<a[i]+sum<<endl;
		}
	}
	return 0;
}
