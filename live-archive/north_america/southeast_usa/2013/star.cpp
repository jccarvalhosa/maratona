#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N=1e5+10;
pii px[N], py[N], pz[N];
int x[N], y[N], z[N];

long long dist(int i, int j) {
	return 1ll * (x[i]-x[j]) * (x[i]-x[j]) + 1ll * (y[i]-y[j]) * (y[i]-y[j]) + 1ll * (z[i]-z[j]) * (z[i]-z[j]);
}

int main() {
	int n, k;
	while(cin>>n>>k && n) {
		for(int i=0;i<n;i++) {
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
			px[i] = pii(x[i], i);
			py[i] = pii(y[i], i);
			pz[i] = pii(z[i], i);
		}
		sort(px, px+n);
		sort(py, py+n);
		sort(pz, pz+n);
		int ans=0;
		for(int i=0;i<n;i++) {
			int ix = lower_bound(px, px+n, pii(x[i]-k+1, 0)) - px;
			int fx = upper_bound(px, px+n, pii(x[i]+k-1, n)) - px;
			int dx = fx-ix;

			int iy = lower_bound(py, py+n, pii(y[i]-k+1, 0)) - py;
			int fy = upper_bound(py, py+n, pii(y[i]+k-1, n)) - py;
			int dy = fy-iy;

			int iz = lower_bound(pz, pz+n, pii(z[i]-k+1, 0)) - pz;
			int fz = upper_bound(pz, pz+n, pii(z[i]+k-1, n)) - pz;
			int dz = fz-iz;

			if(dx <= dy && dx <= dz) {
				for(int j=ix;j<fx;j++) {
					int pos = px[j].second;
					if(pos != i && dist(i, pos) < 1ll*k*k) ans++;
				}
			}
			else if(dy <= dx && dy <= dz) {
				for(int j=iy;j<fy;j++) {
					int pos = py[j].second;
					if(pos != i && dist(i, pos) < 1ll*k*k) ans++;
				}
			}
			else {
				for(int j=iz;j<fz;j++) {
					int pos = pz[j].second;
					if(pos != i && dist(i, pos) < 1ll*k*k) ans++;
				}
			}
		}
		cout << (ans/2) << endl;
	}
	return 0;
}
