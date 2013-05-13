#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int mdc(int a, int b) { return !b ? a : mdc(b, a%b); }

int main() {
	int n, m, x, y, a, b, p, d, x1, y1, x2, y2;
	cin>>n>>m>>x>>y>>a>>b;
	d = mdc(a, b);
	a /= d;
	b /= d;
	p = min(n/a, m/b);
	a *= p;
	b *= p;
	if(x + a/2 > n) {
		x2 = n;
		x1 = n-a;
	}
	else if(x - a/2 < 0) {
		x1 = 0;
		x2 = a;
	}
	else {
		x2 = x+a/2;
		x1 = x2-a;
	}
	if(y + b/2 > m) {
		y2 = m;
		y1 = m-b;
	}
	else if(y - b/2 < 0) {
		y1 = 0;
		y2 = b;
	}
	else {
		y2 = y+b/2;
		y1 = y2-b;
	}
	
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

	return 0;
}
