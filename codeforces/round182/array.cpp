#include <iostream>
#include <algorithm>
using namespace std;

int sp=0, sn=0;

int main() {
	int n, m, i, a, l, r;
	cin>>n>>m;
	for(i=0;i<n;i++) {
		cin>>a;
		if(a == 1) sp++;
		if(a == -1) sn++;
	}
	for(i=0;i<m;i++) {
		cin>>l>>r;
		a = r - l + 1;
		if(a % 2 == 1) cout << 0 << endl;
		else {
			a /= 2;
			if(min(sp, sn) >= a) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}
