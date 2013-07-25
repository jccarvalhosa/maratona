#include <iostream>
using namespace std;
typedef long long ll;

const int M=10001;

int x[11111];

struct euclides {
    ll m, x, y;
    euclides(ll m=0, ll x=0, ll y=0): m(m), x(x), y(y) {}
};

int mod(int a) { return (a%M + M)%M; }

int mdc(int a, int b) { return b?mdc(b, a%b) : a; }

struct euclides emdc(int a, int b) {
    if(a==0) return euclides(b, 0, 1);
    struct euclides e = emdc(b%a, a);
    return euclides(e.m, e.y - b/a*e.x, e.x);
};

int inv(int a) { return mod(emdc(a, M).x); }

int main() {
    int a, b, n, i;
    cin>>n;
    for(i=0;i<n;i++) cin>>x[i];
    for(a=0;a<M;a++) {
        int k = inv(a+1);
        int m = mdc(a+1, M);
        int t = (mod(x[1] - mod(a*a) * x[0]));
        if((t*k)%m != 0) continue;
        b = (t*k/m)%M;
        for(i=1;i<n;i++) if(mod(x[i]) != mod(mod(a*a)*x[i-1] + mod(a*b) + b)) break;
        if(i != n) continue;
        else break;
    }
    //cout<<a<<" "<<b<<endl;
    int t = x[0];
    for(i=1;i<2*n;i++) {
        t = (a*t+b)%M;
        if(i%2==1) cout<<t<<endl;
    }
    return 0;
}
