#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#define EPS 1e-9
#define MAX 50000
using namespace std;

struct pt {
	double x, y;
	int ind;
	pt(double x=0, double y=0, int ind=0): x(x), y(y), ind(ind) {} 
    pt operator +(double c) { return pt(x, y+c); }
    pt operator -(double c) { return pt(x, y-c); }
	bool operator <(const pt &p)const { return y < p.y; }
};

bool cmpx(const pt p, const pt q) { return p.x < q.x; }
double abs(pt p, pt q) { return hypot(p.x-q.x, p.y-q.y); }

pt p[MAX];
int a, b;
set<pt> s;
set<pt>::iterator itmin, itmax, it;

int main() {
	int N, i, j, start;
	scanf("%d", &N); 
	s.clear();
	for(i=0;i<N;i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		p[i].ind = i;
	}
	sort(p, p+N, cmpx);
	a = p[0].ind;
	b = p[1].ind;
	s.insert(p[0]);
	s.insert(p[1]);
	double ans = abs(p[0], p[1]);
	start = 0;
	for(i=2;i<N && ans > EPS;i++) {
		while(p[i].x - p[start].x > ans-EPS) s.erase(p[start++]);
		itmin = s.upper_bound(p[i]-ans);
		itmax = s.upper_bound(p[i]+ans);
		for(it=itmin;it!=itmax;it++) {
			double aux = abs(p[i], *it);
			if(ans > aux) {
				ans = aux;
				a = p[i].ind;
				b = it->ind;
			}
		}
		s.insert(p[i]);
	}
	printf("%d %d %lf\n", min(a, b), max(a, b), ans);
	return 0;
}
