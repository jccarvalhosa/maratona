#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int n, i;
	ll p, q, a, aux;
	cin>>p>>q>>n;
	for(i=0;i<n;i++) {
		cin>>a;
		if(q==0) break;
		if(p/q < a) break;
		if(a < p/q-1) break;
		aux = p - q*a;
		p = q;
		q = aux;
	}
	if(i==n && q==0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
