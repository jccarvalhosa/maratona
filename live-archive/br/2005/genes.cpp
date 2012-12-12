#include <stdio.h>

int rev[1000][2], R;

int final(int g)
{
    for(int i=0;i<R;i++)
    {
        if(g < rev[i][0] || g > rev[i][1]) continue;
        g = rev[i][0] + rev[i][1] - g;
    }
    return g;
}

int main()
{
    int N, Q, i, j, gene, teste=1;
    while(scanf("%d", &N) && N)
    {
        printf("Genome %d\n", teste++);
        scanf("%d", &R);
        for(i=0;i<R;i++) scanf("%d%d", &rev[i][0], &rev[i][1]);
        scanf("%d", &Q);
        for(i=0;i<Q;i++)
        {
            scanf("%d", &gene);
            printf("%d\n", final(gene));
        }
    }
    return 0;
}
