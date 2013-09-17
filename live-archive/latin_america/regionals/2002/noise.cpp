#include <stdio.h>
#include <algorithm>

using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

int L, s[400][400], t[400][400], aux[400][400];

void rotate() {
    int i, j;
    for(i=0;i<L;i++) for(j=0;j<L;j++) aux[j][L-i-1] = t[i][j];
    for(i=0;i<L;i++) for(j=0;j<L;j++) t[i][j] = aux[i][j];
}

void shift() {
    int i, j;
    for(i=0;i<L;i++) for(j=0;j<L;j++) aux[i][L-j-1] = t[i][j];
    for(i=0;i<L;i++) for(j=0;j<L;j++) t[i][j] = aux[i][j];
}

int main()
{
    int i, j, k, l;
    double resp, cont;
    while(scanf("%d", &L) && L) {
        resp = 0;
        for(i=0;i<L;i++) for(j=0;j<L;j++) scanf("%d", &s[i][j]);
        for(i=0;i<L;i++) for(j=0;j<L;j++) scanf("%d", &t[i][j]);
        for(l=0;l<2;l++) {
            shift();
            for(k=0;k<4;k++) {
                rotate();
                cont = 0;
                for(i=0;i<L;i++) for(j=0;j<L;j++) if(mod(t[i][j] - s[i][j]) <= 100) cont++;
                resp = max(resp, cont);
            }
        }
        printf("%.2lf\n", 100*resp/(L*L));
    }
    return 0;
}
