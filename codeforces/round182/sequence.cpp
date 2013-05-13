#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, n, m=1000000000, i, sum=0, nn=0;
	cin>>n;
	for(i=0;i<2*n-1;i++) {
		cin>>a;
		if(a < 0) {
			a = -a;
			nn++;
		}
		sum += a;
		m = min(m, a);
	}
	if(n % 2 == 1 || nn % 2 == 0) cout << sum << endl;
	else cout << sum - 2*m << endl;
	return 0;
}
