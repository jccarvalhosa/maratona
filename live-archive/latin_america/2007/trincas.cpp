#include <stdio.h>
#include <vector>

using namespace std;

int c[2][14], smax, cont;

void calcula(int soma, int ini, int i)
{
    int j, k, l, inik, inil;
    if(smax < soma) smax = soma;
    for(j=ini;j<13;j++) if(c[i][j]) for(k=j;k<=13;k++) if(c[i][k]) for(l=k;l<=13;l++) if(c[i][l] && j+k > l)
    {
        c[i][j]--; c[i][k]--; c[i][l]--;
        if(c[i][j] >= 0 && c[i][k] >= 0 && c[i][l] >= 0) calcula(soma+1, j, i);
        c[i][j]++; c[i][k]++; c[i][l]++;
    }
}

int main()
{
    int N, i, j, k, l, a, b;
    int ot[2], val[2];
    while(scanf("%d", &N) && N)
    {
        ot[0] = ot[1] = 0;
        for(i=1;i<=13;i++) c[0][i] = c[1][i] = 0;
        for(i=0;i<N;i++) scanf("%d", &a), c[i%2][a]++;
        for(j=0;j<=1;j++) for(i=1;i<=13;i++) 
        {
            ot[j] += c[j][i] / 3;
            c[j][i] %= 3;
        }
        if(ot[0] > ot[1]) printf("1\n");
        else if(ot[1] > ot[0]) printf("2\n");
        else
        {
            smax = 0, calcula(0, 1, 0), val[0] = smax; 
            smax = 0, calcula(0, 1, 1), val[1] = smax;
            if(val[0] > val[1]) printf("1\n");
            else if(val[1] > val[0]) printf("2\n");
            else printf("0\n");
        }
    }
    return 0;
}
