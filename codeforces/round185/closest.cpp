#include <iostream>
using namespace std;

int main() {
	int n, k, i, tot;
	cin>>n>>k;
	tot = (n-1)*n/2;
	if(tot > k) { for(i=1;i<=n;i++) cout<<i<<" "<<(n-i)*(n-i)<<endl; }
	else cout<<"no solution"<<endl;
	return 0;
}
