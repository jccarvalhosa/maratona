#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INF 1000000

int min(int a, int b) { return a < b ? a : b;}
int max(int a, int b) { return a > b ? a : b;}

struct Time{
    int num;
    int tenta;
    int tempo;
    int pen;
} t[100];

int compare(const void * a, const void * b)
{
    if(((struct Time *) a)->num == ((struct Time *) b)->num) return ((struct Time *) a)->pen - ((struct Time *) b)->pen;
    return ((struct Time *) a)->num - ((struct Time *) b)->num;
}

int main()
{
    int n, p, i, j, len, sep, a, s;
    int tnum, ttempo, ttenta, kmin, kmax, dtempo, dtenta;
    char frase[10];
    while(scanf("%d%d", &n, &p) && n)
    {
        for(i=0;i<n;i++)
        {
            tnum = ttenta = ttempo = 0;
            for(j=0;j<p;j++)
            {
                getchar();
                scanf("%s", frase);
                len = strlen(frase);
                sep=0;
                while(frase[sep] != '/') sep++;
                if(frase[sep+1] != '-')
                {
                    if(sep == 1) a = frase[0] - '0';
                    else if(sep == 2) a = (frase[0] - '0') * 10 + frase[1] - '0';
                    else a = 100;
                    if(len - sep == 2) s = frase[sep+1] - '0';
                    else if(len - sep == 3) s = (frase[sep+1] - '0') * 10 + frase[sep+2] - '0';
                    else if(len - sep == 4) s = (frase[sep+1] - '0') * 100 + (frase[sep+2] - '0') * 10 + frase[sep+3] - '0';
                    if(a != 0)
                    {
                        tnum++;
                        ttenta += (a - 1);
                        ttempo += s;
                    }
                }
            }
            t[i].num = tnum;
            t[i].tenta = ttenta;
            t[i].tempo = ttempo;
            t[i].pen = ttempo + 20 * ttenta;
        }
        qsort(t, n, sizeof(struct Time), compare);
        kmax = INF;
        kmin = 1;
        //for(i=0;i<n;i++) printf("%d %d %d %d\n", t[i].num, t[i].pen, t[i].tempo, t[i].tenta);
        for(i=1;i<n;i++) if(t[i].num == t[i-1].num && t[i].tenta != t[i-1].tenta)
        {
            dtenta = t[i].tenta - t[i-1].tenta;
            dtempo = t[i].tempo - t[i-1].tempo;
            if(t[i].pen == t[i-1].pen)
            {
                kmin = kmax = 20;
                break;
            }
            if(dtempo > 0 && dtenta < 0) kmax = min(kmax, (1 - dtempo) / dtenta);
            if(dtempo < 0 && dtenta > 0) kmin = max(kmin, ceil((1 - dtempo) / (float)dtenta));
        }
        if(kmax == INF) printf("%d *\n", kmin);
        else printf("%d %d\n", kmin, kmax);
    }
    return 0;
}


