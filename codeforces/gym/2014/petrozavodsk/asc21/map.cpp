#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstdio>
using namespace std;

vector<int> par;
int findPar(int x) { return par[par[x]] == par[x] ? par[x] : par[x] = findPar(par[x]); }

void split(string &s, string &p, string delim) {
	int pos = s.find(delim);
	p = s.substr(0, pos);
	s = s.substr(pos+1);
}

vector<int> concat(vector<int> a, vector<int> b) {
	b.insert(b.begin(), a.begin(), a.end());
	return b;
}

int diff(vector<int>&v, set<int>&vis) {
	int ret=0;
	for(int i=0;i<v.size();i++) if(v[i] && !vis.count(v[i])) {
		vis.insert(v[i]);
		ret++;
	}
	return ret;
}

void merge(vector<int>&a, vector<int>&b) {
	for(int i=0;i<a.size();i++) if(a[i] && b[i]) par[findPar(a[i])] = findPar(b[i]);
}

struct Pattern {
	vector<int> u, r, d, l;
	long long comp, inner;

	Pattern() {}
	Pattern(int x) {
		comp=x;
		inner=0;
		u.push_back(x);
		r.push_back(x);
		d.push_back(x);
		l.push_back(x);
	}

	void add(int delta) {
		for(int i=0;i<u.size();i++) if(u[i]) u[i] += delta;
		for(int i=0;i<r.size();i++) if(r[i]) r[i] += delta;
		for(int i=0;i<d.size();i++) if(d[i]) d[i] += delta;
		for(int i=0;i<l.size();i++) if(l[i]) l[i] += delta;
	}

	void merge() {
		for(int i=0;i<u.size();i++) if(u[i]) u[i] = findPar(u[i]);
		for(int i=0;i<r.size();i++) if(r[i]) r[i] = findPar(r[i]);
		for(int i=0;i<d.size();i++) if(d[i]) d[i] = findPar(d[i]);
		for(int i=0;i<l.size();i++) if(l[i]) l[i] = findPar(l[i]);
	}
	
	void normalize() {
		vector<int> v(1, 0);
		v.insert(v.begin(), u.begin(), u.end());
		v.insert(v.begin(), r.begin(), r.end());
		v.insert(v.begin(), d.begin(), d.end());
		v.insert(v.begin(), l.begin(), l.end());
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i=0;i<u.size();i++) u[i] = lower_bound(v.begin(), v.end(), u[i]) - v.begin();
		for(int i=0;i<r.size();i++) r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
		for(int i=0;i<d.size();i++) d[i] = lower_bound(v.begin(), v.end(), d[i]) - v.begin();
		for(int i=0;i<l.size();i++) l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
		comp = v.size() - 1;
	}
};

map<string, Pattern> id;

int main() {
	freopen("map.in", "r", stdin);
	freopen("map.out", "w", stdout);
	id["0"] = Pattern(0);
	id["1"] = Pattern(1);
	string s, p, a, b, c, d;
	while(1) {
		cin>>s;
		split(s, p, "=");
		split(s, a, ",");
		split(s, b, ",");
		split(s, c, ",");
		d = s;

		Pattern A = id[a], B = id[b], C = id[c], D = id[d];
		B.add(A.comp);
		C.add(A.comp+B.comp);
		D.add(A.comp+B.comp+C.comp);
		
		Pattern P;
		P.inner = A.inner + B.inner + C.inner + D.inner;

		P.u = concat(A.u, B.u);
		P.r = concat(B.r, D.r);
		P.d = concat(C.d, D.d);
		P.l = concat(A.l, C.l);
		
		par.resize(A.comp+B.comp+C.comp+D.comp+1);
		for(int i=0;i<par.size();i++) par[i]=i;
		
		merge(A.r, B.l);
		merge(A.d, C.u);
		merge(B.d, D.u);
		merge(C.r, D.l);
		if(P.l[0]) par[findPar(P.l[0])] = findPar(P.u[0]);
		if(P.r[0]) par[findPar(P.r[0])] = findPar(P.u.back());
		if(P.l.back()) par[findPar(P.l.back())] = findPar(P.d[0]);
		if(P.r.back()) par[findPar(P.r.back())] = findPar(P.d.back());
		P.merge();
		A.merge();
		B.merge();
		C.merge();
		D.merge();
		
		set<int> vis;
		vis.insert(P.u.begin(), P.u.end());
		vis.insert(P.r.begin(), P.r.end());
		vis.insert(P.d.begin(), P.d.end());
		vis.insert(P.l.begin(), P.l.end());

		P.inner += diff(A.r, vis);
		P.inner += diff(A.d, vis);

		P.inner += diff(B.l, vis);
		P.inner += diff(B.d, vis);
		
		P.inner += diff(C.r, vis);
		P.inner += diff(C.u, vis);
		
		P.inner += diff(D.l, vis);
		P.inner += diff(D.u, vis);
		
		P.normalize();

		if(p=="Map") {
			cout << P.comp + P.inner << endl;
			return 0;
		}
		id[p]=P;
	}
}
