#include <cstdio>
#include <iostream>
#include <algorithm>
#define INF 1000000
using namespace std;
typedef long long ll;

ll mod(ll a) { return a > 0 ? a : -a; }
ll mdc(ll a, ll b) { return a%b ? mdc(b, a%b): b; }
ll mmc(ll a, ll b) { return a*b/mdc(a, b); }

struct frac {
    ll n, d;
    frac(ll a=0, ll b=1): n(a), d(b) {
        ll m = mdc(mod(n), mod(d)) * (mod(d)/d);
        n /= m;
        d /= m;
    }
    frac operator+(frac f) { return frac(n*f.d + f.n*d, d*f.d); }
    frac operator-(frac f) { return *this + frac(-f.n, f.d); }
    frac operator*(frac f) { return frac(n*f.n, d*f.d); }
    bool operator <(const frac &f)const { return n * f.d < f.n * d; }
    bool operator ==(const frac &f)const { return n * f.d == f.n * d; }
    friend ostream& operator <<(ostream& o, frac f) { 
        if(f.n == INF) return o << "0 0";
        return o << f.n << " " << f.d; 
    }
};

ll a1, b1, c1, d1, a2, b2, c2, d2;
bool is_solution(frac t) {
    frac r1 = t*a1 + b1;
    frac r2 = t*a2 + b2;
    frac f = t*(c1-c2);
    ll teta = f.d == 1 ? mod(f.n + (d1-d2)) : -1;

    if(r1.n == 0 && r2.n == 0) return true;
    if(r1 == r2 && teta % 360 == 0) return true;
    if(r1 == r2*(-1) && teta % 360 == 180) return true;
    return false;
}

frac min_pos(frac t, frac delta) {
    while(t.d * t.n > 0) t = t - delta;
    while(t.d * t.n < 0) t = t + delta;
    return t;
}

frac sol;

void test(frac t) { if(is_solution(t) && t.d*t.n >= 0) sol = min(sol, t); }

int main()
{
    while(scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a1, &b1, &c1, &d1, &a2, &b2, &c2, &d2) && a1|b1|c1|d1|a2|b2|c2|d2) {
        sol = frac(INF, 1);
        test(frac(0, 1));
        if(a1 != a2) { test(frac(b2-b1, a1-a2)); }
        else if(b1 == b2 && c1 != c2) {
            frac t(d2-d1, c1-c2);
            frac delta(360, mod(c1-c2));
            test(min_pos(t, delta));
        }
        if(a1 + a2 != 0) { test(frac(-b2-b1, a1+a2)); }
        else if(b1 + b2 == 0 && c1 != c2) {
            frac t(180+d2-d1, c1-c2);
            frac delta(360, mod(c1-c2));
            test(min_pos(t, delta));
        }
        cout << sol << endl;
    }
    return 0;
}
