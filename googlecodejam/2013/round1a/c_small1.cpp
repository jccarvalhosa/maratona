#include <cstdio>
#include <iostream>
using namespace std;

int x[64][3], valid[64];

int test(int i, int p) {
	if(p == 1) return 1;
	if(x[i][0] == p || x[i][1] == p || x[i][2] == p) return 1;
	if(x[i][0] * x[i][1] == p) return 1;
	if(x[i][0] * x[i][2] == p) return 1;
	if(x[i][1] * x[i][2] == p) return 1;
	if(x[i][0] * x[i][1] * x[i][2] == p) return 1;
	return 0;
}

int main() {
	int T, i, j, jj, r, n, m, k, c, p;
	cin>>T;
	printf("Case #1:\n");
	cin>>r>>n>>m>>k;
	c=0;
	for(i=2;i<=5;i++) for(j=2;j<=5;j++) for(jj=2;jj<=5;jj++) {
		x[c][0] = i;
		x[c][1] = j;
		x[c][2] = jj;
		c++;
	}
	while(r--) {
		for(i=0;i<64;i++) valid[i] = 1;
		for(i=0;i<k;i++) {
			cin>>p;
			for(j=0;j<64;j++) if(test(j, p) == 0) valid[j] = 0;
		}
		for(i=0;i<64;i++) if(valid[i]) break;
		printf("%d%d%d\n", x[i][0], x[i][1], x[i][2]);
	}
	return 0;
}
