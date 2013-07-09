#include <cstdio>

int c[2][100002], right[2][100002], left[2][100002], total[2];

inline int min(int a, int b) { return a<b?a:b;}

inline void remove(int i, int j) {
	total[i]--;
	left[i][right[i][j]] = left[i][j];
	right[i][left[i][j]] = right[i][j];
}

int main() {
	int n, m, i, j, x, v, a, b;
	scanf("%d%d", &n, &m);
	for(i=0;i<2;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &x);
			c[i][x+1]++;
		}
		for(j=0;j<=m+1;j++) {
			right[i][j]=j+1;
			left[i][j]=j-1;
		}
		total[i]=m;
		for(j=1;j<=m;j++) if(!c[i][j]) remove(i, j);
	}
	for(i=m+1;i>=2;i--) {
		x = total[0]<total[1]?0:1;
		for(a=left[x][m+1];a!=-1;a=left[x][a]) {
			if(a + left[1-x][m+1] < i) break;
			b = i-a;
			if(b>m) b -= m;
			if(b<1) b += m;
			v = min(c[x][a], c[1-x][b]);
			if(v) {
				c[x][a] -= v;
				c[1-x][b] -= v;
				if(!c[x][a]) remove(x, a);
				if(!c[1-x][b]) remove(1-x, b);
				while(v--) printf("%d ", i-2);
			}
		}
	}
	printf("\n");
	return 0;
}
