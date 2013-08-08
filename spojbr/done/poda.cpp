#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define sz size()
#define all(x) (x).begin(), (x).end()
#define EPS 1e-9
#define INF 1e9

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

struct pt {
    double x, y;
    pt(double x=0, double y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    double operator *(pt p) { return x*p.x + y*p.y; }
    double operator %(pt p) { return x*p.y - y*p.x; }
    int cmp(pt p) const { 
        int t = cmpD(x, p.x);
        return t ? t : cmpD(y, p.y);
    }
    bool operator <(const pt &p)const { return cmp(p) < 0; }
    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
};
typedef vector<pt> polygon;
pt pivot;

bool radial_lt(pt p, pt q) {
    pt P = p - pivot, Q = q - pivot;
    double R = P % Q;
    if(cmpD(R)) return cmpD(R) > 0;
    return cmpD(P*P, Q*Q) > 0;
}

polygon convex_hull(vector<pt> T) {
    int i, j=0, k, n=T.sz; polygon U(n);
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

double yline(pt a, pt b, double x) { return b.y + (x-b.x)*(a.y-b.y)/(a.x-b.x); }

int main() {
	int N, i;
	double sum=0, ang, h, H;
	scanf("%d", &N);
	polygon p(N);
	for(i=0;i<N;i++) {
		p[i].x=i;
		scanf("%lf", &p[i].y);
	}
	ang = INF;
	for(i=1;i<N;i++) ang = min(ang, p[i].y/p[i].x);
	sum = max(sum, ang*(N-1));
	ang = INF;
	for(i=0;i<N-1;i++) ang = min(ang, p[i].y/(N-1-p[i].x));
	sum = max(sum, ang*(N-1));
	p = convex_hull(p);
	for(i=0;i<p.size();i++) {
		pt a = p[i], b = p[(i+1) % p.sz], c = p[(i+2) % p.sz];
		if(cmpD(yline(a, b, c.x), c.y) <= 0) {
			h = yline(a, b, 0);
			H = yline(a, b, N-1);
			if(cmpD(h) >= 0 && cmpD(H) >= 0) sum = max(sum, h+H);
		}
	}
	printf("%.2lf\n", sum*N/2);
	return 0;
}
