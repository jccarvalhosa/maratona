#include <cstdio>
#include <iostream>
#include <algorithm>
#define INF 1000000
using namespace std;
typedef long long ll;

ll mod(ll a) { return a > 0 ? a : -a; }
ll mdc(ll a, ll b) { return a%b ? mdc(b, a%b): b; }

struct frac {
	ll n, d;
	frac(ll a=0, ll b=1): n(a), d(b) {
		ll m = mdc(mod(n), mod(d)) * mod(d)/d;
		n /= m;
		d /= m;
	}
    frac operator+(frac f) { return frac(n*f.d + f.n*d, d*f.d); }
    frac operator-(frac f) { return *this + frac(-f.n, f.d); }
    frac operator*(frac f) { return frac(n*f.n, d*f.d); }
    bool operator <(const frac &f)const { return n * f.d < f.n * d; }
    friend ostream& operator <<(ostream& o, frac f) { return o << f.n << "/" << f.d; }
};

frac ini, best, sol;

void test(int n, int d) {
	frac aux = frac(n, d), diff = aux - ini;
	diff.n = mod(diff.n);
	if(diff < best) {
		best = diff;
		sol = aux;
	}
}

int main() {
	int n, d, v, x, y;
	scanf("%d%d%d", &x, &y, &v);
	ini = frac(x, y);
	best = frac(INF, 1);
	for(d=1;d<=v;d++) {
		n = 1ll*x*d/y;
		test(n, d);
		test(n+1, d);
	}
	cout << sol << endl;
	return 0;
}
