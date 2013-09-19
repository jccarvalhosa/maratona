#include <cstdio>
#include <cmath>
#include <algorithm>
#define EPS 1e-12

using namespace std;

int main()
{
    double x, y ,c, lo, hi, mid;
    while(scanf("%lf %lf %lf", &x, &y, &c)!=EOF)
    {
        lo=0;
        hi=min(x, y);
        while(lo<hi+EPS)
        {
            mid=(lo+hi)/2;
            if(1/sqrt(y*y-mid*mid)+1/sqrt(x*x-mid*mid)-1/c>EPS) hi=mid-EPS;
            else lo=mid+EPS;
        }
        printf("%.3lf\n", lo);
    }
    return 0;
}
