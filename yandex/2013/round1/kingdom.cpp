#include <iostream>
#include <cstdio>
using namespace std;

char tab[1111][1111];
int n, m;

int color(int& xx, int& yy, int sum, char c) {
	int x, y;
	x=xx, y=yy;
	for(int i=0;i<sum;i++) {
		tab[x][y]=0;
		if(x&1) {
			y--;
			if(y < 0) {
				y = 0;
				x++;
			}
		}
		else {
			y++;
			if(y >= m) {
				y = m-1;
				x++;
			}
		}
	}
	x=xx, y=yy;
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	for(int i=0;i<sum;i++) {
		for(int j=0;j<4;j++) {
			int xx = x+dx[j];
			int yy = y+dy[j];
			if(xx>=0 && xx<n && yy>=0 && yy<m && tab[xx][yy]==c) return 0;
		}
		if(x&1) {
			y--;
			if(y < 0) {
				y = 0;
				x++;
			}
		}
		else {
			y++;
			if(y >= m) {
				y = m-1;
				x++;
			}
		}
	}
	x=xx, y=yy;
	for(int i=0;i<sum;i++) {
		tab[x][y]=c;
		if(x&1) {
			y--;
			if(y < 0) {
				y = 0;
				x++;
			}
		}
		else {
			y++;
			if(y >= m) {
				y = m-1;
				x++;
			}
		}
	}
	xx=x, yy=y;
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	int t = n*m;
	int k;
	for(k=1;;k++) if((1+k)*k/2 > t) { k--; break; }
	int sum=0;
	int q=1;
	int x=0, y=0;
	for(int i=1;i<=k;i++) {
		int d=i;
		if(i==k) d = t - k*(k-1)/2;
		for(char c='A';c<='Z';c++) if(color(x, y, d, c)) break;
	}
	printf("%d\n", k);
	for(int i=0;i<n;i++) { for(int j=0;j<m;j++) printf("%c", tab[i][j]); printf("\n"); }
	return 0;
}
