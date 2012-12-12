#include <stdio.h>
#include <algorithm>

using namespace std;

int main() 
{
    int T, N, i, j;
    int pd[100000], x[100000], y[100000];
    scanf("%d", &T);
    while(T--) 
    {
        scanf("%d", &N);
        for(i=0;i<N;i++) {
            scanf("%d%d", &x[i], &y[i]);
            pd[i] = 1;
        }
        for(i=0;i<N;i++) for(j=i+1;j<N;j++) if(x[i] <= x[j] && y[i] <= y[j]) pd[j] = max(pd[j], pd[i] + 1);
        int maxv = 0;
        for(i=0;i<N;i++) maxv = max(maxv, pd[i]);
        printf("%d\n", maxv);
    }
    return 0;
}
