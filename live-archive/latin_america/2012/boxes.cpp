#include <stdio.h>
#include <string.h>

int pd[101][201][201];

int main() {
    int i, j, k, l, n, b;
    memset(pd, 0, sizeof(pd));
    pd[1][0][0] = 1;
    for(i=2;i<=100;i++) for(j=0;j<=200;j++) for(k=0;k<=200-j;k++) for(l=0;l<=j;l++)
        pd[i][j][k] = (pd[i][j][k] + pd[i-1][j-l][(k+l)/2]) % 1000000007;
    while(scanf("%d%d", &n, &b)!=EOF) printf("%d\n", pd[b][n][0]);
    return 0;
}
