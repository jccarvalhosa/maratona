#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, Q;
    vector<int> diag[1000];
    int vmax, vlow, vup, i, j, a, b;
    while(scanf("%d%d", &N, &M) && N)
    {
        for(i=0;i<N+M-1;i++) diag[i].clear();
        for(i=0;i<N;i++) for(j=0;j<M;j++)
        {
            scanf("%d", &a);
            diag[N+j-i-1].push_back(a);
        }
        scanf("%d", &Q);
        while(Q--)
        {
            vmax = vlow = 0;
            vup = 1;
            scanf("%d%d", &a, &b);
            for(i=0;i<N+M-1;i++)
            {
                if(vup > diag[i].size()) vup = diag[i].size();
                while(vlow < diag[i].size() && diag[i][vlow] < a) vlow++;
                while(vup > 0 && diag[i][vup-1] > b) vup--;
                if(vmax < vup - vlow) vmax = vup - vlow;
                if(vlow > 0) vlow--;
                vup++;
            }
            printf("%d\n", vmax);
        }
        printf("-\n");
    }
    return 0;
}
