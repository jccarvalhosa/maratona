#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#define EPS 1e-9
#define INF 1e9

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
	bool operator ==(pt p) { return cmp(p) == 0; }
	bool operator !=(pt p) { return cmp(p) != 0; }
	bool operator <(const pt &p)const { return cmp(p) < 0; }
	bool operator >(const pt &p)const { return cmp(p) > 0; }
};

double abs(pt p, pt q) { return hypot(p.x-q.x, p.y-q.y); }

int ccw(pt p, pt q, pt r) { return cmpD((q-p) % (r-p)); }

pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

bool between(pt p, pt q, pt r) { return ccw(p, q, r) == 0 && cmpD((p-q) * (r-q)) <= 0; }

pt line_intersect(pt p, pt q, pt r, pt s) {
	pt a = q-p, b = s-r;
	pt c(p%q, r%s);
	if(cmpD(a % b) == 0) return pt(INF, INF);
	return pt(pt(a.x, b.x) % c, pt(a.y, b.y) % c) / (a % b);
}

bool seg_intersect(pt p, pt q, pt r, pt s) {
	pt a = line_intersect(p, q, r, s);
	return between(p, a, q) && between(r, a, s);
}

double dist_pt_seg(pt p, pt a, pt b) {
	pt pp = a + project(p-a, b-a);
	if(between(a, pp, b)) return abs(p, pp);
	return min(abs(p, a), abs(p, b));
}

double dist_seg_seg(pt p, pt q, pt r, pt s) { 
	if(seg_intersect(p, q, r, s)) return 0;
	return min(min(dist_pt_seg(p ,r, s), dist_pt_seg(q, r, s)), min(dist_pt_seg(r, p, q), dist_pt_seg(s, p, q)));
}

int N;
vector<pair<int, double> > grafo[1000];

double prim(int s) {
	int i, u, v, aux, vis[1000], pi[1000];
    double d[1000], resp;
	priority_queue<pair<double, int> > q;
    for(i=0;i<N;i++) {
        vis[i]=0;
        d[i]=INF;
    }
	d[s]=0;
	q.push(make_pair(-d[s], s));
	while(!q.empty()) {
		u=q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(i=0;i<grafo[u].size();i++) {
			v=grafo[u][i].first;
			if(!vis[v] && cmpD(grafo[u][i].second, d[v]) < 0) {
				d[v]=grafo[u][i].second;
				pi[v]=u;
				q.push(make_pair(-d[v], v));
			}
		}
	}
    resp=0;
    for(aux=1; aux!=0; aux=pi[aux]) resp=max(resp, d[aux]);
    return resp;
}

int main()
{
	double x, y, l, d;
	int i, j;
	pt wall[1000][2];
	while(scanf("%d", &N) && N) {
		for(i=0;i<N;i++) {
			scanf("%lf%lf%lf", &x, &y, &l);
			grafo[i].clear();
		    wall[i][0] = pt(x, y);
			if(cmpD(l) >= 0) wall[i][1] = pt(x+l, y);
			else wall[i][1] = pt(x, y-l);
		}
		for(i=0;i<N;i++) for(j=i+1;j<N;j++) {
			d = dist_seg_seg(wall[i][0], wall[i][1], wall[j][0], wall[j][1]);
			grafo[i].push_back(make_pair(j, d));
			grafo[j].push_back(make_pair(i, d));
		}
		printf("%.2lf\n", prim(0));
	}
	return 0;
}
