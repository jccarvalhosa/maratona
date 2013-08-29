#include <cstdio>
#include <cstring>

int is_pal(int n) {
    char buf[30], sz, i;
    sprintf(buf, "%d", n);
    sz=strlen(buf);
    for(i=0;i<sz;i++) if(buf[i]!=buf[sz-i-1]) return 0;
    return 1;
}

int main() {
    int i, j, n, max=0, a=0, b=0;
    scanf("%d", &n);
    for(i=1;i<n;i++) for(j=i;j<n;j++) if(is_pal(i*j) && i*j>max) {
        max=i*j;
        a=i, b=j;
    }
    printf("%d %d", a, b);
    return 0;
}
