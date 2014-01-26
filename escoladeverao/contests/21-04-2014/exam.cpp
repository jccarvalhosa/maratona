#include <iostream>

using namespace std;

int ans[1111111];

int mod(int a) { return ((a>0)?a:-a);}

int main() {
	int n, k, ok = 1;
	cin >> n >> k;
	if(k > n/2) cout << "NIE" << endl;
	else {
		int p1 = (n+1)/2;
		int p2 = n;
		for(int i=0;i<n;i++) {
			if(i != 0) cout << " ";
			if(i%2==0) cout << p1--;
			else cout << p2--;
		}
		cout << endl;
	}
	return 0;
}
