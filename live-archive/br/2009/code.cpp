#include <cstdio>
#include <cstring>

int main() {
    char s[1003], k;
    int c[26], down, up, n, i;
    s[0] = 'a';
    while(scanf("%s", s+1) && s[1] != '*') {
        n = strlen(s);
        s[n++] = 'a';
        memset(c, 0, sizeof(c));
        down = up = 0;
        for(i=1;i<n;i++) {
            k = (s[i] - s[i-1] + 26) % 26;
            down += k;
            c[k]++;
        }
        for(i=25;i>0;i--) while(c[i] && down > up) {
            down -= i;
            up += 26 - i;
            c[i]--;
        }
        printf("%d\n", down);
    }
    return 0;
}
