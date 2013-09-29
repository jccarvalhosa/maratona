#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-6
using namespace std;

int main() {
	int n, t;
	cin >> t;
	while(t--) {
		int ret = 0;
		int x, y;
		cin >> n;
		for(int i=0;i<n;i++) {
			cin >> x >> y;
			double r = hypot(x,y);
			double d = r/20;
			if(x == 0 && y == 0) ret += 10;
			else ret += max(0.0,11-(ceil(d)));
		}
		cout << ret << endl;
	}
	return 0;
}
