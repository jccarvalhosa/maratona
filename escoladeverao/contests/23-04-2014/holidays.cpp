#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int a[555555][3];
ll INF=(ll)1e18;

ll mod(ll a) { return a>0 ? a : -a; }

int main() {
	int i, j, k, n, d=3, p[11];
	ll s, dist;
	scanf("%d", &n);
	for(i=0; i<(1<<d); i++) p[i]=-INF;
	for(i=0; i<n; i++) for(j=0; j<d; j++) scanf("%d", &a[i][j]);
	for(i=0; i<(1<<d); i++) {
		dist=-INF;
		for(k=0; k<n; k++) {
			s=0;
			for(j=0; j<d; j++) {
				if(i&(1<<j)) s+=a[k][j];
				else s-=a[k][j];
			}
			if(s>dist) {
				dist=s;
				p[i]=k;
			}
		}
	}
	for(j=0; j<n; j++) {
		dist=-INF;
		for(i=0; i<(1<<d); i++) dist=max(dist, mod(a[j][0]-a[p[i]][0])+mod(a[j][1]-a[p[i]][1])+mod(a[j][2]-a[p[i]][2]));
		printf("%lld\n", dist);
	}
	return 0;
}
