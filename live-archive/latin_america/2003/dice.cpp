#include <stdio.h>

int main()
{
    int trap[3], sum[100000], prox[10], pos[10];
    int P, S, N, i, jog;
    while(scanf("%d%d", &P, &S) && P) 
    {
        scanf("%d%d%d", &trap[0], &trap[1], &trap[2]);
        scanf("%d", &N);
        int a, b;
        for(i=0;i<N;i++)
        {
            scanf("%d%d", &a, &b);
            sum[i] = a+b;
        }
        for(i=0;i<P;i++) prox[i]=1, pos[i]=0;
        jog=0;
        for(i=0;i<N;i++) {
            while(prox[jog] == 0) {
                prox[jog] = 1;
                jog = (jog+1) % P;
            }
            pos[jog] += sum[i];
            if(pos[jog] > S) break;
            if(pos[jog] == trap[0] || pos[jog] == trap[1] || pos[jog] == trap[2]) prox[jog] = 0;
            jog = (jog+1) % P;
        }
        printf("%d\n", jog+1);
    }
    return 0;
}
