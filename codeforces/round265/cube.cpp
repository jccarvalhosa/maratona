#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int v[8][3];
long long dist[7];

int test() {
	for(int i=0;i<8;i++) {
		int pos = 0;
		long long m = 1e18;
		for(int j=0;j<8;j++) if(i != j) {
			dist[pos] = 
				1ll * (v[i][0] - v[j][0]) * (v[i][0] - v[j][0])
				+ 1ll * (v[i][1] - v[j][1]) * (v[i][1] - v[j][1])
				+ 1ll * (v[i][2] - v[j][2]) * (v[i][2] - v[j][2]);

			m = min(m, dist[pos++]);
		}
		if(m == 0) return 0;
		int c1=0, c2=0, c3=0;
		for(int j=0;j<7;j++) {
			if(dist[j] == m) {
				if(++c1 > 3) return 0;
			}
			else if(dist[j] == 2*m) {
				if(++c2 > 3) return 0;
			}
			else if(dist[j] == 3*m) {
				if(++c3 > 1) return 0;
			}
			else return 0;
		}
	}
	return 1;
}

int go(int x) {
	if(x == 8) return test();
	int pos[] = {0, 1, 2};
	int aux[] = {v[x][0], v[x][1], v[x][2]};
	do
	{
		v[x][0] = aux[pos[0]];
		v[x][1] = aux[pos[1]];
		v[x][2] = aux[pos[2]];
		if(go(x+1)) return 1;
	} while(next_permutation(pos, pos+3));
	return 0;
}

int main() {
	for(int i=0;i<8;i++) for(int j=0;j<3;j++) scanf("%d", &v[i][j]);
	if(go(0)) {
		printf("YES\n");
		for(int i=0;i<8;i++) { for(int j=0;j<3;j++) printf("%d ", v[i][j]);	printf("\n"); }
	}
	else {
		printf("NO\n");
	}
	return 0;
}
