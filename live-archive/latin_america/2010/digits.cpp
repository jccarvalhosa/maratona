#include <cstdio>
#include <cstring>

int c[2][10], p10[10], num[10];

void count(int x, bool up) {
    int *cnt = c[up], d, p, n=0, i;
    for(p=0;x; p++) {
        d = x % 10; x /= 10;
        if(p) for(i=0;i<10;i++) cnt[i] += d * p10[p-1] * p;
        for(i=0;i<d;i++) cnt[i] += p10[p];
        cnt[d] += n + 1;
        n += p10[p] * d;
    }
    for(i=0;i<p;i++) cnt[0] -= (p-i) * num[i];
}

int main() {
    int a, b, i;
    p10[0] = num[0] = 1;
    for(i=1;i<10;i++) p10[i] = 10*p10[i-1];
    for(i=1;i<10;i++) num[i] = 9*p10[i-1];
    while(scanf("%d%d", &a, &b) && a) {
        memset(c, 0, sizeof(c));
        count(b, 1);
        count(a-1, 0);
        for(i=0;i<10; i++) {
            if(i) printf(" ");
            printf("%d", c[1][i] - c[0][i]);
        }
        printf("\n");
    }
    return 0;
}
