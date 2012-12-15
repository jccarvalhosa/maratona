#include <cstdio>

int mdc(int a, int b) { return !a ? b : mdc(b%a, a); }

int main() {
    int n, q, g, a, b, r, i, j;
    int v[100000];
    while(scanf("%d%d", &n, &q) && n) {
        for(i=0;i<n;i++) scanf("%d", &v[i]);
        g = v[1]-v[0];
        for(i=2;i<n;i++) g = mdc(g, v[i]-v[i-1]);
        g *= 2;
        for(i=0;i<q;i++) {
            if(i) printf(" ");
            scanf("%d%d", &a, &b);
            if(n == 1) printf("%c", a==b || a+b==2*v[0] ? 'Y' : 'N');
            else printf("%c", (a-b)%g == 0 ? 'Y': 'N');
        }
        printf("\n");
    }
    return 0;
}
