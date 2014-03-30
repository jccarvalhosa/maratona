#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef double db;

const int N=1e4;

int cmpD(db x, db y=0, db tol=1e-6) { return (x <= y+tol) ? (x+tol<y) ? -1 : 0 : 1; }

struct pt {
	db x, y;
	pt(db x=0, db y=0): x(x), y(y) {}
	int cmp(pt p) const {
		int t = cmpD(x, p.x);
		return t ? t : cmpD(y, p.y);
	}
	pt operator -(pt p) { return pt(x-p.x, y-p.y); }
	db operator %(pt p) { return x*p.y - y*p.x; }
	db operator *(pt p) { return x*p.x + y*p.y; }
	bool operator <(const pt &p) const { return cmp(p) < 0; }
	bool operator <=(const pt &p) const { return cmp(p) <= 0; }

	int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
};

db val[N], dp[N];
pt p[11];

db abs(pt a, pt b) { return hypot(a.x-b.x, a.y-b.y); }

pt pivot;

bool radial_lt(pt p, pt q) {
	pt P = p-pivot, Q=q-pivot;
	db R = P % Q;
	if(cmpD(R)) return cmpD(R) > 0;
	return cmpD(P*P, Q*Q) > 0;
}

vector<pt> convex_hull(vector<pt> T) {
	int i, j=0, k, n=T.size();
	vector<pt> u(n);
	pivot = *min_element(T.begin(), T.end());
	sort(T.begin(), T.end(), radial_lt);
	for(k=n-2;k>=0 && T[0].prod(T[k], T[n-1]) == 0; k--);
	reverse(T.begin()+k+1, T.end());
	for(i=0;i<n;i++) {
		while(j>1 && T[i].prod(u[j-1], u[j-2]) <= 0) j--;
		u[j++] = T[i];
	}
	u.erase(u.begin()+j, u.end());
	return u;
}

int T=1, n, m;

int valid(int a, int b) {
	for(int i=0;i<n;i++) if((a & (1<<i)) == 0) {
		if(b & (1<<i)) return 0;
	}
	return 1;
}

int main() {
	while(cin>>n>>m && n) {
		for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
		for(int i=1;i<1<<n;i++) {
			val[i] = 2*M_PI*m;
			vector<pt> v;
			for(int j=0;j<n;j++) if((1<<j) & i) v.push_back(p[j]);
			v = convex_hull(v);
			if(v.size() == 1) continue;
			for(int j=0;j<v.size();j++) {
				val[i] += abs(v[j], v[(j+1)%v.size()]);
			}
		}
		for(int i=1;i<1<<n;i++) {
			dp[i] = 1e9;
			for(int j=1;j<=i;j++) if(valid(i, j)) dp[i] = min(dp[i], val[j] + dp[i-j]);
		}
		printf("Case %d: length = %.2lf\n", T++, dp[(1<<n)-1]);
	}
	return 0;
}
