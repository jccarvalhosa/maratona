#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, z;
struct node {
	int x, y, h;

	node(int h=0, int x=0, int y=0) : h(h), x(x), y(y) {}

	node brother() {
		if(x%2) return node(h, x-1, y-2);
		return node(h, x+1, y-2);
	}

	node up(int i) { return node(h-i, x/(1<<i), y-i); }

	vector<node> walk() {
		vector<node> ans;
		node aux = *this;
		ans.push_back(aux);
		while(aux.h != 0 && aux.y != 0) {
			aux = aux.up(1);
			ans.push_back(aux);
		}
		return ans;
	}

	node next() {
		if(y < 2) return up(y);
		return brother();
	}

	int valid() { return y>=0 && h>=0 && h+y <= n-1; }
};

node lca(node a, node b) {
	if(a.h < b.h) b = b.up(b.h - a.h);
	else if(b.h < a.h) a = a.up(a.h - b.h);
	if(a.x == b.x) return a;
	int i=0, f=a.h;
	while(i<f-1) {
		int m = (i+f)/2;
		node A = a.up(m);
		node B = b.up(m);
		if(A.x == B.x) f=m;
		else i=m;
	}
	return a.up(f);
}

int check(node a, node b) {
	a = a.next();
	b = b.next();
	if(!a.valid()) return 0;
	if(!b.valid()) return 0;
	node l = lca(a, b);
	int dist = a.h + a.y + b.h + b.y - 2*l.h;
	return dist > z;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int xa, ya, xb, yb;
		cin>>n>>xa>>ya>>xb>>yb>>z;
		xa--; xb--;
		node a(n-1, xa, ya);
		vector<node> va = a.walk();
		node b(n-1, xb, yb);
		vector<node> vb = b.walk();
		int valid=0;
		for(int i=0;i<va.size();i++) for(int j=0;j<vb.size();j++) if(check(va[i], vb[j])) valid=1;
		if(valid) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
