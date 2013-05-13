#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n, i, j;
	cin>>n;
	if(n % 2 == 0) cout << -1 << endl;
	else {
		for(i=0;i<2;i++) {
			cout << 0;
			for(j=1;j<n;j++) {
				if(j % 2 == 0) cout << " " << j/2;
				else cout << " " << (j+n)/2;
			}
			cout << endl;
		}
		cout << 0;
		for(i=1;i<n;i++) cout << " " << i;
		cout << endl;
	}
	return 0;
}
