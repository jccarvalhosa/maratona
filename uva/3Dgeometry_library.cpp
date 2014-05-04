#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#define INF 0x3f3f3f3f
#define EPS 1e-6

using namespace std;

inline int cmpD (double a, double b=0, double tol=EPS) { return a+tol < b ? -1: a-tol > b; }

struct pt {
    double x, y, z;

    pt(double x=0, double y=0, double z=0): x(x), y(y), z(z) {}

    pt operator +(const pt &p) const { return pt(x + p.x, y + p.y, z + p.z); }
    pt operator -(const pt &p) const { return pt(x - p.x, y - p.y, z - p.z); }
    pt operator *(double c) const { return pt(x*c, y*c, z*c); }
    pt operator /(double c) const { return pt(x/c, y/c, z/c); }
    double operator !() const { return sqrt(x*x + y*y + z*z); }
	bool operator !=(const pt &p) const { return cmpD(!(*this - p)) != 0; }
	bool operator ==(const pt &p) const { return not(*this != p); }

    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << "," << p.z << ")"; }
};

//retorna o produto escalar entre os pontos a e b
double dot(pt a, pt b) { return a.x*b.x + a.y*b.y + a.z*b.z; }

//retorna o produto vetorial entre os pontos a e b
pt cross(pt a, pt b) { return pt(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x); }

//retorna a projecao do ponto b no ponto a
pt project(pt a, pt b) { return b * dot(a, b) / dot(b, b); }

//retorna a projecao do ponto p na reta ab
pt project(pt p, pt a, pt b) { return a + project(p-a, b-a); }

//retorna a projecao do ponto p no plano abc
pt project(pt p, pt a, pt b, pt c) { return p + project(c-p, cross(a-c, b-c)); }

//retorna true se as pontos a, b, c e d sao coplanares
bool coplanar(pt a, pt b, pt c, pt d) { 
	pt p = cross(a-b, c-b);
	pt q = cross(a-b, d-b);
	return cross(p, q) == pt(); 
}

//retorna a area do triangulo abc
double area(pt a, pt b, pt c) { return !cross(b-a, c-a) / 2; }

//retorna true se o ponto p esta acima do plano abc
bool above(pt p, pt a, pt b, pt c) { return cmpD(dot(p-a, cross(b-a, c-a))) > 0; }

//retorna true se os segmentos ab e cd se interseptam
bool seg_seg_intersect(pt a, pt b, pt c, pt d) {
	pt p1 = cross(a-b, c-b);
	pt p2 = cross(a-b, d-b);
	pt p3 = cross(c-d, a-d);
	pt p4 = cross(c-d, b-d);
	if(cmpD(dot(p1, p2)) == 1) return 0;
	if(cmpD(dot(p3, p4)) == 1) return 0;
    return 1;
}

//retorna true se o ponto p pertence ao triangulo T
bool pt_in_tri(pt p, pt T[3]) { 
	double s1 = area(T[0], T[1], T[2]);
	double s2 = area(T[0], T[1], p) + area(T[0], T[2], p) + area(T[1], T[2], p);
	return cmpD(s1, s2) == 0;
}

//retorna true se o segmento pq e o triangulo T tem pelo menos um ponto em comum
bool seg_tri_intersect(pt p, pt q, pt T[3]) {
	if(coplanar(p, T[0], T[1], T[2]) && coplanar(q, T[0], T[1], T[2])) {
		if(pt_in_tri(p, T)) return 1;
		for(int i=0;i<3;i++) if(seg_seg_intersect(p, q, T[i], T[(i+1)%3])) return 1;
		return 0;
	}
	pt n = cross(T[0]-T[1], T[0]-T[2]);
	double d = -1 * dot(n, T[0]);
	double t = -1 * (d + dot(n, p)) / dot(n, q-p);
	if(cmpD(t, 0) >= 0 && cmpD(t, 1) <= 0) return pt_in_tri(p + ((q-p)*t), T);
	return 0;
}

//retorna true se os triangulos T1 e T2 tem pelo menos um ponto em comum
bool tri_tri_intersect(pt T1[3], pt T2[3]) {
	for(int i=0;i<3;i++) if(seg_tri_intersect(T1[i], T1[(i+1)%3], T2)) return 1;
	for(int i=0;i<3;i++) if(seg_tri_intersect(T2[i], T2[(i+1)%3], T1)) return 1;
	return 0;
}

//retorna a distancia entre o ponto p e o segmento ab
double dist_pt_seg(pt p, pt a, pt b) {
    pt pp = project(p, a, b);
    if(cmpD(!(a-pp) + !(pp-b), !(a-b)) == 0) return !(pp - p);
    return min(!(p - a), !(p - b));
}

//retorna a distancia entre os segmentos ab e cd
double dist_seg_seg(pt a, pt b, pt c, pt d) {
    pt e = project(a-d, cross(b-a, d-c));
    if(seg_seg_intersect(a, b, c+e, d+e)) return !e;
    double resp = min(dist_pt_seg(c, a, b), (dist_pt_seg(d, a, b)));
    resp = min(resp, min(dist_pt_seg(a, c, d), dist_pt_seg(b, c, d)));
    return resp;
}

//retorna a distancia entre o ponto p e o triangulo abc
double dist_pt_tri(pt p, pt a, pt b, pt c) {
	pt pp, v1, v2, v3;
    pp = project(p, a, b, c);
    v1 = cross(pp-a, b-a);
    v2 = cross(pp-b, c-b);
    v3 = cross(pp-c, a-c);
    if(cmpD(dot(v1, v2)) >= 0 && cmpD(dot(v1, v3)) >= 0 && cmpD(dot(v2, v3)) >= 0) return !(pp - p);
    return min(dist_pt_seg(p, a, b), min(dist_pt_seg(p, a, c), dist_pt_seg(p, b, c)));
}

//retorna a distancia entre o ponto p e o plano abc
double dist_pt_plane(pt p, pt a, pt b, pt c) { return !(p - project(p, a, b, c)); }

//retorna a distancia entre os tetraedros T1 e T2
double dist_tet_tet(pt T1[4], pt T2[4]) {
    double resp = INF;
    int i, j, ii, jj, k, x;
    for(i=0;i<4;i++) for(j=i+1;j<4;j++) for(ii=0;ii<4;ii++) for(jj=ii+1;jj<4;jj++) resp = min(resp, dist_seg_seg(T1[i], T1[j], T2[ii], T2[jj]));
    for(i=0;i<4;i++) for(j=i+1;j<4;j++) for(k=j+1;k<4;k++) for(x=0;x<4;x++) {
        resp = min(resp, dist_pt_tri(T1[x], T2[i], T2[j], T2[k]));
        resp = min(resp, dist_pt_tri(T2[x], T1[i], T1[j], T1[k]));
    }
    return resp;
}

int main() {
    return 0;
}
