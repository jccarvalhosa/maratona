#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n, k, ne, no;
	cin>>n>>k;
	ne = no = n/2;
	if(n%2==1) no++;
	if(k<=no) cout<<2*k-1<<endl;
	else {
		k -= no;
		cout<<2*k<<endl;
	}
	return 0;
}
