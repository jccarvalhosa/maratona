#include <cstdio>

int main() {
	int n, h, w, m[10][10], c[10];
	while(scanf("%d%d%d", &h, &w, &n) != EOF) {
		for(int i=0;i<n;i++) scanf("%d", &c[i]);
		int x=0;
		for(int j=0;j<w;j++) for(int i=h-1;i>=0;i--) {
			while(!c[x]) x++;
			m[i][j] = x+1;
			c[x]--;
		}
		for(int i=0;i<h;i++) { for(int j=0;j<w;j++) printf("%d", m[i][j]); printf("\n");}
	}
	return 0;
}
