#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct seg { ll x, y, l; };
const int N=50010;
seg v[N];
seg h[N];

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>v[i].x>>v[i].y>>v[i].l;
	for(int i=0;i<m;i++) cin>>h[i].x>>h[i].y>>h[i].l;
	ll ans=0;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		ll lx = min(v[i].x - h[j].x, h[j].x + h[j].l - v[i].x);
		ll ly = min(h[j].y - v[i].y, v[i].y + v[i].l - h[j].y);
		ans = max(ans, min(lx, ly));
	}
	cout<<ans<<endl;
	return 0;
}
