#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char t[12][12];
char s[1111];
int tab[12][12];

void disable(int x, int y, int dx, int dy) {
	for(int i=1;i<=12;i++) {
		int nx = x+i*dx;
		int ny = y+i*dy;
		if(nx<0||nx>12||ny<0||ny>12) break;
		tab[nx][ny] |= 1;
		if(tab[nx][ny]&2) break;
	}
}

int cx[8]={1,1,-1,-1,2,2,-2,-2};
int cy[8]={2,-2,2,-2,1,-1,1,-1};

void mark(char p, int l, int c) {
	if(p=='P') for(int i=-1;i<=1;i+=2) tab[l-1][c+i] |= 1;
	if(p=='p') for(int i=-1;i<=1;i+=2) tab[l+1][c+i] |= 1;
	if(p=='R'||p=='r') for(int i=-1;i<=1;i+=2) disable(l,c,i,0), disable(l,c,0,i);
	if(p=='B'||p=='b') for(int i=-1;i<=1;i+=2) disable(l,c,i,i), disable(l,c,i,-i);
	if(p=='Q'||p=='q') for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) if(i||j) disable(l,c,i,j);
	if(p=='K'||p=='k') for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) if(i||j) tab[l+i][c+j] |= 1;
	if(p=='N'||p=='n') for(int i=0;i<8;i++) tab[l+cx[i]][c+cy[i]] |= 1;
}

int main()
{
	while(scanf("%s", s) != EOF)
	{
		memset(tab,0,sizeof(tab));
		int l = strlen(s);
		int px, py;
		px = py = 0;
		for(int i=0;i<12;i++) for(int j=0;j<12;j++) t[i][j] = 'X';
		for(int i=0;i<l;i++)
		{
			if(s[i] >= '0' && s[i] <= '9') px += (s[i]-'0');
			else if(s[i] == '/') py++, px=0;
			else 
			{
				t[py+2][px+2] = s[i];
				tab[py+2][px+2] = 2;
				px++;
			}
		}
		for(int i=2;i<10;i++)
		{
			for(int j=2;j<10;j++)
			{
				if(t[i][j] != 'X') mark(t[i][j],i,j);
			}
		}
		int r=0;
		for(int i=2;i<10;i++) for(int j=2;j<10;j++) if(tab[i][j] == 0) r++;
		cout << r << endl;
	}
	return 0;
}
