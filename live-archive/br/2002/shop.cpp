#include <stdio.h>
#include <string.h>

int M, L, N, cont;
int v[2000], caixa[2000], vis[1001][1001];

int dfs(int n, int a, int b) {
    if(vis[a][b]) return 0;
    if(n == N-1) return 1;
    vis[a][b] = 1;
    if(a + v[n+1] <= M && dfs(n+1, a+v[n+1], b)) {
        caixa[n+1] = 0;
        cont++;
        return 1; 
    }
    if(b + v[n+1] <= L && dfs(n+1, a, b+v[n+1])) {
        caixa[n+1] = 1;
        return 1;
    }
    return 0;
}

int main()
{
    int i, j;
    while(scanf("%d%d", &M, &L) && (M || L)) {
        scanf("%d", &N);
        for(i=0;i<N;i++) scanf("%d", &v[i]);
        for(i=0;i<=M;i++) for(j=0;j<=L;j++) vis[i][j] = 0;
        cont = 0;
        if(dfs(-1, 0, 0)) {
            printf("%d ", cont);
            for(i=0;i<N;i++) if(caixa[i] == 0) printf("%d ", i+1);
            printf("\n");
        }
        else printf("Impossible to distribute\n");
    }
}
