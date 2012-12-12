#include <stdio.h>
#define MAXL 102

int R, C, g, vis[MAXL][MAXL], grupo[MAXL][MAXL], bloqueado[MAXL*MAXL];
char M[MAXL][MAXL];

void go(int r, int c, int dir)
{
    int i, j;
    vis[r][c] = 1;
    grupo[r][c] = g;
    if(dir == 0) M[r][c] = '(';
    else M[r][c] = ')';
    for(i=-1;i<=1;i++) for(j=(-i-2)/2;j<=(-i+2)/2;j++) if((i != 0 || j != 0) && M[r+i][c+j] != '.')
    {
        if(dir == 0 && (M[r+i][c+j] == '(' || M[r+i][c+j] == 'I')) bloqueado[g] = 1;
        if(dir == 1 && M[r+i][c+j] == ')') bloqueado[g] = 1;
        if(!vis[r+i][c+j]) go(r+i, c+j, (dir + 1) % 2);
    }
}

int main()
{
    int i, j;
    while(scanf("%d%d", &R, &C) && R)
    {
        g = 0;
        for(i=0;i<=R+1;i++) for(j=0;j<=C+1;j++) M[i][j] = '.', vis[i][j] = 0;
        for(i=1;i<=R;i++) for(j=1;j<=C;j++) scanf(" %c ", &M[i][j]);
        for(i=1;i<=R;i++) for(j=1;j<=C;j++) if(!vis[i][j] && M[i][j] == 'I')
        {
            bloqueado[g] = 0;
            go(i, j, 0);
            g++;
        }
        for(i=1;i<=R;i++)
        {
            for(j=1;j<=C;j++)
            {
                if(M[i][j] == '*') printf("F");
                else if(vis[i][j] && bloqueado[grupo[i][j]]) printf("B");
                else printf("%c", M[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
