#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#define INF 1e9
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

bool coplanar(pt a, pt b, pt c, pt d) { 
	pt p = cross(a-b, c-b);
	pt q = cross(a-b, d-b);
	return cross(p, q) == pt(); 
}

double area(pt a, pt b, pt c) { return !cross(b-a, c-a) / 2; }

bool seg_seg_intersect(pt a, pt b, pt c, pt d) {
	pt p1 = cross(a-b, c-b);
	pt p2 = cross(a-b, d-b);
	pt p3 = cross(c-d, a-d);
	pt p4 = cross(c-d, b-d);
	if(cmpD(dot(p1, p2)) == 1) return 0;
	if(cmpD(dot(p3, p4)) == 1) return 0;
    return 1;
}

bool pt_in_tri(pt p, pt T[3]) { 
	double s1 = area(T[0], T[1], T[2]);
	double s2 = area(T[0], T[1], p) + area(T[0], T[2], p) + area(T[1], T[2], p);
	return cmpD(s1, s2) == 0;
}

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

int main() {
	pt p, t[4];
	while(scanf("%lf %lf %lf", &t[0].x, &t[0].y, &t[0].z) != EOF) {
		for(int i=1;i<4;i++) scanf("%lf %lf %lf", &t[i].x, &t[i].y, &t[i].z);
		scanf("%lf %lf %lf", &p.x, &p.y, &p.z);
		for(int i=0;i<4;i++) {
			int valid=1;
			pt g = (t[(i+1)%4]+t[(i+2)%4]+t[(i+3)%4])/3;
			for(int j=0;j<4;j++) for(int k=j+1;k<4;k++) if(j != i && k != i) {
				pt f[3] = {t[i], t[j], t[k]};
				if(seg_tri_intersect(p, g, f)) valid=0;
			}
			printf("%c", valid?'S':'N');
		}
		printf("\n");
	}
    return 0;
}
