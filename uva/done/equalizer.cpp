#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char s[1000], t[1000];

int main()
{
    int c, i, S, T, s0, s1, t0, t1, si, resp, delta, test;
    scanf("%d", &c);
    for(test=1;test<=c;test++) {
        printf("Case %d: ", test);
        scanf(" %s", s);
        scanf("%s", t);
        s0=s1=si=t0=t1=0;
        S = strlen(s);
        T = strlen(t);
        for(i=0;i<S;i++) {
            if(s[i] == '0') s0++;
            if(s[i] == '1') s1++;
            if(s[i] == '?') si++;
        }
        for(i=0;i<T;i++) {
            if(t[i] == '0') t0++;
            if(t[i] == '1') t1++;
        }
        if(S != T || t0 > s0 + si) printf("-1\n");
        else {
            resp = delta = 0;
            for(i=0;i<S;i++) if(s[i] == '?' && t[i] == '0') {
                resp++; si--; s0++;
                s[i] = '0';
            }
            for(i=0;i<S;i++) if(s[i] == '?' && t[i] == '1') {
                resp++; si--;
                if(t0 > s0) s0++, s[i] = '0';
                else s1++, s[i] = '1';
            }
            for(i=0;i<S;i++) if(s[i] == '0' && t[i] == '1' && s0 > t0) {
                resp++; s0--; s1++;
                s[i] = '1';
            }
            for(i=0;i<S;i++) if(s[i] != t[i]) delta++;
            printf("%d\n", resp + delta/2);
        }
    }
    return 0;
}
