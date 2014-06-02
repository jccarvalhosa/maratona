#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pt;
#define x first
#define y second

struct rect {
	pt p1, p2;
	rect(){}
	rect(pt p1, pt p2): p1(p1), p2(p2) { if(p1 > p2) swap(p1, p2); }
};

int dist(rect a, rect b) {
	int dx=0, dy=0;
	if(a.p1.x > b.p2.x) dx = a.p1.x - b.p2.x-1;
	if(b.p1.x > a.p2.x) dx = b.p1.x - a.p2.x-1;
	if(a.p1.y > b.p2.y) dy = a.p1.y - b.p2.y-1;
	if(b.p1.y > a.p2.y) dy = b.p1.y - a.p2.y-1;
	return max(dx, dy);
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int w, h, b;
		cin>>w>>h>>b;
		vector<rect> vr;
		vr.push_back(rect(pt(-1, 0), pt(-1, h-1)));
		vr.push_back(rect(pt(w, 0), pt(w, h-1)));
		for(int i=0;i<b;i++) {
			pt p1, p2;
			cin>>p1.x>>p1.y>>p2.x>>p2.y;
			vr.push_back(rect(p1, p2));
		}
		priority_queue<pt> q;
		vector<int> d(vr.size(), 1e9);
		d[0]=0;
		q.push(pt(0, 0));
		while(!q.empty()) {
			pt p = q.top();
			q.pop();
			int v = p.second;
			if(d[v] != -p.first) continue;
			for(int u=0;u<vr.size();u++) {
				int dd = dist(vr[v], vr[u]);
				if(d[u] > d[v] + dd) {
					d[u] = d[v] + dd;
					q.push(pt(-d[u], u));
				}
			}
		}
		printf("Case #%d: %d\n", t, d[1]);
	}
	return 0;
}
