#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

const int D = 1000;
const double INF = 1e9;

int main() {
	freopen("slowdown.in", "r", stdin);
	freopen("slowdown.out", "w", stdout);
	int n, v=1;
	cin>>n;
	double d=0, t=0;
	vector<int> vd, vt;
	while(n--) {
		char c;
		int x;
		cin>>c>>x;
		if(c=='D') vd.push_back(x);
		if(c=='T') vt.push_back(x);
	}
	vd.push_back(D);
	vt.push_back(INF);
	sort(vd.begin(), vd.end());
	sort(vt.begin(), vt.end());
	int nd=0, nt=0;
	while(1) {
		while(nd < vd.size() && vd[nd] <= d) nd++, v++;
		while(nt < vt.size() && vt[nt] <= t) nt++, v++;
		if(nd == vd.size()) break;
		double dt = min(vt[nt] - t, (vd[nd] - d)*v);
		t += dt;
		d += dt/v;
	}
	printf("%.0lf\n", t);
	return 0;
}
