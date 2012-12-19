#include <cstdio>
#define N 1000001
#define M 1001

int count[N+M], forbid[N+M];

int main() {
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    for(i=0;i<=n;i++) count[i] = forbid[i] = 0;
    for(i=0;i<=n;i++) {
        if(count[i] == 0) {
            for(j=1;j<=m;j++) {
                count[i+j]++;
                forbid[i+j] = j;
            }
        } else if(count[i] == 1) {
            count[i + forbid[i]]++;
            forbid[i + forbid[i]] = forbid[i];
        }
    }
    printf("%s\n", count[n] ? "Paula" : "Carlos");
    return 0;
}
