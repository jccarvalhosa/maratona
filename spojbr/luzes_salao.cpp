#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define fori(i, n) for(int i=0;i<(n);i++)
#define tr(T, i) for (typeof(T.begin()) i=T.begin(); i != T.end(); i++)
#define sz size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x"=" << x << endl)
#define EPS 1e-9
#define INF 1e9
const double PI = 2*acos(0);

typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

double positive_angle(double a) {
    while(cmpD(a) < 0) a += 2*PI;
    while(cmpD(a, 2*PI) >= 0) a -= 2*PI;
    return a;
}

bool between(double a, double b, double c) { 
    a = positive_angle(a); b = positive_angle(b); c = positive_angle(c);
    int ret = b <= max(a, c) && b >= min(a, c);
    if(cmpD(fabs(c-a), PI) > 0) return 1 - ret;
    return ret;
}

struct pt {
    double x, y;

    pt(double x=0, double y=0): x(x), y(y) {}

    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(double c) { return pt(x*c, y*c); }
    pt operator /(double c) { return pt(x/c, y/c); }
    double operator *(pt p) { return x*p.x + y*p.y; }
    double operator %(pt p) { return x*p.y - y*p.x; }
    int cmp(pt p) const { 
        int t = cmpD(x, p.x);
        return t ? t : cmpD(y, p.y);
    }
    bool operator ==(pt p) { return cmp(p) == 0; }
    bool operator !=(pt p) { return cmp(p) != 0; }
    bool operator <(const pt &p)const { return cmp(p) < 0; }
    bool operator >(const pt &p)const { return cmp(p) > 0; }
    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }
};

typedef vector<pair<pt, pt> > vppp;

double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }
double arg(pt p) { return atan2(p.y, p.x); }
int ccw(pt p, pt q, pt r) { return cmpD((p-r) % (q-r)); }
bool between(pt p, pt q, pt r) { return ccw(p, q, r) == 0 && cmpD((p-q) * (r-q)) <= 0; }
double angle(pt p, pt q, pt r) { pt u=p-q, v=r-q; return atan2(u % v, u * v); }
pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

bool normalize(pt &p) {
    double r = abs(p);
    if(!cmpD(r)) return 0;
    p.x /= r; p.y /= r;
    return 1;
}

pt line_intersect(pt p, pt q, pt r, pt s) {
    pt a=q-p, b=s-r;
    pt c(p%q, r%s);
    if(cmpD(a % b) == 0) return pt(INF, INF);
    return pt(pt(a.x, b.x) % c , pt(a.y, b.y) % c) / (a % b);
}

bool seg_intersect(pt p, pt q, pt r, pt s) {
    pt a = line_intersect(p, q, r, s);
    if(a == pt(INF, INF)) return 0;
    return between(p, a, q) && between(r, a, s);
}

double dist_pt_line(pt p, pt a, pt b = pt()) { return abs(p, a + project(p-a, b-a)); }

double dist_pt_seg(pt p, pt a, pt b) {
    pt pp = a + project(p, b-a);
    if(between(a, pp, b)) return abs(p, pp);
    return min(abs(p, a), abs(p, b));
}

double dist_seg_seg(pt p, pt q, pt r, pt s) { return min(dist_pt_seg(p, r, s), dist_pt_seg(q, r, s)); }

int in_circle(pt p, pt o, double r) { return cmpD(abs(p, o), r); }

pair<pt, pt> tangents(pt p, pt o, double r) {
    double a, b, c, teta1, teta2;
    a = (o.x-p.x)*(o.x-p.x) - r*r;
    b = -2*(o.x-p.x)*(o.y-p.y);
    c = (o.y-p.y)*(o.y-p.y) - r*r;
    if(cmpD(a) == 0) {
        teta1 = acos(0);
        teta2 = atan2(-c, b);
    } else {
        teta1 = atan2(-b+sqrt(b*b-4*a*c), 2*a);
        teta2 = atan2(-b-sqrt(b*b-4*a*c), 2*a);
    }
    pt p1 = p + project(o-p, pt(cos(teta1), sin(teta1))); 
    pt p2 = p + project(o-p, pt(cos(teta2), sin(teta2))); 
    return make_pair(p1, p2);
}

//AINDA NAO FOI TESTADA
vector<pt> cuts(pt a, pt b, pt o, double r) {
    vector<pt> resp;
    pt op = a+project(o-a, b-a);
    int flag = cmpD(abs(op, o), r);
    if(flag == 0) resp.pb(op);
    if(flag == -1) {
        double d = sqrt(r*r - (o-op)*(o-op));
        resp.pb(op + (b-a)*d/abs(b-a));
        resp.pb(op - (b-a)*d/abs(b-a));
    }
    return resp;
}

double cannon_area(pt p, pt o, double r, double a, double t) {
    double ST,S1,S2,h1,h2,teta1,teta2,ang1,ang2,angtg1,angtg2;
    ST = PI * r * r;
    ang1 = (a - t/2)*PI/180;
    ang2 = (a + t/2)*PI/180;
    pair<pt, pt> tg = tangents(p, o, r);
    angtg1 = arg(tg.first-p);
    angtg2 = arg(tg.second-p);
    h1 = min(dist_pt_line(o, p, p+pt(cos(ang1), sin(ang1))), r);
    h2 = min(dist_pt_line(o, p, p+pt(cos(ang2), sin(ang2))), r);
    teta1 = acos(h1/r);
    S1 = between(angtg1, ang1, angtg2) * r * r * (teta1  - sin(2*teta1)/2);
    teta2 = acos(h2/r);
    S2 = between(angtg1, ang2, angtg2) * r * r * (teta2  - sin(2*teta2)/2); 
    if(between(ang1, arg(o-p), ang2)) return ST - S1 - S2;
    return fabs(S1 - S2);
}

vppp join(vppp v) {
    vppp u;
    if(v.empty()) return v;
    sort(all(v));
    u.pb(v[0]);
    for(int i=1; i<v.sz;i++) {
        if(v[i].first > u[u.sz-1].second) u.pb(v[i]);
        else u[u.sz-1].second = max(u[u.sz-1].second, v[i].second);
    }
    return u;
}

vppp reverse(vppp v, pt ini, pt fim) {
    vppp u;
    if(v.empty()) u.pb(mp(ini, fim));
    else {
        fori(i, v.sz) {
            v[i].first = min(fim, max(ini, v[i].first));
            v[i].second = min(fim, max(ini, v[i].second));
        }
        if(v[0].first != ini) u.pb(mp(ini, v[0].first));
        for(int i=1;i<v.sz;i++) if(v[i].first > v[i-1].second) u.pb(mp(v[i-1].second, v[i].first));
        if(v[v.sz-1].second != fim) u.pb(mp(v[v.sz-1].second, fim));
    }
    return u;
}

pair<pt, pt> shadow(pt p, pt o, double r, pt ini, pt fim) {
    double d1 = dist_pt_line(p, ini, fim);
    double d2 = dist_pt_line(o, ini, fim);
    if(cmpD(d1, d2-r) <= 0) return mp(pt(), pt());
    pair<pt, pt> tg = tangents(p, o, r);
    pt p1 = line_intersect(p, tg.first, ini, fim);  
    pt p2 = line_intersect(p, tg.second, ini, fim);  
    if(p1 > p2) swap(p1, p2);
    if(cmpD(d1, d2+r) <= 0) {
        pt pl = ini + project(p, fim - ini);
        pt pc = ini + project(o, fim - ini);
        if(p2 == pt(INF, INF)) {
            if(pl > pc) p2 = pt(-INF, -INF);
            else swap(p1, p2);
        } 
        else if(pl > pc) p2 = pt(-INF, -INF);
        else p1 = pt(INF, INF);
        swap(p1, p2);
    }
    return mp(p1, p2);
}

int main() {
    int L, C;
    double X, Y, r[1000], x, y;
    vector<pt> luz, col;
    vppp side, aceso, apagado;
    while(scanf("%d %d %lf %lf",&L,&C,&X, &Y) && L) {
        luz.clear(); col.clear();
        side.clear();
        side.pb(mp(pt(X, 0), pt(X, Y)));
        side.pb(mp(pt(0, Y), pt(X, Y)));
        side.pb(mp(pt(0, 0), pt(X, 0)));
        side.pb(mp(pt(0, 0), pt(0, Y)));
        fori(i, L) {
            scanf("%lf%lf", &x, &y);
            luz.pb(pt(x, y));
        }
        fori(i, C) {
            scanf("%lf%lf", &x, &y);
            col.pb(pt(x, y));
            scanf("%lf", &r[i]);
        }
        double resp = 0;
        fori(i, 4) {
            aceso.clear();
            fori(j, luz.sz) {
                apagado.clear();
                fori(k, col.sz) apagado.pb(shadow(luz[j], col[k], r[k], side[i].first, side[i].second));
                apagado = reverse(join(apagado), side[i].first, side[i].second);
                fori(k, apagado.sz) aceso.pb(apagado[k]);
            }
            aceso = join(aceso);
            fori(j, aceso.sz) resp += abs(aceso[j].first, aceso[j].second); 
        }
        printf("%.4lf\n", resp);
    }
    return 0;
}
