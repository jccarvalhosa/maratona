#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<double, double> pt;
typedef vector<pt>  vp;

const double PI=acos(-1);

const int N=1e4+1;
int n;
vp blocked[N], ok[N];

vp inverse(vp v) {
	vp u;
	int sz = v.size();
	if(sz==0) {
		u.push_back(pt(0, 2*PI));
	}
	else {
		if(v[0].first > 0) {
			u.push_back(pt(0, v[0].first));
		}
		for(int i=1;i<sz;i++) {
			if(v[i].first > v[i-1].second) {
				u.push_back(pt(v[i-1].second, v[i].first));
			}
		}
		if(v[sz-1].second < 2*PI) {
			u.push_back(pt(v[sz-1].second, 2*PI));
		}
	}
	return u;
}

vp extend(vp v, double p) {
	int sz = v.size();
	if(sz==0) return v;
	vp u;
	double start = max(0.0, v[0].first-p);
	if(v[sz-1].second+p >= 2*PI) {
		double end = v[sz-1].second+p-2*PI;
		if(end < start) {
			u.push_back(pt(0, end));
		}
		else start=0;
	}
	u.push_back(pt(start, min(2*PI, v[0].second+p)));
	for(int i=1;i<sz;i++) {
		if(v[i].first-p > u.back().second) {
			u.push_back(pt(v[i].first-p, min(2*PI, v[i].second+p)));
		}
		u.back().second = max(u.back().second, min(2*PI, v[i].second+p));
	}
	double end = v[0].first-p;
	if(end < 0) {
		end = 2*PI + end;
		if(end > u.back().second) u.push_back(pt(end, 2*PI));
		else u.back().second=2*PI;
	}
	return u;
}

vp inter(vp a, vp b) {
	vp v;
	int i=0, j=0;
	while(i != a.size() && j != b.size()) {
		double s = max(b[j].first, a[i].first);
		double e = min(b[j].second, a[i].second);
		if(s<=e) v.push_back(pt(s, e));
		if(j+1 != b.size() && b[j+1].first < a[i].second) j++;
		else i++;
	}
	return v;
}

int valid(double p) {
	vector<pt> v;
	v.push_back(pt(0, 2*PI));
	for(int i=0;i<n;i++) {
		v = inter(extend(v, 2*PI*p), ok[i]);
		if(v.size()==0) return 0;	
	}
	return 1;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		for(int i=0;i<n;i++) {
			blocked[i].clear();
			int k;
			scanf("%d", &k);
			while(k--) {
				double a, b;
				scanf("%lf%lf", &a, &b);
				if(a < b) blocked[i].push_back(pt(a, b));
				else {
					blocked[i].push_back(pt(0, b));
					blocked[i].push_back(pt(a, 2*PI));
				}
			}
			sort(blocked[i].begin(), blocked[i].end());
			ok[i] = inverse(blocked[i]);
		}
		double i=0, f=1;
		for(int k=0;k<50;k++) {
			double m = (i+f)/2;
			if(valid(m)) f=m;
			else i=m;
		}
		printf("Case #%d: %.4lf\n", t, f);
	}
	return 0;
}
