#include <cstdio>
#include <algorithm>
using namespace std;

int N, G[200][200], p[200];

int ord(char c, int flag) {
	int i, j, x, m, ret=0;
	for(i=0;i<N;i++) {
		x=i, m=p[i];
		for(j=i+1;j<N;j++) if(p[j] < m) x=j, m=p[j];
		if(x != i) {
			ret++;
			swap(p[i], p[x]);
			if(flag) printf("%c %d %d\n", c, i+1, x+1); 
		}
	}
	return ret;
}

int main() {
	int L, C, i, j, sol=0;
	scanf("%d%d", &L, &C);
	for(i=0;i<L;i++) for(j=0;j<C;j++) scanf("%d", &G[i][j]);
	for(i=0;i<2;i++) {
		for(j=0;j<L;j++) p[j] = G[j][0];
		N=L, sol += ord('L', i);
		for(j=0;j<C;j++) p[j] = G[0][j];
		N=C, sol += ord('C', i);
		if(!i) printf("%d\n", sol);
	}
	return 0;
}
