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

inline double dot(pt a, pt b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
inline pt cross(pt a, pt b) { return pt(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x); }
inline pt project(pt a, pt b) { return b * dot(a, b) / dot(b, b); }

inline bool coplanar(pt a, pt b, pt c, pt d) { return cross(cross(a-b, c-b), cross(a-b, d-b)) == pt(); }

inline double area(pt a, pt b, pt c) { return !cross(b-a, c-a) / 2; }

inline bool seg_intersect(pt a, pt b, pt c, pt d) {
    return cmpD(dot(cross(a-b, c-b), cross(a-b, d-b))) <= 0 && cmpD(dot(cross(c-d, a-d), cross(c-d, b-d))) <= 0;
}

inline bool pt_in_tri(pt p, pt T[3]) { 
	return cmpD(area(T[0], T[1], T[2]), area(T[0], T[1], p) + area(T[0], T[2], p) + area(T[1], T[2], p)) == 0;
}

inline bool seg_in_tri(pt p, pt q, pt T[3]) {
	if(coplanar(p, T[0], T[1], T[2]) && coplanar(q, T[0], T[1], T[2])) {
		for(int i=0;i<3;i++) if(seg_intersect(p, q, T[i], T[(i+1)%3])) return 1;
		return 0;
	}
	pt n = cross(T[0]-T[1], T[0]-T[2]);
	double d = - dot(n, T[0]);
	double t = - (d + dot(n, p)) / dot(n, q-p);
	if(cmpD(t, 0) >= 0 && cmpD(t, 1) <= 0) return pt_in_tri(p + ((q-p)*t), T);
	return 0;
}

inline bool tri_intersect(pt T1[3], pt T2[3]) {
	for(int i=0;i<3;i++) if(seg_in_tri(T1[i], T1[(i+1)%3], T2)) return 1;
	for(int i=0;i<3;i++) if(seg_in_tri(T2[i], T2[(i+1)%3], T1)) return 1;
	return 0;
}

int main() {
    int T, i;
    pt T1[3], T2[3];
    scanf("%d", &T);
    while(T--) {
        for(i=0;i<3;i++) scanf("%lf %lf %lf", &T1[i].x, &T1[i].y, &T1[i].z);
        for(i=0;i<3;i++) scanf("%lf %lf %lf", &T2[i].x, &T2[i].y, &T2[i].z);
		printf("%d\n", tri_intersect(T1, T2));
    }
    return 0;
}
