#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;


struct pt {
	ll x, y;
	pt(ll x=0, ll y=0): x(x), y(y) {}
	ll operator %(pt p) { return x*p.y - y*p.x; }
};

typedef vector<pt> polygon;

int n;

ll poly_area(polygon T) {
	ll s=0;
	for(int i=0;i<n;i++) s += T[i] % T[(i+1)%n];
	return s;
}

ll boundary_points(polygon T) {
	ll s=0;
	for(int i=0;i<n;i++) {
		int j = (i+1)%n;
		ll dx = abs(T[i].x - T[j].x);
		ll dy = abs(T[i].y - T[j].y);
		if(dx==0) s += dy-1;
		else if(dy==0) s += dx-1;
		else s += __gcd(dx, dy)-1;
	}
	return s+n;
}

const int N=1e4+10;

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		vector<pt> v(n);
		for(int i=0;i<n;i++) cin>>v[i].x>>v[i].y;
		cout << (poly_area(v) - boundary_points(v))/2 + 1 << endl;
	}
	return 0;
}
