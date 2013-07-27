#include <cstdio>
#include <cmath>

int main() {
    int T;
    char s[100], t[100];
    double x, y, z, x0, y0, z0;
    scanf("%d", &T);
    while(T--) {
        scanf(" %[^\n] %lf %lf %lf %[^\n] %lf %lf %lf", s, &x0, &y0, &z0, t, &x, &y, &z);
        printf("%s to %s: %.2lf\n", s, t, sqrt((x0-x)*(x0-x) + (y0-y)*(y0-y) + (z0-z)*(z0-z)));
    }
    return 0;
}
