#include <cstdio>
#include <cstring>
	
int tab[10][10];

void disable(int x, int y, int dx, int dy) {
	for(int i=1;i<=8;i++) {
		int nx = x+i*dx;
		int ny = y+i*dy;
		if(nx<0 || nx>8 || ny<0 || ny>8) break;
		if(tab[nx][ny] > 1) {
			tab[nx][ny] = 3;
			break;
		}
		tab[nx][ny] = 1;
	}
}

void mark(char p, int l, int c) {
	if(p=='P') tab[l-1][c+1] = tab[l-1][c-1] = 1;
	if(p=='T') for(int i=-1;i<=1;i+=2) disable(l, c, i, 0), disable(l, c, 0, i);
	if(p=='B') for(int i=-1;i<=1;i+=2) disable(l, c, i, i), disable(l, c, i, -i);
	if(p=='R') for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) if(i || j) disable(l, c, i, j);
	if(p=='W') for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) tab[l+i][c+j] = 1;
}

int valid(int l, int c) {
	for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) if(tab[l+i][c+j] % 2 == 0) return 1;
	return 0;
}

int main() {
	int n, x[11], y[11];
	char p[11], l, c;
	while(scanf("%d", &n) != EOF) {
		memset(tab, 0, sizeof(tab));
		for(int i=0;i<=9;i++) tab[0][i] = tab[9][i] = tab[i][0] = tab[i][9] = 1;
		for(int i=0;i<n;i++) {
			scanf(" %c%c%c", &p[i], &c, &l);
			x[i] = l-'0';
			y[i] = c-'a'+1;
			tab[x[i]][y[i]]=2;
		}
		for(int i=0;i<n;i++) mark(p[i], x[i], y[i]);
		scanf(" %c%c%c", &p[0], &c, &l);
		if(valid(l-'0', c-'a'+1)) printf("NAO\n");
		else printf("SIM\n");
	}
	return 0;
}
