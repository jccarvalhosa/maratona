#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define EPS 1e-3
#define INF 1e9

//compara dois doubles, retornando 1 se x > y, 0 se x == y e -1 se x < y
int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

struct pt {
    double x, y;
    pt(double x=0, double y=0): x(x), y(y) {}
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator /(double c) { return pt(x/c, y/c); }
    double operator %(pt p) { return x*p.y - y*p.x; }
    int cmp(pt p) const { 
		int t = cmpD(x, p.x);
		return t ? t : cmpD(y, p.y);
	}
    bool operator <(const pt &p)const { return cmp(p) < 0; }
    bool operator <=(const pt &p)const { return cmp(p) <= 0; }
    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
};

typedef pair<pt, pt> segment;

//determina o ponto de intersecao entre as retas pq e rs
pt line_intersect(pt p, pt q, pt r, pt s) {
    pt a=q-p, b=s-r, c(p%q, r%s);
    if(cmpD(a % b) == 0) return pt(INF, INF);
    return pt(pt(a.x, b.x) % c , pt(a.y, b.y) % c) / (a % b);
}

//true se os segmentos pq e rs tem intersecao, false cc
bool seg_intersect(pt p, pt q, pt r, pt s) {
    if(r.between(p, q) || s.between(p, q) || p.between(r, s) || q.between(r, s)) return true;
    pt a = line_intersect(p, q, r, s);
    return a.between(p, q) && a.between(r, s);
}

vector<segment> v;

int main() {
	int t, i, j, T, N, num;
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d", &N);
		v.resize(N);
		num = 0;
		for(i=0;i<N;i++) scanf("%lf%lf%lf%lf", &v[i].first.x, &v[i].first.y, &v[i].second.x, &v[i].second.y);
		for(i=0;i<N;i++) for(j=i+1;j<N;j++) if(seg_intersect(v[i].first, v[i].second, v[j].first, v[j].second)) num++;
		if(t) printf("\n");
		printf("%d\n", N + 2*num);
	}
	return 0;
}
