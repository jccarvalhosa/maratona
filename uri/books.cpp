#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	double q, d, p;
	while(cin>>q && q) {
		cin>>d>>p;
		int n = q*p*d/(p-q) + 1e-9;
		cout<<n;
		if(n==1) cout<<" pagina\n";
		else cout<<" paginas\n";
	}
	return 0;
}
