#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, i, j, d, elem[20], obj[20], flag, ord[10000];
    while(scanf("%d", &N) && N) {
        flag = 0;
        for(i=0;i<N;i++) obj[i] = -1;
        for(i=0;i<N;i++) {
            scanf("%d", &d);
            if(obj[d-1] != -1) flag = 1;
            obj[d-1] = i;
        }
        if(flag == 1) printf("No solution\n");
        else {
            M = 0;
            for(i=0;i<N;i++) elem[i] = i;
            for(i=0;i<N;i++) {
                if(elem[i] != obj[i]) {
                    for(j=i+1;j<N;j++) if(elem[j] == obj[i]) break;
                    for(;j != i;j--) {
                        ord[M++] = j;
                        swap(elem[j], elem[j-1]);
                    }
                }
            }
            printf("%d", M);
            for(i=0;i<M;i++) printf(" %d", ord[i]);
            printf("\n");
        }
    }
    return 0;
}
