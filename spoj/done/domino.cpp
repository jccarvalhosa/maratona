#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m[7][8], v[7][8], conv[7][7], vis;

int pos(int a, int b) {
	if(a>b) swap(a, b);
	return conv[a][b];
}

int dfs(int a, int b) {
	if(a == 7) return 1;
	if(b == 8) return dfs(a+1, 0);
	if(v[a][b]) return dfs(a, b+1);
	int n, ret=0;
	if(b != 7 && v[a][b+1] == 0) {
		n = pos(m[a][b], m[a][b+1]);
		if((vis & (1<<n)) == 0) {
			vis += (1<<n);
			v[a][b] = v[a][b+1] = 1;
			ret += dfs(a, b+1);
			v[a][b] = v[a][b+1] = 0;
			vis -= (1<<n);
		}
	}
	if(a != 6 && v[a+1][b] == 0) {
		n = pos(m[a][b], m[a+1][b]);
		if((vis & (1<<n)) == 0) {
			vis += (1<<n);
			v[a][b] = v[a+1][b] = 1;
			ret += dfs(a, b+1);
			vis -= (1<<n);
			v[a][b] = v[a+1][b] = 0;
		}
	}
	return ret;
}

int main() {
	int T, t, i, j;
	scanf("%d", &T);
	t=0;
	i=j=0;
	while(i != 7) {
		conv[i][j] = ++t;
		if(++j == 7) j = ++i;
	}
	for(t=1;t<=T;t++) {
		printf("Teste %d\n", t);
		for(i=0;i<7;i++) for(j=0;j<8;j++) scanf("%d", &m[i][j]);
		vis = 0;
		memset(v, 0, sizeof(v));
		printf("%d\n\n", dfs(0, 0));
	}
	return 0;
}
