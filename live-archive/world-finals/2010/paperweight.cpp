#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
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
pt project(pt p, pt a, pt b) { return a + project(p-a, b-a); }
pt project(pt p, pt a, pt b, pt c) { return p + project(c-p, cross(a-c, b-c)); }

double area(pt a, pt b, pt c) { return !cross(b-a, c-a) / 2; }

bool pt_in_tri(pt p, pt a, pt b, pt c) {
	double s1 = area(a, b, c);
	double s2 = area(a, b, p) + area(b, c, p) + area(a, c, p);
	return cmpD(s1, s2) == 0;
}

bool coplanar(pt a, pt b, pt c, pt d) {
	pt p = cross(a-b, c-b);
	pt q = cross(a-b, d-b);
	return cross(p, q) == pt(); 
}

bool above(pt p, pt a, pt b, pt c) { return cmpD(dot(p-a, cross(b-a, c-a))) >= 0; }

bool seg_seg_intersect(pt a, pt b, pt c, pt d) {
	pt p1 = cross(a-b, c-b);
	pt p2 = cross(a-b, d-b);
	pt p3 = cross(c-d, a-d);
	pt p4 = cross(c-d, b-d);
	if(cmpD(dot(p1, p2)) == 1) return 0;
	if(cmpD(dot(p3, p4)) == 1) return 0;
    return 1;
}

bool good(pt p, pt a, pt b) {
	double d = !(p - project(p, a, b));
	return cmpD(d, 0.2) > 0;
}

double dist_pt_plane(pt p, pt a, pt b, pt c) { return !(p - project(p, a, b, c)); }

void read(pt &p) { scanf("%lf%lf%lf", &p.x, &p.y, &p.z); }

int main() {
	pt p[6];
	int T=1;
	while(1) {
		scanf("%lf", &p[0].x);
		if(scanf("%lf", &p[0].y) == EOF) break;
		scanf("%lf", &p[0].z);
		for(int i=1;i<6;i++) read(p[i]);
		pt cm1, cm2, cm;
		cm1 = (p[0] + p[1] + p[2] + p[3])/4;
		cm2 = (p[0] + p[1] + p[2] + p[4])/4;
		double vol1 = area(p[0], p[1], p[2]) * dist_pt_plane(p[3], p[0], p[1], p[2]) / 3;
		double vol2 = area(p[0], p[1], p[2]) * dist_pt_plane(p[4], p[0], p[1], p[2]) / 3;
		cm = (cm1 * vol1 + cm2 * vol2) / (vol1 + vol2);
		double dmin=1e9, dmax=-1;
		for(int i=0;i<5;i++) for(int j=i+1;j<5;j++) for(int k=j+1;k<5;k++) {
			vector<pt> v;
			pt cmproj = project(cm, p[i], p[j], p[k]);
			int abo=0, und=0;
			for(int ii=0;ii<5;ii++) {
				if(coplanar(p[ii], p[i], p[j], p[k])) v.push_back(p[ii]);
				else {
					if(above(p[ii], p[i], p[j], p[k])) abo=1;
					else und=1;
				}
			}
			if(abo && und) continue;
			if(v.size() == 4) {
				if(pt_in_tri(v[0], v[1], v[2], v[3])) v.erase(v.begin());
				else if(pt_in_tri(v[1], v[0], v[2], v[3])) v.erase(v.begin()+1);
				else if(pt_in_tri(v[2], v[0], v[1], v[3])) v.erase(v.begin()+2);
				else if(pt_in_tri(v[3], v[0], v[1], v[2])) v.erase(v.begin()+3);
			}
			if(v.size() == 4) {
				int ord[] = {0, 1, 2, 3};
				do {
					pt a = v[ord[0]];
					pt b = v[ord[1]];
					pt c = v[ord[2]];
					pt d = v[ord[3]];
					if(seg_seg_intersect(a, c, b, d)) {
						v[0]=a;
						v[1]=b;
						v[2]=c;
						v[3]=d;
						break;
					}
				} while(next_permutation(ord, ord+4));
				int valid=0;
				if(pt_in_tri(cmproj, v[0], v[1], v[2])) valid=1;
				if(pt_in_tri(cmproj, v[0], v[2], v[3])) valid=1;
				if(!valid) continue;
			}
			else if(!pt_in_tri(cmproj, v[0], v[1], v[2])) continue;
			int valid=1;
			for(int i=0;i<v.size();i++) if(!good(cmproj, v[i], v[(i+1)%v.size()])) valid=0;
			if(!valid) continue;
			double d = dist_pt_plane(p[5], v[0], v[1], v[2]);
			dmin = min(dmin, d);
			dmax = max(dmax, d);
		}
		printf("Case %d: %.5lf %.5lf\n", T++, dmin, dmax);
	}
	return 0;
}
