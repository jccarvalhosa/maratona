#include <stdio.h>
#include <math.h>
#define EPS 1e-5

double p[100][2];

double c[2], r2;

int circunferencia(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double d = (x1-x2)*(y1-y3) - (x1-x3)*(y1-y2);
    if(d == 0) return 0;
    double c1 = (x1*x1 - x2*x2 + y1*y1 - y2*y2)/2;
    double c2 = (x1*x1 - x3*x3 + y1*y1 - y3*y3)/2;
    c[0] = (c1*(y1-y3) - c2*(y1-y2)) / d;
    c[1] = (c2*(x1-x2) - c1*(x1-x3)) / d;
    r2 = (x1-c[0])*(x1-c[0]) + (y1-c[1])*(y1-c[1]);
    return 1;
}

int pertence(double x, double y) { return fabs((x-c[0])*(x-c[0]) + (y-c[1])*(y-c[1]) - r2) < EPS ? 1 : 0; }

int main()
{
    int N, i, j, k, l, resp, atual;
    while(scanf("%d", &N) && N)
    {
        for(i=0;i<N;i++) scanf("%lf%lf", &p[i][0], &p[i][1]);
        if(N < 3)
        {
            printf("%d\n", N);
            continue;
        }
        resp = 2;
        for(i=0;i<N;i++) for(j=i+1;j<N;j++) for(k=j+1;k<N;k++)
        {
            atual = 3;
            if(!circunferencia(p[i][0], p[i][1], p[j][0], p[j][1], p[k][0], p[k][1])) continue;
            for(l=k+1;l<N;l++) if(pertence(p[l][0], p[l][1])) atual++;
            if(resp < atual) resp = atual;
        }
        printf("%d\n", resp);
    }
    return 0;
}
