#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    char s[1000], l, r, *p;
    while(scanf("%[^\n] ", s) && s[0] != '*') {
        l = toupper(s[0]);
        r = 'Y';
        p = strtok(s, " ");
        while(p != NULL) {
            if(l != toupper(p[0])) r = 'N';
            p = strtok(NULL, " ");
        }
        printf("%c\n", r);
    }
    return 0;
}
