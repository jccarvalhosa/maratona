#include <stdio.h>

int main()
{
    int N, i, start;
    int v[10000];
    while(scanf("%d", &N) && N)
    {
        for(i=0;i<N;i++) scanf("%d", &v[i]);
        for(i=0;i<N;i++) if(v[i] == 1) break;
        if(i == N) printf("%d\n", (N+1)/2);
        else
        {
            start = i;
            int sum=0, tam=0;
            for(i=start; i <= N + start; i++)
            {
                if(v[i % N] == 0) tam++;
                else
                {
                    sum += tam/2;
                    tam = 0;
                }
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
