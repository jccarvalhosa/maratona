#include <cstdio>
#include <numeric>
using namespace std;

int t1[111][111], t2[111][111];

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) && n) {
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) { scanf("%d", &t1[i][j]); t2[j][i] = t1[i][j]; }
		int g[4]={1, 1, 1, 1};
		for(int i=0;i<n;i++) {
			if(accumulate(t1[i], t1[i]+m, 0) == m) g[0]=0;
			if(accumulate(t1[i], t1[i]+m, 0) == 0) g[1]=0;
		}
		for(int i=0;i<m;i++) {
			if(accumulate(t2[i], t2[i]+n, 0) == n) g[2]=0;
			if(accumulate(t2[i], t2[i]+n, 0) == 0) g[3]=0;
		}
		printf("%d\n", accumulate(g, g+4, 0));
	}
	return 0;
}
