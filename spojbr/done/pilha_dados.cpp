#include <cstdio>
#include <algorithm>
using namespace std;

int d[10000][6];

int oposto(int x, int n) {
	int i;
	for(i=0;i<6;i++) if(d[n][i] == x) break;
	switch(i) {
		case 0: return d[n][5];
		case 5: return d[n][0];
		case 1: return d[n][3];
		case 3: return d[n][1];
		case 4: return d[n][2];
		case 2: return d[n][4];
	}
}

int main() {
	int n, b, t, i, j, k, sum, ans;
	scanf("%d", &n);
	for(i=0;i<n;i++) for(j=0;j<6;j++) scanf("%d", &d[i][j]);
	ans = 0;
	for(i=1;i<=6;i++) {
		t = i;
		sum = 0;
		for(j=0;j<n;j++) {
			b = t;
			t = oposto(b, j);
			for(k=6;k>0;k--) if(b != k && t != k) break;
			sum += k;
		}
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
}
