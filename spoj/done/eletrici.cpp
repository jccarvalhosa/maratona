#include <stdio.h>

int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int N, dmax, i=0, d=0, m=0, a=0, c, times, delta;
    int conv[32][13][201], consu[1000], num[1000];
    conv[0][0][0] = 0;
    while(1) {
        dmax = dias[m];
        if(m == 1) {
            if((a + 1900) % 400 == 0) dmax++;
            else if((a+1900) % 4 == 0 && (a+1900) % 100 != 0) dmax++;
        }
        if(++d >= dmax) {
            d = 0;
            if(++m >= 12) {
                m = 0;
                if(++a > 200) break;
            }
        }
        conv[d][m][a] = ++i;
    }
    while(scanf("%d", &N) && N) {
        times = delta = 0;
        for(i=0;i<N;i++) {
            scanf("%d%d%d%d", &d, &m, &a, &c);
            num[i] = conv[d-1][m-1][a-1900];
            consu[i] = c;
            if(i > 0 && num[i] == num[i-1] + 1) times++, delta += consu[i] - consu[i-1];
        }
        printf("%d %d\n", times, delta);
    }
    return 0;
}
