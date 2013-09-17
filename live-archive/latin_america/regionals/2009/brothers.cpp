#include <cstdio>

int T[100][100][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    int N, R, C, K, i, j, k;
    while(scanf("%d%d%d%d", &N, &R, &C, &K) && N) {
        for(i=0;i<R;i++) for(j=0;j<C;j++) scanf("%d", &T[i][j][0]);
        for(k=1;k<=K;k++) {
            for(i=0;i<R;i++) for(j=0;j<C;j++) T[i][j][k] = T[i][j][k-1];
            for(i=0;i<R;i++) for(j=0;j<C;j++) for(int a=0;a<4;a++) {
                int ni = i + dx[a];
                int nj = j + dy[a];
                if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
                if(T[ni][nj][k-1] == (T[i][j][k-1] + 1) % N) T[ni][nj][k] = T[i][j][k-1];
            }
        }
        for(i=0;i<R;i++) {
            printf("%d", T[i][0][K]);
            for(j=1;j<C;j++) printf(" %d", T[i][j][K]);
            printf("\n");
        }
    }
    return 0;
}
