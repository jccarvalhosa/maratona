#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int n, x[111111];

int solve() {
	if(n<=2) return 0;
	int m = *max_element(x,x+n);
	int s = accumulate(x,x+n,0);
	if(m >= 2*(s-m)) return s-m;
	return s/3;
}

int main() {
	while(cin>>n && !cin.eof()) {
		for(int i=0;i<n;i++) cin>>x[i];
		cout << solve() << endl;
	}
	return 0;
}
