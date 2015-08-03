#include <iostream>
#include <algorithm>
using namespace std;

int x, r, c;

int solve() {
	if(x >= 7) return 0;
	if(x == 6 && min(r, c) <= 3) return 0;
	if(x == 5 && min(r, c) == 3 && max(r,c) == 5) return 0;
	if(x == 4 && min(r, c) <= 2) return 0;
	if(x >= 2*min(r,c)+1) return 0;
	if(x > max(r, c)) return 0;
	if(r*c % x) return 0;
	return 1;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>x>>r>>c;
		int win = solve();
		cout << "Case #"<<t<<": "<<(win ? "GABRIEL" : "RICHARD")<<endl;
	}
	return 0;
}
