#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int x, y, X, Y, s;
		cin>>x>>y>>X>>Y;
		if(x==X) {
			cout << "Case "<<t<<": 0 0 1 0"<<endl;
			continue;
		}
		int dx = x-X;
		int dy = y-Y;
		int a1 = 0, a2 = a1 + dy;
		if(a2 < 0) {
			a1 = -a2;
			a2 = 0;
		}
		int b1 = 0, b2 = b1 - dx;
		if(b2 < 0) {
			b1 = -b2;
			b2 = 0;
		}
		cout << "Case "<<t<<": "<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
	}
	return 0;
}
