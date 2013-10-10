#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define M 1555
#define INF 1<<30

int w, h;
string tab[M];
int color[M][M], vis[M][M], s1[M][M], s2[M][M], sb[M][M];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};

void paint(int col) {
	int r=0, c=0, d=0;
	color[r][c] |= col;
	while (r < h - 1 || c < w - 1) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr >= 0 && nr < h && nc >= 0 && nc < w && tab[nr][nc] == '.') {
			color[r=nr][c=nc] |= col;
			d = (d + 1) % 4;
		} else {
			d = (d + 3) % 4;
		}
	}
}

int count(int ri, int ci, int rf, int cf, int s[M][M]) { return s[rf+1][cf+1] - s[rf+1][ci] - s[ri][cf+1] + s[ri][ci]; }
int valid(int r, int c, int l) { return count(r-l, c-l, r, c, sb)==0; }
int block(int r, int c, int l) { return count(r-l, c-l, r, c, s1) && count(r-l, c-l, r, c, s2); }

int main() {
	while(cin>>w>>h && !cin.eof()) {
		for(int i=0;i<h;i++) cin>>tab[i];
		for(int i=0;i<h;i++) for(int j=0;j<w;j++) color[i][j]=0;
		for(int c=1;c<=2;c++) {
			paint(c);
			for(int i=0;i<2;i++) {
				swap(dr[i], dr[3-i]);
				swap(dc[i], dc[3-i]);
			}
		}

		tab[0][0] = tab[h-1][w-1] = '#';
		for(int i=1;i<=h;i++) {
			int n1=0, n2=0, nb=0;
			for(int j=1;j<=w;j++) {
				if(tab[i-1][j-1]=='#') nb++;
				if(color[i-1][j-1] & 1) n1++;
				if(color[i-1][j-1] & 2) n2++;
				sb[i][j] = nb + (i==0 ? 0 : sb[i-1][j]);
				s1[i][j] = n1 + (i==0 ? 0 : s1[i-1][j]);
				s2[i][j] = n2 + (i==0 ? 0 : s2[i-1][j]);
			}
		}

		int ans=INF, ansr=0, ansc=0;
		for(int r=0;r<h;r++) for(int c=0;c<w;c++) {
			if(tab[r][c]=='#' || ans==1) continue;
			if(block(r, c, 0)) {
				ans = 1;
				ansr = r+1;
				ansc = c+1;
				continue;
			}
			int maxv, i=0, f=min(r, c);
			if(valid(r, c, f)) maxv=f;
			else {
				while(i<f-1) {
					int m=(i+f)/2;
					if(valid(r, c, m)) i=m;
					else f=m;
				}
				maxv=i;
			}
			i=0, f=maxv;
			if(!block(r, c, f)) continue;
			while(i<f-1) {
				int m=(i+f)/2;
				if(block(r, c, m)) f=m;
				else i=m;
			}
			if(ans > f+1) {
				ans=f+1;
				ansr=r-f+1;
				ansc=c-f+1;
			}
		}

		//for(int i=0;i<h;i++) { for(int j=0;j<w;j++) if(tab[i][j]=='#') cout<<"# "; else cout<<color[i][j]<<" "; cout<<endl; } cout<<endl;
		if(ans==INF) cout<<"Impossible"<<endl;
		else cout<<ans<<" "<<ansc<<" "<<ansr<<endl;
	}
	return 0;
}
