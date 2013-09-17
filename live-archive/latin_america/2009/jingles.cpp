#include <cstdio>
#include <cstring>

int val(char c) {
    switch(c) {
        case 'W': return 64;
        case 'H': return 32;
        case 'Q': return 16;
        case 'E': return 8;
        case 'S': return 4;
        case 'T': return 2;
        case 'X': return 1;
    }
    return 0;
}

int main()
{
    char s[1000], *pch;
    int i, n, sum, resp;
    while(scanf("%s", s) && s[0] != '*') {
        pch = strtok(s, "/");
        resp = 0;
        while(pch != NULL)
        {
            sum = 0;
            n = strlen(pch);
            for(i=0;i<n;i++) sum += val(pch[i]);
            if(sum == 64) resp++;
            pch = strtok(NULL, "/");
        }
        printf("%d\n", resp);
    }
    return 0;
}
