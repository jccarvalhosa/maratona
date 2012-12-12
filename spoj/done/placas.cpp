#include <stdio.h>
#include <string.h>

int isnum(char c) { return c <= '9' && c >= '0' ? 1 : 0; }
int isalpha(char c) { return c <= 'Z' && c >= 'A'; }

long long val(char *p)
{
    long long pos, total;
    int i;
    if(isnum(p[3]))
    {
        pos = 0;
        total = 1;
        for(i=6;i>=3;i--)
        {
            pos += (p[i] - '0') * total;
            if(isalpha(p[i])) return -1;
            total *= 10;
        }
        for(i=2;i>=0;i--)
        {
            if(isnum(p[i])) return -1;
            pos += (p[i] - 'A') * total;
            total *= 26;
        }
    }
    else
    {
        pos = 175760000;
        total = 1;
        for(i=6;i>=5;i--)
        {
            if(isalpha(p[i])) return -1;
            pos += (p[i] - '0') * total;
            total *= 10;
        }
        for(i=4;i>=0;i--)
        {
            if(isnum(p[i])) return -1;
            else if(p[i] == 'A') return -1;
            else if(p[i] < 'C') pos += (p[i] - 'A' - 1) * total;
            else if(p[i] == 'C') return -1;
            else if(p[i] < 'I') pos += (p[i] - 'A' - 2) * total;
            else if(p[i] == 'I') return -1;
            else if(p[i] < 'M') pos += (p[i] - 'A' - 3) * total;
            else if(p[i] == 'M') return -1;
            else if(p[i] < 'P') pos += (p[i] - 'A' - 4) * total;
            else if(p[i] == 'P') return -1;
            else pos += (p[i] - 'A' - 5) * total;
            total *= 21;
        }
    }
    return pos;
}

int main()
{
    int c;
    char p1[10], p2[10];
    long long int vp1, vp2;
    while(scanf("%s %s %d", p1, p2, &c) && c)
    {
        vp1 = val(p1);
        vp2 = val(p2);
        if(vp2 == -1) printf("N\n");
        else if(vp2 > vp1 && vp2 <= vp1 + c) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
