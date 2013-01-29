#include <cstdio>
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
    bool operator >(const pt &p)const { return cmp(p) > 0; }
    bool operator <=(const pt &p)const { return cmp(p) <= 0; }
    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
};

typedef pair<pt, pt> segment;

bool parallel(segment a, segment b) { return cmpD((a.second - a.first) % (b.second - b.first)) == 0; }

//determina o ponto de intersecao entre as retas pq e rs
pt line_intersect(segment s1, segment s2) {
	pt p = s1.first, q = s1.second, r = s2.first, s = s2.second;
    pt a=q-p, b=s-r, c(p%q, r%s);
    if(cmpD(a % b) == 0) return pt(INF, INF);
    return pt(pt(a.x, b.x) % c , pt(a.y, b.y) % c) / (a % b);
}

//true se os segmentos pq e rs tem intersecao, false cc
bool seg_intersect(segment s1, segment s2) {
	pt p = s1.first, q = s1.second, r = s2.first, s = s2.second;
    if(r.between(p, q) || s.between(p, q) || p.between(r, s) || q.between(r, s)) return true;
    pt a = line_intersect(s1, s2);
    return a.between(p, q) && a.between(r, s);
}

vector<segment> v;
vector<pt> T(3);

int main() {
	int t, i, j, k, N, ans;
	while(scanf("%d", &N)!=EOF) {
		v.resize(N);
		ans=0;
		for(i=0;i<N;i++) scanf("%lf%lf%lf%lf", &v[i].first.x, &v[i].first.y, &v[i].second.x, &v[i].second.y);
		for(i=0;i<N;i++) if(v[i].first > v[i].second) swap(v[i].first, v[i].second);
		for(i=0;i<N;i++) for(j=i+1;j<N;j++) if(parallel(v[i], v[j]) && seg_intersect(v[i], v[j])) {
			v[i].first = min(v[i].first, v[j].first);
			v[i].second = max(v[i].second, v[j].second);
			swap(v[j--], v[--N]);
		}
		for(i=0;i<N;i++) for(j=i+1;j<N;j++) for(k=j+1;k<N;k++) {
			if(seg_intersect(v[i], v[j]) && seg_intersect(v[i], v[k]) && seg_intersect(v[j], v[k])) {
				T[0] = line_intersect(v[i], v[j]);
				T[1] = line_intersect(v[i], v[k]);
				T[2] = line_intersect(v[j], v[k]);
				sort(T.begin(), T.end());
				if(!T[1].between(T[0], T[2])) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
