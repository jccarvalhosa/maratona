#include <stdio.h>

char name[26][10000];
int music[26];

int main()
{
    int N, Q, i, j, k, m, n, t;
    while(scanf("%d%d", &N, &Q) && N) {
        for(i=0;i<N;i++) scanf(" %s ", name[i]);
        while(Q--) {
            scanf("%d", &k); k--;
            if(N == 1) {
                printf("%s\n", name[0]);
                continue;
            }
            n = 1;
            t = N;
            while(k >= t) {
                n++;
                k -= t;
                t=n;
                for(i=0;i<n;i++) t*=N;
            }
            m = k / n;
            for(i=0;i<n;i++) {
                music[i] = m % N;
                m /= N;
            }
            printf("%s\n", name[music[n-1-k%n]]);
        }
        printf("\n");
    }
    return 0;
}
