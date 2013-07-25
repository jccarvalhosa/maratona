#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
#define mp make_pair
#define INF 1e9
#define EPS 1e-6

int cmpD(double x, double y=0, double tol=EPS) { return (x<=y+tol) ? (x+tol<y) ? -1 : 0 : 1;  }

struct pt {
    double x, y, r;
    pt(double x=0, double y=0, double r=0): x(x), y(y), r(r) {}
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
    bool operator ==(pt p) { return cmp(p)==0; }
    bool operator !=(pt p) { return cmp(p)!=0; }
    bool operator <(const pt &p)const { return cmp(p)<0; }
    bool operator >(const pt &p)const { return cmp(p)>0; }
    bool operator <=(const pt &p)const { return cmp(p)<=0; }
    bool operator >=(const pt &p)const { return cmp(p)>=0; }

    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }
};

typedef pair<pt, pt> seg;

pt project(pt a, pt b) { return b*((a*b)/(b*b)); }

double abs(pt p, pt q=pt()) { return hypot(p.x-q.x, p.y-q.y); }

double dist_pt_line(pt p, pt a, pt b=pt()) { return abs(p, a+project(p-a, b-a));  }

pt line_intersect(pt p, pt q, pt r, pt s) {
    pt a=q-p, b=s-r, c(p%q, r%s);
    if(cmpD(a%b)==0) return pt(INF, INF);
    return pt(pt(a.x, b.x)%c, pt(a.y, b.y)%c)/(a%b);
}

seg tangents(pt p, pt o) {
    double a, b, c, teta1, teta2;
    a=(o.x-p.x)*(o.x-p.x)-o.r*o.r;
    b=-2*(o.x-p.x)*(o.y-p.y);
    c=(o.y-p.y)*(o.y-p.y)-o.r*o.r;
    if(cmpD(a)==0) {
        teta1=acos(0);
        teta2=atan2(-c, b);
    }
    else {
        teta1=atan2(-b+sqrt(b*b-4*a*c), 2*a);
        teta2=atan2(-b-sqrt(b*b-4*a*c), 2*a);
    }
    pt p1=p+project(o-p, pt(cos(teta1), sin(teta1)));
    pt p2=p+project(o-p, pt(cos(teta2), sin(teta2)));
    return mp(p1, p2);
}

seg shadow(pt p, pt o, pt ini, pt fim) {
    double d1=dist_pt_line(p, ini, fim);
    double d2=dist_pt_line(o, ini, fim);
    if(cmpD(d1, d2-o.r)<=0) return mp(pt(), pt());
    pair<pt, pt> tg=tangents(p, o);
    pt p1=line_intersect(p, tg.first, ini, fim);
    pt p2=line_intersect(p, tg.second, ini, fim);
    if(p1>p2) swap(p1, p2);
    if(cmpD(d1, d2+o.r)<=0) {
        pt pl=ini+project(p, fim-ini);
        pt pc=ini+project(o, fim-ini);
        if(p2==pt(INF, INF)) {
            if(pl>pc) p2=pt(-INF, -INF);
            else swap(p1, p2);
        }
        else if(pl>pc) p2=pt(-INF, -INF);
        else p1=pt(INF, INF);
        swap(p1, p2);
    }
    return mp(p1, p2);
}


pt p[11111];
pt v[4];

int main() {
    int h, w, r, cx, cy, n;
    int T=1;
    while(1) {
        cin>>h>>w>>r>>cx>>cy>>n;
        if(h==0) break;
        int ans=0;
        for(int i=0;i<n;i++) scanf("%lf %lf", &p[i].x, &p[i].y); 
        printf("Case %d: ", T++);
        if(n==1) {
            cout<<1<<endl;
            continue;
        }
        v[0] = pt();
        v[1] = pt(0, h);
        v[2] = pt(w, h);
        v[3] = pt(w, 0);
        for(int i=0;i<4;i++) {
            if(ans==n) break;
            pt ini = v[i];
            pt fim = v[(i+1)%4];
            if(ini>fim) swap(ini, fim);
            vector<pair<pt, int> > aux;
            for(int j=0;j<n;j++) {
                seg s = shadow(p[j], pt(cx, cy, r), ini, fim);
                aux.push_back(mp(s.first, -1));
                aux.push_back(mp(s.second, 1));
            }
            aux.push_back(mp(ini, 0));
            aux.push_back(mp(fim, 0));
            sort(aux.begin(), aux.end());
            int j=0;
            int x=n;
            int t=aux.size();
            while(j<t) {
                if(aux[j].first > fim) break;
                x += aux[j].second;
                while(j<t && aux[j+1].first==aux[j].first) x += aux[++j].second;
                if(aux[j].first >= ini) ans = max(x, ans);
                j++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
