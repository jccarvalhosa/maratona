#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll x, y, m, n=0;
	int i;
	cin>>x>>y>>m;
	if(x>=m||y>=m) {
		cout << 0 << endl;
		return 0;
	}
	if(x<=0 && y<=0) {
		cout << -1 << endl;
		return 0;
	}
	if(x>y) swap(x, y);
	if(x<0) {
		x *= -1;
		n = x/y;
		x = x%y;
		if(x%y != 0) {
			x = y - x;
			n++;
		}
	}
	while(y<m) {
		ll aux = y+x;
		x=y;
		y=aux;
		n++;
	}
	cout << n << endl;
	return 0;
}
