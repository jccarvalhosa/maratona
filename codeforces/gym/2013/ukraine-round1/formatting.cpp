#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int digits(ll k) {
    int c = 0;
    if(k == 0) return 1;
    while(k) {
        k/=10;
        c++;
    }
    return c;
}

int main() {
    ll n, a, dp[22], p10[22];
    dp[0] = 0;
    p10[0] = 1;
    dp[1] = 10;
    p10[1] = 10;
    for(int i=2;i<11;i++) {
        p10[i] = p10[i-1]*10;
        dp[i] = dp[i-1] + i*(p10[i]-p10[i-1]);
    }
    cin >> n >> a;
    int k1=digits(a);
    int k2=digits(a+n);
    p10[0] = 0;
    ll v1 = dp[k1-1] + (a-p10[k1-1])*k1;
    ll v2 = dp[k2-1] + (a+n-p10[k2-1])*k2;
    cout << (v2-v1) << endl;
    return 0;
}
