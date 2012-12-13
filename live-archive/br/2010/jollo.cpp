#include <cstdio>

int a[3], b[3];
int p[6][3] = {0, 1, 2, 0, 2, 1, 1, 0, 2, 1, 2, 0, 2, 0, 1, 2, 1, 0};

int valid() {
    int n, i, j, k;
    for(i=0;i<6;i++) for(j=0;j<6;j++) {
        for(n=k=0;k<3;k++) if(b[p[i][k]] > a[p[j][k]]) n++;
        if(n < 2) return 0;
    }
    return 1;
}

int main() {
    int i;
    while(scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &b[0], &b[1]) && a[0]) {
        for(i=1;i<=52;i++) {
            if(i == a[0] || i == a[1] || i == a[2] || i == b[0] || i == b[1]) continue;
            b[2] = i;
            if(valid()) break;
        }
        printf("%d\n", i != 53 ? i : -1);
    }
    return 0;
}
