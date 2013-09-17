#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

vector<int> v;
int s[200][200], pd[200][200];

int main()
{
    int N, i, j, k, x, resp;
    double F;
    while(scanf("%d%lf", &N, &F) && N)
    {
        v.clear();
        for(i=0;i<N;i++) {
            scanf("%d", &x);
            v.push_back(x);
        }
        if(N == 1) printf("0.00\n");
        else {
            memset(pd, INF ,sizeof(pd));
            for(i=0;i<N;i++) {
                s[i][0] = v[i];
                for(j=1;j<N;j++) s[i][j] = s[i][j-1] + v[(i+j)%N];
            }
            for(i=0;i<N;i++) pd[i][0] = 0;
            for(j=1;j<N;j++) 
                for(k=0;k<j;k++)
                    for(i=0;i<N;i++)
                        pd[i][j] = min(pd[i][j], pd[i][k] + pd[(i+k+1)%N][j-k-1] + max(s[i][k], s[(i+k+1)%N][j-k-1]));
            resp = INF;
            for(i=0;i<N;i++) resp = min(resp, pd[i][N-1]);
            printf("%.2lf\n", resp*F);
        }
    }
    return 0;
}
