#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define EPS 1e-6
#define INF 1e9
const double PI = 2*acos(0);

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
};

//retorna distancia entre dois pontos, se apenas um for passado, considera o outro a origem
double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }

//retorna a projecao do ponto a no ponto b
pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

//distancia entre um ponto e uma reta
double dist_pt_line(pt p, pt a, pt b = pt()) { return abs(p, a + project(p-a, b-a)); }

//dado um ponto inicial, o angulo de tiro e a distancia d, retorna o ponto de destino
pt shot(pt p, double teta, double d=1) { return p + pt(cos(teta), sin(teta))*d;  }

//retorna a coordenada x de y na reta ab
double xline(pt a, pt b, double y) { 
	if(cmpD(y, b.y)==0) return b.x;
	return b.x + (y-b.y)*(a.x-b.x)/(a.y-b.y);
}

int main() {
	int N, i, cont;
	double T, teta, ang;
	scanf("%d", &N);
	while(N--) {
		scanf("%lf %lf", &T, &teta);
		teta = teta*PI/180;
		T = T * 100;
		double x=0, y=105.0/2, nx, ny;
		cont=0;
		while(1) {
			if(cont % 2 == 0) { 
				ny = 10;
				nx = xline(pt(x, y), shot(pt(x, y), -teta), ny);
			} else {
				ny = 95;
				nx = xline(pt(x, y), shot(pt(x, y), teta), ny);
			}
			if(cmpD(nx, T) > 0) break;
			cont++;
			x = nx; y = ny;
		}
		double d = dist_pt_line(pt(T, 105.0/2), pt(x, y), pt(nx, ny));
		//printf("d = %lf\n", d);
		if(cmpD(d, 16) <= 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
