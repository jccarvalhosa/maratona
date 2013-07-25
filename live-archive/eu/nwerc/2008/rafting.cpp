#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define EPS 1e-9
#define INF 1e9
using namespace std;

int cmpD(double x, double y=0, double tol=EPS) {  return (x <= y+tol) ? (x+tol<y) ? -1 : 0 : 1; }

struct pt {
    double x, y;
    pt(double x=0, double y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(double c) { return pt(x*c, y*c); }
    pt operator /(double c) { return pt(x/c, y/c); }
    double operator *(pt p) { return x*p.x+y*p.y; }
    double operator %(pt p) { return x*p.y-y*p.x; }
    int cmp(pt p) const {
        int t=cmpD(x, p.x);
        return t ? t : cmpD(y, p.y);
    }
    bool operator <=(const pt &p)const { return cmp(p)<=0; }
    bool operator ==(const pt &p)const { return cmp(p)==0; }
    bool operator <(const pt &p)const { return cmp(p)<0; }
    bool operator >(const pt &p)const { return cmp(p)>0; }
    bool operator >=(const pt &p)const { return cmp(p)>=0; }

    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
    bool between(pt p, pt q) {  return prod(p, q)==0 && min(p, q)<= *this && *this <= max(p, q); }
};

pt p1[111], p2[111];

pt project(pt a, pt b) { return b * ((a*b)/(b*b)); }

double abs(pt p, pt q=pt()) { return hypot(p.x-q.x, p.y-q.y); }

double dist_pt_seg(pt p, pt a, pt b) {
    pt pp = a+project(p-a, b-a);
    if(pp.between(a, b)) return abs(p, pp);
    return min(abs(p, a), abs(p, b));
}

double dist_seg_seg(pt p, pt q, pt r, pt s) {
    double ret = min(
        min(dist_pt_seg(p, r, s), dist_pt_seg(q, r, s)),
        min(dist_pt_seg(r, p, q), dist_pt_seg(s, p, q))
    );
    return ret;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n1, n2;
        cin>>n1;
        for(int i=0;i<n1;i++) cin>>p1[i].x>>p1[i].y;
        cin>>n2;
        for(int i=0;i<n2;i++) cin>>p2[i].x>>p2[i].y;
        double dmax=INF;
        for(int i=0;i<n1;i++) for(int j=0;j<n2;j++) dmax = min(dmax, dist_seg_seg(p1[i], p1[(i+1)%n1], p2[j], p2[(j+1)%n2]));
        printf("%.9lf\n", dmax/2);
    }
    return 0;
}

