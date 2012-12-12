#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 1e9 

using namespace std;

int N, M, lista[100], id[100000]; 
double pd[100][100000], pdmin[100][100000], valor[100000];

int main()
{
    int i, j;
    while(scanf("%d%d", &M, &N) && N) {
        for(i=0;i<M;i++) for(j=0;j<N;j++) pd[i][j] = pdmin[i][j] = INF;
        for(i=0;i<M;i++) scanf("%d", &lista[i]);
        for(i=0;i<N;i++) scanf("%d%lf", &id[i], &valor[i]);
        for(i=0;i<N;i++) {
            if(id[i] == lista[0]) pd[0][i] = valor[i];
            if(i > 0) pdmin[0][i] = min(pdmin[0][i-1], pd[0][i]);
            else pdmin[0][i] = pd[0][i];
        }
        for(i=1;i<M;i++) for(j=i;j<N;j++) {
            if(id[j] == lista[i]) pd[i][j] = valor[j] + pdmin[i-1][j-1];
            pdmin[i][j] = min(pdmin[i][j-1], pd[i][j]);
        }
        double resp = INF;
        for(j=0;j<N;j++) resp = min(resp, pd[M-1][j]);
        if(resp >= INF) printf("Impossible\n");
        else printf("%.2lf\n", resp);
    }
    return 0;
}
