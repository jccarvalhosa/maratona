#include <stdio.h>
#define MOD 1300031

long long mdc(long long a, long long b) {
    if((a % b) == 0) return b;
    return mdc(b, a % b);
}

long long mmc(long long a, long long b) { return a * b / mdc(a, b); }

long long pa(long long ini, long long fim, long long delta) {
    long long first, last, n;
    last = fim - fim % delta;
    if((ini % delta) == 0) first = ini;
    else first = ini + delta - (ini % delta);
    n = (last - first) / delta + 1;
    if(last < first) return 0;
    return ((first + last) * n / 2) % MOD;
}

int main()
{
    int T, i, j, ini, fim, n, count, div[20];
    long long sum, num;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &ini, &fim, &n);
        for(i=0;i<n;i++) scanf("%d", &div[i]);
        sum = 0;
        for(i=1;i<1<<n;i++) {
            count = 0;
            num = 1;
            for(j=0;j<n;j++) {
                if(i & (1<<j)) {
                    count++;
                    num = mmc(num, div[j]);
                    if(num > fim) break;
                }
            }
            if(j != n) continue;
            if(count % 2 == 1) sum = (sum + pa(ini, fim, num)) % MOD;
            else sum = (sum - pa(ini, fim, num) + MOD) % MOD;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
