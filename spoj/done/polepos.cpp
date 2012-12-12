#include <stdio.h>

int main()
{
    int N, car[1000], i, flag, c, p;
    while(scanf("%d", &N) && N) {
        for(i=0;i<N;i++) car[i] = 0;
        flag = 0;
        for(i=0;i<N;i++) {
            scanf("%d%d", &c, &p);
            if(p+i < N && p+i >= 0 && !car[p+i]) car[p+i] = c;
            else flag=1;
        }
        if(flag) printf("-1\n");
        else {
            for(i=0;i<N;i++) printf("%d ", car[i]);
            printf("\n");
        }
    }
    return 0;
}
