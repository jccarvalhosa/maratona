#include <stdio.h>
#include <string.h>
#define N 9

int s[N][N], times;
int line[N][10], col[N][10], quad[N][10];
int nquad[N][N];

int valid(int a, int b, int v)
{
    if(line[a][v]) return 0;
    if(col[b][v]) return 0;
    if(quad[nquad[a][b]][v]) return 0;
    return 1;
}

void mark(int a, int b, int v, int m)
{
    line[a][v] = m;
    col[b][v] = m;
    quad[nquad[a][b]][v] = m;
}

int solve(int a, int b)
{
    int i;
    times++;
    if(a >= N) return 1;
    if(b >= N) return solve(a+1, 0);
    if(s[a][b]) return solve(a, b+1);
    for(i=1;i<10;i++) if(valid(a, b, i))
    {
        s[a][b] = i;
        mark(a, b, i, 1);
        if(solve(a, b+1)) return 1;
        mark(a, b, i, 0);
    }
    s[a][b] = 0;
    return 0;
}

int main()
{
    int K, i, j, k, t;
    char c[20][20];
    times = 0;
    scanf("%d", &K);
    for(t=0;t<K;t++)
    {
        for(i=0;i<N;i++) for(j=0;j<10;j++) line[i][j] = col[i][j] = quad[i][j] = 0;
        for(i=0;i<N;i++) scanf("%s", c[i]);
        for(i=0;i<N;i++) for(j=0;j<N;j++)
        {
            nquad[i][j] = (i/3)*3 + j/3;
            s[i][j] = c[i][j] - '0';
            if(s[i][j]) mark(i, j, s[i][j], 1);
        }
        solve(0, 0);
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++) printf("%d", s[i][j]);
            printf("\n");
        }
        printf("times: %d\n", times);
    }
    return 0;
}
