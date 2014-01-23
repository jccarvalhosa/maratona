#include <iostream>
using namespace std;
typedef long long ll;

struct pt {
	ll x, y, z;
	pt() {}
	pt(ll x, ll y, ll z) : x(x), y(y), z(z) {}
};

pt diff(pt a, pt b) { return pt(a.x-b.x, a.y-b.y, a.z-b.z); }

ll dot(pt a, pt b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
pt cross(pt a, pt b) { return pt(a.y*b.z - b.y*a.z, -(a.x*b.z - b.x*a.z), a.x*b.y - a.y*b.x); }

int main() {
	int T;
	cin>>T;
	while(T--) {
		pt a, b, c, u, w;
		cin>>a.x>>a.y>>a.z;
		cin>>b.x>>b.y>>b.z;
		cin>>c.x>>c.y>>c.z;
		cin>>u.x>>u.y>>u.z;
		cin>>w.x>>w.y>>w.z;
		pt n = cross(diff(b, a), diff(b, c));
		ll du = dot(diff(b, u), n);
		ll dw = dot(diff(b, w), n);
		if(dw == 0)
			cout<<"NIE"<<endl;
		else if((du > 0 && dw > 0) || (du < 0 && dw < 0))
			cout<<"TAK"<<endl;
		else
			cout<<"NIE"<<endl;
	}
	return 0;
}
