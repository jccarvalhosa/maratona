#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> pp;

struct seg { ll x, y, l; };
const int N=50010;

seg v[N];
pp h[N];
int n, m;

bool valid(ll t) {
	if(t==0) return 1;
	for(int i=0;i<n;i++) {
		ll ymin = v[i].y + t;
		ll ymax = v[i].y + v[i].l - t;
		if(ymin > ymax) continue;
		
		ll xmin = v[i].x-t;
		ll xmax = v[i].x+t;
		
		for(int j = lower_bound(h, h+m, pp(ymin, pii(0, 0))) - h;j<m;j++) {
			if(h[j].first > ymax) break;
			if(h[j].second.second <= xmin && h[j].second.second + h[j].second.first >= xmax) return 1;
		}
	}
	return 0;
}

int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>v[i].x>>v[i].y>>v[i].l;
	for(int i=0;i<m;i++) cin>>h[i].second.second>>h[i].first>>h[i].second.first;
	sort(h, h+m);
	ll i=0, f=1e12;
	while(i<f-1) {
		ll m = (i+f)/2;
		if(valid(m)) i=m;
		else f=m;
	}
	cout<<i<<endl;
	return 0;
}
