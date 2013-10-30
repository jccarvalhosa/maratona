#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define sz size()
#define EPS 1e-6
#define INF 1e9

//compara dois doubles, retornando 1 se x > y, 0 se x == y e -1 se x < y
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
    int cmp(pt p) const { 
        int t = cmpD(x, p.x);
        return t ? t : cmpD(y, p.y);
    }
    bool operator ==(pt p) { return cmp(p) == 0; }
    bool operator !=(pt p) { return cmp(p) != 0; }
    bool operator <(const pt &p)const { return cmp(p) < 0; }
    bool operator >(const pt &p)const { return cmp(p) > 0; }
    bool operator <=(const pt &p)const { return cmp(p) <= 0; }
    bool operator >=(const pt &p)const { return cmp(p) >= 0; }
    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }
    
    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
    //true se o ponto em questao esta entre os pontos p e q
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
    //true se o ponto esta a esquerda do segmento pq
    bool left(pt p, pt q) { return prod(p, q) < 0; }
    //true se o ponto esta a direita do segmento pq
    bool right(pt p, pt q) { return prod(p, q) > 0; }
};

typedef vector<pt> polygon;

//retorna distancia entre dois pontos, se apenas um for passado, considera o outro a origem
double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }

//retorna a projecao do ponto a no ponto b
pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

//retorna a projecao do ponto p na reta ab
pt project_pt_line(pt p, pt a, pt b) { return a + project(p-a, b-a); }

//funcao carteada que eu ainda to tentando entender
bool cart(pt a, pt b, pt c, pt d) { return (d.left(a, c) != d.left(b, c) && c.left(a, b) != d.left(a, b)); }

//retorna 0 se o ponto p esta no exterior de T, -1 se esta na fronteira ou 1 se esta no interior
//funciona para qualquer poligono
int in_poly(pt p, polygon T) {
    for(int i=0;i<T.sz;i++) if(p.between(T[i],T[(i+1)%T.sz])) return -1;
	int n = 0;
	pt ref = pt(INF, INF);
	for(int i=0;i<T.sz;i++) n += cart(T[i], T[(i+1)%T.sz], p, ref);
	return n % 2;
}

polygon p(3);
pt o;
double r;

int valid() {
	if(in_poly(o, p)) return 1;
	for(int i=0;i<3;i++) if(abs(p[i], o) < r+EPS) return 1;
	for(int i=0;i<3;i++) {
		pt a = p[i], b=p[(i+1)%3];
    	pt pp = project_pt_line(o, a, b);
		if(pp.between(a, b) && abs(o, pp) < r+EPS) return 1;
	}
	return 0;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		for(int i=0;i<3;i++) cin>>p[i].x>>p[i].y;
		cin>>o.x>>o.y>>r;
		if(valid()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
