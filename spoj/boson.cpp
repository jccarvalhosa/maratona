#include <stdio.h>
#define INF 1000000000

int mdc(int a, int b) { return a % b == 0 ? b : mdc(b, a % b); }
int mod(int a) { return a > 0 ? a : -a; }

int main()
{
    int a1, b1, c1, d1, a2, b2, c2, d2, p , q, m, n, h, t[2], teta;
    while(scanf("%d%d%d%d%d%d%d%d", &a1, &b1, &c1, &d1, &a2, &b2, &c2, &d2) && (a1 || b1 || c1 || d1 || a2 || b2 || c2 || d2)) {
        if(!b1 && !b2) {
            printf("0 1\n");
            continue;
        }
        t[0] = INF;
        if(a1 && a2 && (b1 % a1 == 0) && (b2 % a2 == 0) && b1*a1 <= 0 && a1*b2 == a2*b1) {
            p = mod(b1);
            q = mod(a1);
            m = mdc(p, q);
            p /= m; q /= m;
            t[0]=p, t[1]=q;
        }
        p = b2 - b1;
        q = a1 - a2;
        if(!p && !q) {
            n = c1 - c2;
            h = d1 - d2;
            
        }
        else if(!p || p*q > 0) {
                p = mod(p); q = mod(q);
                m = mdc(p, q);
                p /= m; q /= m;
                n = c1 - c2;
                h = d1 - d2;
                if((n*p) % q == 0) {
                    teta = n*p/q + h;
                    if(teta % 360 == 0) t[0]=p, t[1]=q;
                }
        }
        p = -b2 - b1;
        q = a1 + a2;
        if(!p && !q) {
        }
        else if(!p || p*q > 0) {
                p = mod(p); q = mod(q);
                m = mdc(p, q);
                p /= m; q /= m;
                n = c1 - c2;
                h = d1 - d2;
                if((n*p) % q == 0) {
                    teta = n*p/q + h;
                    if(mod(teta % 360) == 180 && (t[0] == INF || p*t[1] < q*t[0])) t[0]=p, t[1]=q;
                }
        }
        if(t[0] == INF) printf("0 0\n");
        else printf("%d %d\n", t[0], t[1]);
    }
    return 0;
}
