#include <algorithm>
#include <cstdio>
using namespace std;

int mod(int x){return x>0?x:-x;}

int main() {
	int xx, yy;
	while(scanf("%d%d", &xx, &yy) && xx) {
		int ord[] = {0, 1, 2};
		int ans=1e9;
		int px[3], py[3];
		char d[3];
		for(int i=0;i<3;i++) scanf("%d%d %c ", &px[i], &py[i], &d[i]);
		do {
			int t=0, add=0, x=xx, y=yy;
			for(int ii=0;ii<3;ii++) {
				int i = ord[ii];
				int dt;
				for(dt=1;;dt++) {
					int dx = mod(px[i] + (d[i]=='D' ? t+dt : 0) - x);
					int dy = mod(py[i] + (d[i]=='C' ? t+dt : 0) - y);
					if(2*dt >= dx+dy) break;
				}
				t += dt;
				x = px[i] + (d[i]=='D' ? t : 0);
				y = py[i] + (d[i]=='C' ? t : 0);
			}
			ans = min(ans, t);
		} while(next_permutation(ord, ord+3));
		printf("%d\n", ans);
	}
	return 0;
}
