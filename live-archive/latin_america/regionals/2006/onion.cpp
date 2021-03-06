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
#define INF 0x3f3f3f3f
const double PI = 2*acos(0);

typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

//compara dois doubles, retornando 1 se x > y, 0 se x == y e -1 se x < y
int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

//retorna um angulo entre 0 e 2*PI
double positive_angle(double a) {
    while(cmpD(a) < 0) a += 2*PI;
    while(cmpD(a, 2*PI) >= 0) a -= 2*PI;
    return a;
}

//verifica se o angulo b esta entre os angulos a e c
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

//retorna distancia entre dois pontos, se apenas um for passado, considera o outro a origem
double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }

//retorna o argumento do ponto p
double arg(pt p) { return atan2(p.y, p.x); }

//retorna 0 se o ponto r esta na reta pq, 1 se esta na esquerda e -1 se esta na direita
int ccw(pt p, pt q, pt r) { return cmpD((q-p) % (r-p)); }

//verifica se o ponto q esta entre os pontos p e r
bool between(pt p, pt q, pt r) { return ccw(p, q, r) == 0 && cmpD((p-q) * (r-q)) <= 0; }

//retorna o valor do angulo pqr
double angle(pt p, pt q, pt r) { pt u=p-q, v=r-q; return atan2(u % v, u * v); }

//retorna a projecao do ponto a no ponto b
pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

//normaliza um vetor, retornando false caso ele seja o vetor nulo
bool normalize(pt &p) {
    double r = abs(p);
    if(!cmpD(r)) return false;
    p.x /= r; p.y /= r;
    return true;
}

//determina o ponto de intersecao entre as retas pq e rs
pt line_intersect(pt p, pt q, pt r, pt s) {
    pt a=q-p, b=s-r, c(p%q, r%s);
    if(cmpD(a % b) == 0) return pt(INF, INF);
    return pt(pt(a.x, b.x) % c , pt(a.y, b.y) % c) / (a % b);
}

//true se os segmentos pq e rs tem intersecao, false cc
bool seg_intersect(pt p, pt q, pt r, pt s) {
    pt a = line_intersect(p, q, r, s);
    return between(p, a, q) && between(r, a, s);
}

//distancia entre um ponto e uma reta
double dist_pt_line(pt p, pt a, pt b = pt()) { return abs(p, a + project(p-a, b-a)); }

//distancia entre um ponto e um segmento de reta
double dist_pt_seg(pt p, pt a, pt b) {
    pt pp = a + project(p-a, b-a);
    if(between(a, pp, b)) return abs(p, pp);
    return min(abs(p, a), abs(p, b));
}

//distancia entre dois segmentos de reta
double dist_seg_seg(pt p, pt q, pt r, pt s) {
	if(seg_intersect(p, q, r, s)) return 0;
    return min(min(dist_pt_seg(p, r, s), dist_pt_seg(q, r, s)), min(dist_pt_seg(r, p, q), dist_pt_seg(s, p, q)));
}

//retorna 1 se p esta fora da circunferencia, 0 se esta em cima e -1 se esta dentro
int in_circle(pt p, pt o, double r) { return cmpD(abs(p, o), r); }

//retorna o circuncentro do triangulo pqr
pt circumcenter(pt p, pt q, pt r) {
    pt a=p-r, b=q-r, c=pt(a*(p+r)/2, b*(q+r)/2);
    return pt(c % pt(a.y, b.y), pt(a.x, b.x) % c / (a % b));
}

//dados o ponto p e a circunferencia definida por o e r
//retorna os dois pontos de tangencia de p para a circunferencia
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
    return mp(p1, p2);
}


//dadas a reta definida pelos pontos a e b, o centro o da circunferencia e o raio r
//retorna um vetor com os pontos de intersecao entre a reta e a circunferencia
//o vetor pode ter tamanhos 0, 1 ou 2, dependendo da quantidade de pontos de intersecao
vector<pt> cuts(pt a, pt b, pt o, double r) {
    vector<pt> resp;
    pt op = a+project(o-a, b-a);
    int flag = cmpD(abs(op, o), r);
    if(flag == 0) resp.pb(op);
    if(flag == -1) {
        double d = sqrt(r*r - (o-op)*(o-op));
        resp.pb(op - (b-a)*d/abs(b-a));
        resp.pb(op + (b-a)*d/abs(b-a));
    }
    return resp;
}

//dados o ponto p em que se localiza um canhao, o centro o da circunferencia, o raio r,
//o angulo de disparo a e o angulo de espalhamento t
//determina a area que o tiro faz na circunferencia
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

//dado um vetor qualquer v de segmentos de reta
//retorna um vetor com a uniao de todos esses segmentos (segmentos disjuntos e ordenados)
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

//dados um vetor v disjunto e ordenado de segmentos de reta e os pontos ini e fim
//retorna um vetor com a uniao de todos os segmentos que estao contidos no segmento (ini,fim) e nao possuem intersecao com v
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

//dados o ponto p em que esta uma lampada, o centro da circunferencia, o raio e os pontos ini e fim que definem um anteparo
//retorna o segmento de reta (p1,p2) aonde estara localizada a sombra produzida pela lampada no anteparo
//se nenhuma sombra for produzida, retorna um segmento de comprimento nulo
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

//flag 1 retorna os pontos que estao no convex_hull, flag 0 retorna os pontos que nao estao
vector<pt> convex_hull(vector<pt> v, int flag) {
    int vis[10000], p=0, np;
    fori(i, v.sz) {
        vis[i]=0;
        if(v[i] < v[p]) p = i;
    }
    while(!vis[p]) {
        vis[p] = 1; np = -1;
        fori(i, v.sz) if(i != p) if(np == -1 || ccw(v[p], v[np], v[i]) == 1 || between(v[p], v[i], v[np])) np = i;
        p = np;
    }
    vector<pt> u;
    fori(i, v.sz) if(vis[i] == flag) u.pb(v[i]);
    return u;
}

int main()
{
    int N, cam, c;
    double x, y;
    vector<pt> v;
    while(scanf("%d", &N) && N)
    {
        v.clear();
        fori(i, N) {
            scanf("%lf%lf", &x, &y);
            v.pb(pt(x, y));
        }
        for(cam=1; true; cam++) {
            v = convex_hull(v, 0);
            if(v.empty()) break;
        }
        if((cam % 2) == 0) printf("Do not take this onion to the lab!\n");
        else printf("Take this onion to the lab!\n");
    }
    return 0;
}
