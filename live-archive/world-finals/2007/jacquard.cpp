#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

vector<pair<ll, ll> > p;

ll mod(ll a) { return a>0 ? a : -a; }

ll cross(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc) { return (xa-xb)*(yc-yb)-(xc-xb)*(ya-yb); }

int main()
{
	int i, n, m, t=1;
	ll x, y, xmin, ymin;
	while(scanf("%d %d", &n, &m) && (n || m))
	{
		p.clear();
		ll a=0;
		xmin=ymin=1e9;
		for(i=0; i<n; i++)
		{
			scanf("%lld %lld", &x, &y);
			if(xmin>x) xmin=x, ymin=y;
			else if(xmin==x && ymin>y) ymin=y;
			p.push_back(make_pair(x, y));
		}
		for(i=1; i<n; i++) if(!cross(p[i-1].first, p[i-1].second, p[i].first, p[i].second, p[(i+1)%n].first, p[(i+1)%n].second)) p.erase(p.begin()+i), n--, i--;
		for(i=0; i<n; i++) p[i].first-=xmin, p[i].second-=ymin;
		ll mdc=0;
		for(i=0; i<n; i++) mdc=__gcd(mdc, __gcd(mod(p[i].first), mod(p[i].second)));
		for(i=0; i<n; i++) p[i].first/=mdc, p[i].second/=mdc;
		for(i=0; i<n; i++) a+=(p[i].first*p[(i+1)%n].second-p[i].second*p[(i+1)%n].first);
		a = mod(a);
		ll b=0;
		for(i=0; i<n; i++) b+=__gcd(mod(p[i].first-p[(i+1)%n].first), mod(p[i].second-p[(i+1)%n].second));
		ll ans=(a+2-b)/2;
		for(i=2; i<=m; i++)
		{
			ll area=a*i*i;
			ll bound=b*i;
			ans+=(area+2-bound)/2;
		}
		printf("Case %d: %lld\n", t++, ans);
	}
	return 0;
}
