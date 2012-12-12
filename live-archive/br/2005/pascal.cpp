#include <stdio.h>

int main()
{
    int i, j, n, d, m[500][500], flag;
    while(scanf("%d%d", &d, &n) && n)
    {
        for(i=0;i<n;i++) for(j=0;j<d;j++) scanf("%d", &m[i][j]);
        flag = 0;
        for(j=0;j<d;j++)
        {
            for(i=0;i<n;i++) if(m[i][j] == 0) break;
            if(i == n) flag = 1;
        }
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
