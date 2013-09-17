#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
#define M 1000000

struct pt { 
	int x, y; 
	pt(int x=0, int y=0): x(x), y(y) {}
};
struct seg { pt p1, p2; };
int cmp(const seg &a, const seg &b) { return a.p2.y < b.p2.y; }

int n, c, q[111111];
seg s[111111];
pt v[1111111];
stack<int> p;
set<int> vis;

void go(int pos) {
	seg sp = s[pos];
	int xmin = min(sp.p1.x, sp.p2.x);
	int xmax = max(sp.p1.x, sp.p2.x);
	int sz=p.size();
	set<int>::iterator it = vis.lower_bound(xmin);
	while(it != vis.end() && *it <= xmax) {
		p.push(*it);
		vis.erase(it++);
	}
	if(sp.p1.y != sp.p2.y) vis.insert(sp.p2.x);
	if(pos != n-1) go(pos+1);
	while(p.size() > sz) {
		int k = p.top();
		p.pop();
		if(sp.p1.y == sp.p2.y) v[k] = pt(k, sp.p2.y);
		else v[k] = v[sp.p2.x];
	}
}

int main() {
	while(scanf("%d %d", &n, &c) != EOF) {
		for(int i=0;i<n;i++) {
			cin>>s[i].p1.x>>s[i].p1.y>>s[i].p2.x>>s[i].p2.y;
			if(s[i].p2.y < s[i].p1.y) swap(s[i].p1, s[i].p2);
		}
		sort(s, s+n, cmp);
		s[n].p1 = pt(0, M+1);
		s[n].p2 = pt(M, M+1);
		n++;
		vis.clear();
		for(int i=0;i<c;i++) {
			cin>>q[i];
			vis.insert(q[i]);
		}
		go(0);
		for(int i=0;i<c;i++) {
			pt p = v[q[i]];
			cout<<p.x;
			if(p.y != M+1) cout<<" "<<p.y<<endl;
			else cout<<endl;
		}
	}
	return 0;
}
