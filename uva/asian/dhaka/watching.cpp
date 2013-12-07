#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 111111;
int a[N], b[N], vx[N], nx;
vector<int> v[N];

void add(int x, int y) { for(;x<=nx;x+=x&-x) v[x].push_back(y); }
int valid(int x, int y) { for(;x;x-=x&-x) if(v[x].back() >= y) return 1; return 0; }

int main() {
	int T;
	scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		printf("Case %d:\n", t);
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=0;i<n;i++) {
			scanf("%d %d", &a[i], &b[i]);
			vx[i] = a[i];
		}
		sort(vx, vx+n);
		nx = unique(vx, vx+n)-vx;
		for(int i=1;i<=nx;i++) v[i].clear();
		for(int i=0;i<n;i++) add(1+lower_bound(vx, vx+nx, a[i])-vx, b[i]);
		for(int i=1;i<=nx;i++) sort(v[i].begin(), v[i].end());
		while(m--) {
			int x;
			scanf("%d", &x);
			int i=0, f=(int)1e9;
			while(i<f-1) {
				int m = (f+i)/2;
				int px = upper_bound(vx, vx+nx, x-m)-vx;
				if(px==0) f=m;
				else if(valid(px, x+m)) i=m;
				else f=m;
			}
			printf("%d\n", i);
		}
	}
	return 0;
}
