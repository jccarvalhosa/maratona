#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#define EPS 1e-9
#define INF 1e18
#define all(x) (x).begin(), (x).end()
using namespace std;

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
    bool operator <(const pt &p)const { return cmp(p) < 0; }
    bool operator <=(const pt &p)const { return cmp(p) <= 0; }
    
    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
};

pt pivot;

typedef vector<pt> polygon;

pt rotate(pt a, double teta, pt o=pt()) {
	a = a - o;
	pt cis(cos(teta), sin(teta));
	return o + pt(a.x*cis.x - a.y*cis.y, a.x*cis.y + a.y*cis.x);
}

bool radial_lt(pt p, pt q) {
    pt P = p - pivot, Q = q - pivot;
    double R = P % Q;
    if(cmpD(R)) return cmpD(R) > 0;
    return cmpD(P*P, Q*Q) > 0;
}

polygon convex_hull(vector<pt> T) {
    int i, j=0, k, n=T.size(); polygon U(n);
    pivot = *min_element(all(T));
    sort(all(T), radial_lt);
    for(k=n-2; k>=0 && T[0].prod(T[k], T[n-1]) == 0; k--) ;
    reverse((k+1) + all(T));
    for(i=0;i<n;i++) {
        while(j>1 && T[i].prod(U[j-1], U[j-2]) <= 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + all(U));
    return U;
}

double poly_area(polygon T) {
    double s=0; 
	int i, n=T.size();
    for(i=0;i<n;i++) s += T[i] % T[(i+1)%n];
    return s/2;
}

double yline(pt a, pt b, double x) { 
	if(cmpD(x, b.x)==0) return b.y;
	return b.y + (x-b.x)*(a.y-b.y)/(a.x-b.x);
}

double xline(pt a, pt b, double y) { 
	if(cmpD(y, b.y)==0) return b.x;
	return b.x + (y-b.y)*(a.x-b.x)/(a.y-b.y);
}

polygon A(4), B(4), inter;

int main() {
	double h, w, teta, x, y;
	int i, j;
	scanf("%lf %lf %lf", &w, &h, &teta);
	if(cmpD(teta) == 0 || cmpD(teta, 180) == 0) {
		printf("%.9lf\n", w*h);
		return 0;
	}
	teta = teta *acos(0) / 90;
	A[0] = pt(-w/2, -h/2);
	A[1] = pt(w/2, -h/2);
	A[2] = pt(w/2, h/2);
	A[3] = pt(-w/2, h/2);
	for(i=0;i<4;i++) B[i] = rotate(A[i], teta);
	for(i=0;i<4;i++) for(j=0;j<4;j++) {
		if(i % 2 == 0) {
			x = xline(B[j], B[(j+1)%4], A[i].y);
			if(cmpD(x, min(A[i].x, A[(i+1)%4].x)) < 0) continue;
			if(cmpD(x, max(A[i].x, A[(i+1)%4].x)) > 0) continue;
			inter.push_back(pt(x, A[i].y));
		}
		else {
			y = yline(B[j], B[(j+1)%4], A[i].x);
			if(cmpD(y, min(A[i].y, A[(i+1)%4].y)) < 0) continue;
			if(cmpD(y, max(A[i].y, A[(i+1)%4].y)) > 0) continue;
			inter.push_back(pt(A[i].x, y));
		}
	}
	printf("%.9lf\n", poly_area(convex_hull(inter)));	
	return 0;
}
