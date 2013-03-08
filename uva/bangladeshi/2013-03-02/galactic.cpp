#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAXD 10000001
#define MAXN 500001

int id[MAXD], d[2][MAXN], N;
vector<int> v[MAXN];

int query(int x, int y) {
	int ans=0;
	for(; x ; x -= x&-x) ans += upper_bound(v[x].begin(), v[x].end(), y) - v[x].begin();
	return ans;
}

void add(int x, int y) {
	for( ; x <= N; x += x&-x) v[x].push_back(y);
}

int main() {
	int n, q, i, j, a, b, c;
	double xc[2], yc[2], zc[2], xp, yp, zp;
	scanf("%d", &n);
	for(i=0;i<2;i++) scanf("%lf%lf%lf", &xc[i], &yc[i], &zc[i]);
	n-=2;
	memset(id, 0, sizeof(id));
	for(i=0;i<n;i++) {
		scanf("%lf%lf%lf", &xp, &yp, &zp);
		for(j=0;j<2;j++) d[j][i] = ceil(sqrt((xp-xc[j])*(xp-xc[j]) + (yp-yc[j])*(yp-yc[j]) + (zp-zc[j])*(zp-zc[j])));
		id[d[0][i]]++;
	}
	id[0]=1;
	for(i=1;i<MAXD;i++) id[i] += id[i-1];
	N = id[MAXD-1];
	for(i=0;i<n;i++) add(id[d[0][i]], d[1][i]);
	for(i=1;i<=N;i++) sort(v[i].begin(), v[i].end());
	sort(d[0], d[0]+n);
	sort(d[1], d[1]+n);
	stringstream ss;
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d", &i, &j);
		a = upper_bound(d[0], d[0]+n, i) - d[0];
		b = upper_bound(d[1], d[1]+n, j) - d[1];
		c = query(id[i], j);
		ss << a+b-c << '\n';
	}
	cout << ss.str();
	return 0;
}
