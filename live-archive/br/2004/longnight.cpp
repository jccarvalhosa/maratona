#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 1000000000

using namespace std;

int N;

int nbits(int a) {
    int i, ret = 0;
    for(i=0;i<20;i++) if(a & 1<<i) ret++;
    return ret;
}

int pd[20][1<<20];
int nvis[1<<20];

int main()
{
    int t[20], M[20][20];
    int i, j, k, cmax;
    for(j=1;j<1<<20;j++) nvis[j] = nbits(j);
    while(scanf("%d", &N) && N)
    {
        for(i=0;i<N;i++) scanf("%d", &t[i]);
        for(i=0;i<N;i++) for(j=0;j<N;j++) scanf("%d", &M[i][j]);
        for(i=0;i<N;i++) for(j=0;j<N;j++) M[i][j] += t[j];
        for(i=0;i<N;i++) for(j=0;j<N;j++) for(k=0;k<N;k++) M[i][k] = min(M[i][k], M[i][j]+M[j][k]);
        for(i=0;i<N;i++) for(j=1;j<1<<N;j++) pd[i][j] = INF;
        for(i=0;i<N;i++) pd[i][1<<i] = M[i][i];

        for(i=0;i<N;i++) for(j=1;j<1<<N;j++) if((j & 1<<i) && pd[i][j] <= 420)
            for(k=0;k<N;k++) if((j & 1<<k) == 0)
                pd[k][j + (1<<k)] = min(pd[k][j + (1<<k)], pd[i][j] + M[i][k]);
        
        cmax = 0;
        for(i=0;i<N;i++) for(j=1;j<1<<N;j++) if(pd[i][j] <= 420) cmax = max(cmax, nvis[j]);
        printf("%d\n", cmax);
    }
    return 0;
}
