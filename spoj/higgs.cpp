#include <stdio.h>
#define INF 1000000000

int mdc(int a, int b) { return a % b == 0 ? b : mdc(b, a % b); }
int mod(int a) { return a > 0 ? a : -a; }

int t[2], m;

int valido(int c1, int d1, int c2, int d2, int p, int q, int tipo) {
    if(tipo == 0) return 1;
    if(tipo == 1) return ((c1-c2)*p/q + (d1-d2)) % 360 == 0;
    if(tipo == 2) return mod(((c1-c2)*p/q + (d1-d2)) % 360) == 180;
}

void trata(int c1, int d1, int c2, int d2, int p, int q, int tipo) {
    if(p != INF) { if(p*t[1] < q*t[0] && valido(c1, d1, c2, d2, p, q, tipo)) t[0]=p, t[1]=q; }
    else {
        if(tipo == 0) t[0]=0, t[1]=1;
        else {
            if(c1 == c2) { if(valid(c1, d1, c2, d2, 0, 1, tipo)) t[0]=0, t[1]=1; }
            else {
                q = c1 - c2;
                if(tipo == 1) p = ((d1 - d2) % 360 + 360) % 360;
                if(tipo == 2) p = ((d1 - d2 - 180) % 360 + 360) % 360;
                if(q < 0) p = 360 - p;
                if(p*q >= 0) {
                    p = mod(p); q = mod(q);
                    m = mdc(p, q);
                    t[0]=p/m, t[1]=q/m;
                }
            }
        }
    }
}

int main()
{
    int a1, b1, c1, d1, a2, b2, c2, d2, p , q;
    while(scanf("%d%d%d%d%d%d%d%d", &a1, &b1, &c1, &d1, &a2, &b2, &c2, &d2) && (a1 || b1 || c1 || d1 || a2 || b2 || c2 || d2)) {
        t[0] = INF;
        p = a1 
        if(t[0] == INF) printf("0 0\n");
        else printf("%d %d\n", t[0], t[1]);
    }
    return 0;
}
