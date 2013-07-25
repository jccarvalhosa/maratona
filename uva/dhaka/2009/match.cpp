#include <cstdio>
#include <cstring>

int main() {
    int i, b, s, a, cb[70], aux=1;
    while(scanf("%d %d", &b, &s) && (b || s)) {
        memset(cb, 0, sizeof(cb));
        for(i=0; i<b; i++) {
            scanf("%d", &a);
            cb[a]++;
        }
        for(i=0; i<s; i++) scanf("%d", &a);
        printf("Case %d: ", aux++);
        if(b<=s) printf("0\n");
        else {
            for(i=0; i<70; i++) if(cb[i]) {
                printf("%d %d\n", b-s, i);
                break;
            }
        }
    }
    return 0;
}
