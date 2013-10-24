#include <vector>
#include <complex>
#include <algorithm>
#include <iostream>
#define INF (ll)1e8
using namespace std;
typedef long long ll;
typedef complex<ll> pt;
#define x real()
#define y imag()

vector<pt> p;

ll cross(pt a, pt b) { return imag(conj(a)*b); }
ll dot(pt a, pt b) { return real(conj(a)*b); }
bool left(pt a, pt b, pt c) { return cross(a-b, c-b)<0; }
bool between(pt a, pt b, pt c) { 
	if(cross(a-b, c-b)) return false;
	ll A = dot(a-b, c-b);
	ll B = dot(c-b, c-b);
	return A>=0 && A<=B;
}

bool cart(pt a, pt b, pt c, pt d) { return (left(d, a, c) != left(d, b, c) && left(c, a, b) != left(d, a, b)); }

int in_poly(pt p, vector<pt> T) {
    for(int i=0;i<T.size();i++) if(between(p, T[i], T[(i+1)%T.size()])) return -1;
	int n = 0;
	pt ref = pt(INF, INF);
	for(int i=0;i<T.size();i++) n += cart(T[i], T[(i+1)%T.size()], p, ref);
	return n % 2;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cout << "Case #"<<t<<":"<<endl;
		int n;
		cin>>n;
		p.resize(n+1);
		for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
		int R;
		cin>>R;
		for(int i=0;i<R;i++) {
			cout << "Region " <<i+1<<endl;
			int b;
			cin>>b;
			vector<pt> poly(b);
			for(int j=0;j<b;j++) cin>>poly[j].x>>poly[j].y;
			vector<int> tmp;
			for(int j=1;j<=n;j++) if(in_poly(p[j], poly)) tmp.push_back(j);
			int q;
			cin>>q;
			while (q--) {
				pt u;
				cin>>u.x>>u.y;
				ll mx1=norm(u-p[tmp[0]]);
				ll mx2=norm(u-p[tmp[1]]);
				ll r1=tmp[0], r2=tmp[1];
				if (mx1>mx2) {
					swap(mx1, mx2);
					swap(r1, r2);
				}
				for (int i=2; i<tmp.size(); i++) {
					ll dist=norm(u-p[tmp[i]]);
					if (dist<mx1) {
						mx2=mx1, r2=r1;
						mx1=dist, r1=tmp[i];
					} else if (dist<mx2) {
						mx2=dist, r2=tmp[i];
					}
				}
				cout << r1 << " " << r2 << endl;
			}
		}
	}
	return 0;
}
