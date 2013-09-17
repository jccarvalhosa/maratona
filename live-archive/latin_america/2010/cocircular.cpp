#include <cstdio>
#include <algorithm>
using namespace std;
#define EPS 1e-3

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

struct pt {
    double x, y;
    pt(double x=0, double y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(double c) { return pt(x*c, y*c); }
    pt operator /(double c) { return pt(x/c, y/c); }
    double operator *(pt p) { return x*p.x + y*p.y; }
    double operator %(pt p) { return x*p.y - y*p.x; }
    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
};

double abs2(pt a, pt b) { return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); }

pt circumcenter(pt p, pt q, pt r) {
    pt a=p-r, b=q-r, c=pt(a*(p+r)/2, b*(q+r)/2);
    return pt(c % pt(a.y, b.y), pt(a.x, b.x) % c) / (a % b);
}

int main() {
    int N, i, j, k, l, sol, aux;
    double r2;
    pt p[100], c;
    while(scanf("%d", &N) && N) {
        sol = min(2, N);
        for(i=0;i<N;i++) scanf("%lf%lf", &p[i].x, &p[i].y);
        for(i=0;i<N;i++) for(j=i+1;j<N;j++) for(k=j+1;k<N;k++) if(p[i].prod(p[j], p[k])) {
            c = circumcenter(p[i], p[j], p[k]);
            r2 = abs2(c, p[i]);
            aux = 3;
            for(l=k+1;l<N;l++) if(cmpD(abs2(c, p[l]), r2) == 0) aux++;
            sol = max(sol, aux);
        }
        printf("%d\n", sol);
    }
    return 0;
}
