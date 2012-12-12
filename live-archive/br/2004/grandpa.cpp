#include <stdio.h>
#include <algorithm>
#define MAX 100001

using namespace std;

int main()
{
    int i, p, N, M, P[MAX], pmax;
    while(scanf("%d%d", &N, &M) && N) {
        for(i=1;i<MAX;i++) P[i]=0;
        for(i=0;i<N*M;i++) scanf("%d", &p), P[p]++;
        pmax = p = 0;
        for(i=1;i<MAX;i++) pmax = max(pmax, P[i]);
        for(i=1;i<MAX;i++) if(P[i] != pmax) p = max(p, P[i]);
        for(i=1;i<MAX;i++) if(P[i] == p) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
