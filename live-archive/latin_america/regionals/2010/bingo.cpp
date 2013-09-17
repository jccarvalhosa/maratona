#include <cstdio>
int mod(int a) { return a > 0 ? a : -a; } 

int main() {
    int N, B, i, j, p[1000], b[1000];
    while(scanf("%d%d", &N, &B) && N) {
        p[0]=1;
        for(i=1;i<=N;i++) p[i] = 0;
        for(i=0;i<B;i++) scanf("%d", &b[i]);
        for(i=0;i<B;i++) for(j=i+1;j<B;j++) p[mod(b[i]-b[j])] = 1;
        for(i=0;i<=N;i++) if(!p[i]) break;
        if(i == N+1) printf("Y\n");
        else printf("N\n", i);
    }
    return 0;
}
