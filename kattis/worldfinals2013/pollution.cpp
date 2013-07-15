#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define EPS 1e-6
#define pb push_back
using namespace std;

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

struct pt {
	double x, y;
	pt(double x=0, double y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(double c) { return pt(x*c, y*c); }
    pt operator /(double c) { return pt(x/c, y/c); }
	double operator %(pt p) { return x*p.y - y*p.x; }
    double operator *(pt p) { return x*p.x + y*p.y; }
    int cmp(pt p) const { 
        int t = cmpD(x, p.x);
        return t ? t : cmpD(y, p.y);
    }
    bool operator <(const pt &p)const { return cmp(p) < 0; }
    bool operator ==(pt p) { return cmp(p) == 0; }
    bool operator <=(const pt &p)const { return cmp(p) <= 0; }
    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }
};
pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }
double abs(pt p, pt q=pt()) { return hypot(p.x-q.x, p.y-q.y); }
double angle(pt p, pt q, pt r) { pt u=p-q, v=r-q; return atan2(u % v, u * v); }
double area_triangle(pt a, pt b, pt c) { return (b%c - a%c + a%b)/2; }

int n;
double r;
pt p[100], o=pt();

//dadas a reta definida pelos pontos a e b, o centro o da circunferencia e o raio r
//retorna um vetor com os pontos de intersecao entre a reta e a circunferencia
//o vetor pode ter tamanhos 0, 1 ou 2, dependendo da quantidade de pontos de intersecao
vector<pt> cuts(pt a, pt b) {
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

double area_sector(pt a, pt b) { return r*r*angle(a, o, b)/2; }
double area_cut(pt a, pt b) { return area_sector(a, b) - area_triangle(o, a, b); }
int in_circle(pt a) { return abs(a-o) < r-EPS?1:0;}

double area_inter(pt a, pt b) {
	vector<pt> v, aux=cuts(a, b);
	for(int i=0;i<aux.size();i++) if(aux[i].between(a, b)) v.pb(aux[i]);
	if(v.size()==0) return in_circle(a) ? area_triangle(o, a, b) : area_sector(a, b);
	if(v.size()==1) {
		double sa = in_circle(a) ? area_triangle(o, a, v[0]) : area_sector(a, v[0]);
		double sb = in_circle(b) ? area_triangle(o, v[0], b) : area_sector(v[0], b);
		return sa + sb;
	}
	if(v.size()==2) return area_sector(a, b) - area_cut(v[0], v[1]);
}

double area_polygon() {
	double s=0;
	for(int i=0;i<n;i++) s += area_inter(p[i], p[(i+1)%n]);;
	return s;
}

int main() {
	cin>>n>>r;
	for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
	printf("%.9lf\n", area_polygon());
	return 0;
}
