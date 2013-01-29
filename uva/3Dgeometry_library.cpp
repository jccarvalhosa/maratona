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

double dot(pt a, pt b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
pt cross(pt a, pt b) { return pt(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x); }
pt project(pt a, pt b) { return b * dot(a, b) / dot(b, b); }

bool coplanar(pt a, pt b, pt c, pt d) { return cross(cross(a-b, c-b), cross(a-b, d-b)) == pt(); }

double area(pt a, pt b, pt c) { return !cross(b-a, c-a) / 2; }

bool inter_pt_tri(pt p, pt T[3]) { 
	return cmpD(area(T[0], T[1], T[2]), area(T[0], T[1], p) + area(T[0], T[2], p) + area(T[1], T[2], p)) == 0;
}

bool inter_seg_seg(pt a, pt b, pt c, pt d) {
    return cmpD(dot(cross(a-b, c-b), cross(a-b, d-b))) <= 0 && cmpD(dot(cross(c-d, a-d), cross(c-d, b-d))) <= 0;
}


bool inter_seg_tri(pt p, pt q, pt T[3]) {
	if(coplanar(p, T[0], T[1], T[2]) && coplanar(q, T[0], T[1], T[2])) {
		for(int i=0;i<3;i++) if(inter_seg_seg(p, q, T[i], T[(i+1)%3])) return 1;
		return 0;
	}
	pt n = cross(T[0]-T[1], T[0]-T[2]);
	double d = - dot(n, T[0]);
	double t = - (d + dot(n, p)) / dot(n, q-p);
	if(cmpD(t, 0) >= 0 && cmpD(t, 1) <= 0) return inter_pt_tri(p + ((q-p)*t), T);
	return 0;
}

bool inter_tri_tri(pt T1[3], pt T2[3]) {
	for(int i=0;i<3;i++) if(inter_seg_tri(T1[i], T1[(i+1)%3], T2)) return 1;
	for(int i=0;i<3;i++) if(inter_seg_tri(T2[i], T2[(i+1)%3], T1)) return 1;
	return 0;
}

double dist_pt_seg(pt p, pt a, pt b) {
    pt pp = a + project(p-a, b-a);
    if(cmpD(!(a-pp) + !(pp-b), !(a-b)) == 0) return !(pp - p);
    return min(!(p - a), !(p - b));
}

double dist_seg_seg(pt a, pt b, pt c, pt d) {
    pt e = project(a-d, cross(b-a, d-c));
    if(inter_seg_seg(a, b, c+e, d+e)) return !e;
    double resp = min(dist_pt_seg(c, a, b), (dist_pt_seg(d, a, b)));
    resp = min(resp, min(dist_pt_seg(a, c, d), dist_pt_seg(b, c, d)));
    return resp;
}

double dist_pt_tri(pt p, pt a, pt b, pt c) {
    pt n, pp, v1, v2, v3;
    n = cross(a-c, b-c);
    pp = p + project(c-p, n);
    v1 = cross(pp-a, b-a);
    v2 = cross(pp-b, c-b);
    v3 = cross(pp-c, a-c);
    if(cmpD(dot(v1, v2)) >= 0 && cmpD(dot(v1, v3)) >= 0 && cmpD(dot(v2, v3)) >= 0) return !(pp - p);
    return min(dist_pt_seg(p, a, b), min(dist_pt_seg(p, a, c), dist_pt_seg(p, b, c)));
}

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
