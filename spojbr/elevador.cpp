#include <stdio.h>

unsigned long long M[20][10];

unsigned long long f(unsigned long long N)
{
    int i=-1, alg[20];
    int flag1, flag4;
    unsigned long long soma;
    while(N != 0)
    {
        alg[++i] = N % 10;
        N /= 10;
    }
    soma = flag1 = flag4 = 0;
    while(i >= 0)
    {
        if(flag1 == 1 && alg[i] < 3) flag1 = 0;
        if(alg[i] == 4) flag4 = 1;
        if(alg[i] == 1) flag1 = 1;
        while(alg[i] > 0)
        {
            if(flag1 == 1 && alg[i] == 3)
            {
                alg[i]--;
                flag1 = 0;
                continue;
            }
            soma += M[i][--alg[i]];
        }
        if(flag4 == 1) return soma - 1;
        i--;
    }
    return soma;
}

int main()
{
    unsigned long long N, resp, val;
    int i, j;
    for(i=0;i<10;i++) M[0][i] = 1;
    M[0][4] = 0;
    for(i=1;i<19;i++)
    {
        M[i][0] = 0;
        for(j=0;j<10;j++) M[i][0] += M[i-1][j];
        for(j=1;j<10;j++) M[i][j] = M[i][0];
        M[i][1] -= M[i-1][3];
        M[i][4] = 0;
    }
    M[19][0] = 0;
    for(j=0;j<10;j++) M[19][0] += M[18][j];
    while(scanf("%llu", &N) != EOF)
    {
        resp = N;
        val = f(resp);
        while(val != N)
        {
            resp += N - val;
            val = f(resp);
        }
        printf("%llu\n", resp);
    }
    return 0;
}
