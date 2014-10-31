#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

double gcd(double a, double b) {
	if(b < 0.5) return a;
	return gcd(b, fmod(a, b));
}

ll egcd(ll a, ll b, ll &x, ll &y) {
	ll g = a;
	x = 1; y = 0;
	if(b) {
		g = egcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
	return g;
}

int main() {
	ll a, b, s;
	while(scanf("%lld%lld%lld", &a, &b, &s) != EOF) {
		if(!a && !b) {
			printf("%s\n", s==0 ? "YES" : "NO");
			continue;
		} 
		if(!a) {
			printf("%s\n", s%b==0 ? "YES" : "NO");
			continue;
		} 
		if(!b) {
			printf("%s\n", s%a==0 ? "YES" : "NO");
			continue;
		} 
		ll x, y;
		ll g = egcd(a, b, x, y);
		if(s%g) {
			printf("NO\n");
			continue;
		}
		a /= g;	b /= g;	s /= g;
		double X = x, Y = y;
		X *= s;	Y *= s;
		double NX = fmod(fmod(X*s, b) + b, b);
		Y -= (NX-X)/b*a;
		X = NX;
		int ok=0;
		while(Y > 0.5) {
			if(X > 0.5) {
				double g = gcd(X, Y);
				if(fabs(g-1) < 0.5) {
					printf("YES\n");
					ok=1;
					break;
				}
			}
			x += b;
			y -= a;
		}
		if(!ok) {
			printf("NO\n");
		}
	}
	return 0;
}
