#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int s, c, p, l, t=1;
    while(scanf("%d%d%d%d", &s, &c, &p, &l) && s) {
        int i;
        int d = (s-p)%s;
        l = (l+d)%c;
        for(i=0;i<c;i++) if((l+i*s)%c == 0) break;
        printf("Case %d: ", t++);
        if(i == c) printf("Never\n");
        else printf("%d %d/%d\n", i, d, s);
    }
    return 0;
}
