#include <cstdio>
#define INF 1000000000000000000
typedef long long ll;

ll div[5000000];

int main() {
    int t, d, i;
    ll x, y, n, m, sol;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld", &x, &y);
        y -= 2;
        if(x - y == 0) printf("%lld\n", y+1);
        else {
            n = x-y;
            d = 0;
            for(m=1;m*m<=n;m++) if(n % m == 0) div[d++] = m, div[d++] = n/m;
            sol = INF;
            for(i=0;i<d;i++) if(div[i] > y && div[i] < sol) sol = div[i];
            if(sol != INF) printf("%lld\n", sol);
            else printf("Impossible\n");
        }
    }
    return 0;
}
