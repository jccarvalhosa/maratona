#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 200000

using namespace std;

int idx[2*MAX+1], idy[2*MAX+1];
int vx[302], vy[302], v0x[302], v0y[302];
//B[i][j][k] -> 1 se tiver uma bomba em x=k entre os pontos y=i e y=j, 0 caso contrario
bool B[302][302][302];

int main()
{
    int N, i, j, k, x, y, xi, xf, yi, yf, mx, my, ini, fim, a, b, na, nb;
    while(scanf("%d%d%d%d", &xi, &yi, &xf, &yf) && (xi || yi || xf || yf)) {
        scanf("%d", &N);
        memset(idx, 0, sizeof(idx));
        memset(idy, 0, sizeof(idy));
        idx[xi+MAX] = idx[xf+MAX] = idy[yi+MAX] = idy[yf+MAX] = 1;
        for(i=0;i<N;i++) {
            scanf("%d%d", &x, &y);
            idx[x+MAX] = idy[y+MAX] = 1;
            v0x[i] = x; v0y[i]=y;
        }
        for(mx=i=0;i<=2*MAX;i++) if(idx[i]) {
            vx[mx] = i-MAX;
            idx[i] = mx++;
        }
        for(my=i=0;i<=2*MAX;i++) if(idy[i]) {
            vy[my] = i-MAX;
            idy[i] = my++;
        }
        for(i=0;i<my;i++) for(j=0;j<my;j++) for(k=0;k<mx;k++) B[i][j][k] = 0;
        for(i=0;i<N;i++) {
            y = idy[v0y[i]+MAX];
            x = idx[v0x[i]+MAX];
            B[y][y][x] = 1;
        }
        //tem uma bomba em x=k entre os pontos y=i e y=j se tem bomba entre y=i e y=j-1 ou se tem bomba em y=j
        for(i=0;i<my;i++) for(j=i+1;j<my;j++) for(k=0;k<mx;k++) B[i][j][k] = B[i][j-1][k] || B[j][j][k];
        a = b = 0;
        for(i=0;i<my;i++) for(j=i+1;j<my;j++) {
            ini = 0;
            for(fim=1;fim<mx;fim++) if(B[i+1][j-1][fim] || fim == mx-1) {
                na = vy[j] - vy[i];
                nb = vx[fim] - vx[ini];
                if(na > nb) swap(na, nb);
                if(na > a) a=na, b=nb;
                else if(na == a && nb > b) a=na, b=nb;
                ini = fim;
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}
