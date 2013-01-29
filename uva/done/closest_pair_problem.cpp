#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#define EPS 1e-9
#define MAX 10000
using namespace std;

struct pt {
	double x, y;
	pt(double x=0, double y=0): x(x), y(y) {} 
    pt operator +(double c) { return pt(x, y+c); }
    pt operator -(double c) { return pt(x, y-c); }
	bool operator <(const pt &p)const { return y < p.y; }
};

bool cmpx(const pt p, const pt q) { return p.x < q.x; }
double abs(pt p, pt q) { return hypot(p.x-q.x, p.y-q.y); }

pt p[10000];
set<pt> s;
set<pt>::iterator itmin, itmax, it;

int main() {
	int N, i, j, start;
	while(scanf("%d", &N) && N) {
		s.clear();
		for(i=0;i<N;i++) scanf("%lf%lf", &p[i].x, &p[i].y);
		if(N == 1) printf("INFINITY\n");
		else {
			sort(p, p+N, cmpx);
			s.insert(p[0]);
			s.insert(p[1]);
			double ans = abs(p[0], p[1]);
			start = 0;
			for(i=2;i<N && ans > EPS;i++) {
				while(p[i].x - p[start].x > ans-EPS) s.erase(p[start++]);
				itmin = s.upper_bound(p[i]-ans);
				itmax = s.upper_bound(p[i]+ans);
				for(it=itmin;it!=itmax;it++) ans = min(ans, abs(p[i], *it));
				s.insert(p[i]);
			}
			if(ans > MAX - EPS) printf("INFINITY\n") ;
			else printf("%.4lf\n", ans);
		}
	}
	return 0;
}
