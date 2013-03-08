#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAXD 10000001
#define MAXN 2000000

int id[MAXD], d[2][MAXN];
vector<int> v[MAXN+1];

int query(int x, int y) {
	int ans=0;
	for(; x ; x -= x&-x) ans += upper_bound(v[x].begin(), v[x].end(), y) - v[x].begin();
	return ans;
}

void add(int x, int y) {
	for( ; x <= MAXN; x += x&-x) v[x].push_back(y);
}

int main() {
	int n, q, i, j, a, b, c;
	double xc[2], yc[2], zc[2], xp, yp, zp;
	scanf("%d", &n);
	for(i=0;i<2;i++) scanf("%lf%lf%lf", &xc[i], &yc[i], &zc[i]);
	n-=2;
	for(i=0;i<n;i++) {
		scanf("%lf%lf%lf", &xp, &yp, &zp);
		for(j=0;j<2;j++) d[j][i] = ceil(sqrt((xp-xc[j])*(xp-xc[j]) + (yp-yc[j])*(yp-yc[j]) + (zp-zc[j])*(zp-zc[j])));
	}
	for(i=0;i<n;i++) add(d[0][i], d[1][i]);
	for(i=1;i<=MAXN;i++) sort(v[i].begin(), v[i].end());
	sort(d[0], d[0]+n);
	sort(d[1], d[1]+n);
	stringstream ss;
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d", &i, &j);
		i = min(i, MAXN);
		j = min(j, MAXN);
		a = upper_bound(d[0], d[0]+n, i) - d[0];
		b = upper_bound(d[1], d[1]+n, j) - d[1];
		c = query(i, j);
		ss << a+b-c << '\n';
	}
	cout << ss.str();
	return 0;
}
