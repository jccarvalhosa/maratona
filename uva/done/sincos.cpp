#include <cstdio>
#include <cmath>
#define EPS 1e-9

using namespace std;

int cmpD(double x, double y=0) { return x < y+EPS ? x+EPS < y ? -1 : 0 : 1; }

int main()
{
    int T, i;
    double val, teta, gama, a, b;
    double pi = acos(-1);
    scanf("%d", &T);
    for(i=0;i<T;i++) {
        scanf("%lf%lf", &a, &b);
        if(cmpD(a) == 0 && cmpD(b) == 0) printf("0.00 0.00\n");
        else {
            val = sqrt(a*a+b*b);
            gama = acos(a/val);
            if(cmpD(b) < 0) gama = 2*pi - gama;
            teta = pi/2 - gama;
            if(cmpD(teta, 2*pi) > 0) teta -= 2*pi;
            if(cmpD(teta) < 0) teta += 2*pi;
            printf("%.2lf %.2lf\n", teta, val);
        }
    }
    return 0;
}
