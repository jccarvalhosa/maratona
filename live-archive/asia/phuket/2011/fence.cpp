#include <cstdio>
#include <cmath>
typedef long long ll;

int main() {
	int dmin, dmax, rmin, rmax, s;
	while(scanf("%d%d%d%d%d", &rmin, &rmax, &dmin, &dmax, &s) && s) {
		ll ans=0;
		double PI = acos(-1);
		for(int d=dmin;d<=dmax;d++) for(int r=rmin;r<=rmax;r++) {
			ll w = 2*d+2*r;
			ll c = (w*s - PI*r*r)/(w*w - PI*r*r);
			ans += 2*c;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
