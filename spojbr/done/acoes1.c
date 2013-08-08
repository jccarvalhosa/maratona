#include <stdio.h>

int val[1000001];

int main()
{
    int N, K, i;
    while(scanf("%d%d", &N, &K) && N) {
        val[0] = 0;
        for(i=1;i<=K;i++) val[i] = 1;
        for(i=K+1;i<=N;i++) {
            if(i % 2 == 0) val[i] = 2*val[i/2];
            else val[i] = val[i/2]+val[(i+1)/2];
        }
        printf("%d\n", val[N]);
    }
    return 0;
}
