#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;

const int N=1e5+1;
const int S=100001;
int n, xmin[N], xmax[N], ymin[N], ymax[N];
pii ordmin[N], ordmax[N];
double xc, yc;
int bestd;

map<int, int> best[2*S];

int query(int x, int yi, int yf) {
	if(x <= 0) return 0;
	for(;x;x-=x&-x) {
		if(best[x].empty()) continue;
		map<int, int>::iterator it = best[x].upper_bound(yi);
		if(it != best[x].begin() && (*--it).second >= yf) return 1;
	}
	return 0;
}

void add(int x, int yi, int yf) {
	for(;x<2*S;x+=x&-x) {
		map<int, int>::iterator it = best[x].lower_bound(yi);
		while(it != best[x].end() && (*it).second < yf) best[x].erase(it++);
		if(it != best[x].end() && (*it).first == yi) return;
		if(it != best[x].begin() && (*--it).second >= yf) return;
		best[x][yi] = yf;
	}
}

void solve() {
	for(int i=0;i<n;i++) {
		int pos = ordmin[i].second;
		int dmax=2*S-1;
		while(bestd < dmax-1) {
			int d = (bestd+dmax)/2;
			int xi = xmin[pos];
			int xf = xi+d;
			int yi = ymin[pos];
			int yf = yi+d;
			if(yf <= ymax[pos] && xf <= xmax[pos] && query(2*S-xf, yi, yf)) {
				xc = (xi+xf)/2.0;
				yc = (yi+yf)/2.0;
				bestd=d;
				continue;
			}
			yf = ymax[pos];
			yi = yf-d;
			if(yi >= ymin[pos] && xf <= xmax[pos] && query(2*S-xf, yi, yf)) {
				xc = (xi+xf)/2.0;
				yc = (yi+yf)/2.0;
				bestd=d;
				continue;
			}
			dmax=d;
		}
		add(2*S-xmax[pos], ymin[pos], ymax[pos]);
	}
	for(int i=1;i<2*S;i++) best[i].clear();
	for(int i=0;i<n;i++) {
		int pos = ordmax[i].second;
		int dmax=2*S-1;
		while(bestd < dmax-1) {
			int d = (bestd+dmax)/2;
			int xf = xmax[pos];
			int xi = xf-d;
			int yi = ymin[pos];
			int yf = yi+d;
			if(xi >= xmin[pos] && yf <= ymax[pos] && query(xi, yi, yf)) {
				xc = (xi+xf)/2.0;
				yc = (yi+yf)/2.0;
				bestd=d;
				continue;
			}
			yf = ymax[pos];
			yi = yf-d;
			if(xi >= xmin[pos] && yi >= ymin[pos] && query(xi, yi, yf)) {
				xc = (xi+xf)/2.0;
				yc = (yi+yf)/2.0;
				bestd=d;
				continue;
			}
			dmax=d;
		}
		add(xmin[pos], ymin[pos], ymax[pos]);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=0;i<n;i++) {
		scanf("%d%d%d%d", &xmin[i], &ymin[i], &xmax[i], &ymax[i]);
		xmin[i] += S;
		ymin[i] += S;
		xmax[i] += S;
		ymax[i] += S;
		ordmin[i] = pii(xmin[i], i);
		ordmax[i] = pii(xmax[i], i);
	}
	sort(ordmin, ordmin+n);
	sort(ordmax, ordmax+n);
	reverse(ordmax, ordmax+n);
	solve();
	if(!bestd) {
		cout << "Impossible" << endl;
		return 0;
	}
	printf("%.1lf %.1lf %.1lf\n", xc-S, yc-S, bestd/2.0);
	return 0;
}
