#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

pair<ll, ll> dp[1<<20];

int main() {
    int i, j, n, m, aux=1;
    ll f[22], c[22], v, t;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%lld %lld", &f[i], &c[i]);
    for(i=1;i<(1<<n);i++) dp[i].first=dp[i].second=0;
    for(i=1;i<(1<<n);i++) for(j=0;j<n;j++) if(i&(1<<j)) {
        dp[i].first+=c[j];
        dp[i].second+=f[j];
    }
    sort(dp, dp+(1<<n));
    scanf("%d", &m);
    for(i=0;i<m;i++) {
        scanf("%lld %lld", &v, &t);
        ll cmin;
        for(j=1;j<(1<<n);j++) if(dp[j].second*t>=v) {
            cmin=dp[j].first;
            break;
        }
        printf("Case %d: ", i+1);
        if(j==(1<<n)) printf("IMPOSSIBLE\n");
        else printf("%lld\n", cmin);
    }
    return 0;
}
